#!/usr/local/bin/lua
args = {...}

if #args < 1 then
    print("USAGE: asm <filename>")
    os.exit()
end

local filename = ""
local line = 0
local funcs = {}

function funcs.jmp(code)
    if code == nil then error("[ASM ERROR] "..filename..":"..line..": missing address JMP <ADDRESS>") end
    return "goto "..code
end

function funcs.je(code)
    if code == nil then error("[ASM ERROR] "..filename..":"..line..": missing address JE <ADRESS>") end
    return "if flag.cmp == 0 then\n\t goto "..code.."\n end"
end

function funcs.jne(code)
    if code == nil then error("[ASM ERROR] "..filename..":"..line..": missing address JNE <ADDRESS>") end
    return "if flag.cmp ~= 0 then\n\t goto "..code.."\n end"
end

function funcs.jl(code)
    if code == nil then error("[ASM ERROR] "..filename..":"..line..": missing address JL <ADDRESS>") end
    return "if flag.cmp == -1 then\n\t goto "..code.."\n end"
end

function funcs.jle(code)
    if code == nil then error("[ASM ERROR] "..filename..":"..line..": missing address JLE <ADDRESS>") end
    return "if flag.cmpe == -1 then\n\t goto "..code.."\n end"
end

function funcs.jg(code)
    if code == nil then error("[ASM ERROR] "..filename..":"..line..": missing address JG <ADDRESS>") end
    return "if flag.cmpe == 1 then\n\t goto "..code.."\n end"
end

function funcs.jge(code)
    if code == nil then error("[ASM ERROR] "..filename..":"..line..": missing address JGE <ADDRESS>") end
    return "if flag.cmpe == 1 then\n\t goto "..code.."\n end"
end

function funcs.add(i, j)
    if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address ADD <ADDRESS SRC> <ADDRESS DEST>") end
    return i.."="..i.."+"..j
end

function funcs.sub(i, j)
    if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address SUB <ADDRESS SRC> <ADDRESS DEST>") end
    return i.."="..i.."-"..j
end

function funcs.neg(i)
    if i == nil then error("[ASM ERROR] "..filename..":"..line..": missing address NEG <ADDRESS SRC>") end
    return i.."= -"..i
end

function funcs.inc(i)
    if i == nil then error("[ASM ERROR] "..filename..":"..line..": missing address INC <ADDRESS SRC>") end
    return i.."="..i.."+ 1"
end

function funcs.dec(i, j)
    if i == nil then error("[ASM ERROR] "..filename..":"..line..": missing address DEC <ADDRESS SRC>") end
    return i.."="..i.."- 1"
end

function funcs.imul(i, j, k)
    if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address ADD <ADDRESS SRC> <ADDRESS DEST>") end
    if i and j and not k then
        return i.."="..i.."*"..j
    else
        return i.."="..j.."*"..k
    end
end

funcs["and"] = function(i, j)
    if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address AND <ADDRESS SRC> <ADDRESS DEST>") end
    return i.." = "..i.." & "..j
end

funcs["or"] = function(i, j)
    if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address OR <ADDRESS SRC> <ADDRESS DEST>") end
    return i.." = "..i.." | "..j
end

function funcs.xor(i, j)
if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address XOR <ADDRESS SRC> <ADDRESS DEST>") end
    return i.." = "..i.." ~ "..j
end

funcs["not"] = function(i)
    if i == nil then error("[ASM ERROR] "..filename..":"..line..": missing address NOT <ADDRESS SRC> <ADDRESS DEST>") end
    return i.."= ~"..i
end

function funcs.shl(i, j)
    if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address SHL <ADDRESS SRC> <ADDRESS DEST>") end
    return i.."="..i.."<<"..j
end

function funcs.shr(i, j)
if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address SHR <ADDRESS SRC> <ADDRESS DEST>") end
return i.."="..i..">>"..j
end

function funcs.cmp(i, j)
    if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address CMP <ADDRESS1> <ADDRESS2>") end
    return "if "..i.."=="..j.." then\n\tflag.cmp = 0\nelseif "..i.."<"..j.." then\n\tflag.cmp = -1\nelse\n\tflag.cmp = 1\nend\nif "..i.."<="..j.." then\n\tflag.cmpe=-1\nelseif "..i..">="..j.." then\n\tflag.cmpe=1\nelse\n\tflag.cmpe=0\nend"
end

function funcs.mov(i, j)
    if i == nil or j == nil then error("[ASM ERROR] "..filename..":"..line..": missing address MOV <ADDRESS1> <VALUE>") end
    return i.."="..j
end

function funcs.push(i)
    if i == nil then error("[ASM ERROR] "..filename..":"..line..": missing value push <VALUE>") end
    return "stack[#stack + 1] = "..i
end

function funcs.pop()
    return "stack[#stack]\nstack[#stack] = nil"
end

function funcs.puts(...)
    return "print("..table.concat( {...}, ", ")..")"
end

local h = io.open(args[1], "r")
if h then
    filename = args[1]
    local asmcode = ""
    local ldata = h:read()
    while ldata do
        line = line + 1
        local data = {}
        for v in ldata:gmatch("[^ ]+") do
            data[#data + 1] = v
        end
        local find = false
        for k, v in pairs(funcs) do
            if k == data[1]:lower() then
                find = true
                break
            end
        end
        if find then
            asmcode = asmcode..funcs[data[1]:lower()](table.unpack(data, 2)).."\n"
        else
            if data[1]:match("^::[^:]+::$") then
                asmcode = asmcode..data[1].."\n"
            else
                error("[ASM ERROR] "..filename..":"..line..": Unknown instruction "..data[1]:upper())
            end
        end
        ldata = h:read()
    end
    asmcode = "local flag={cmp=0}\n"..asmcode
    asmcode = "local stack={}\n"..asmcode
    local env = setmetatable({}, {__index=_G})
    local f, e = load(asmcode, "asm", "t", env)
    if f then
        local hh = io.open(filename..".out","w")
        hh:write(string.dump(f))
        hh:close()
        print("[ASM] Output "..filename..".out")
    else
        error(e)
    end
    h:close()
else
    print("[Error] File not found")
    os.exit()
end