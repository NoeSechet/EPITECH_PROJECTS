args = {...}

local txt = ""
local index = 1
local bytes = {}

function readInt()
    local val = string.unpack(">i4", 
    string.char(bytes[index], bytes[index + 1],
    bytes[index + 2], bytes[index + 3]))
    index = index + 4
    return val
end

function readShort()
    local val = string.unpack(">i2", 
    string.char(bytes[index], bytes[index + 1]))
    index = index + 2
    return val
end

function readByte()
    local val = bytes[index]
    index = index + 1
    return val
end

function readHeader()
    local magic = readInt()
    local name = ""
    for i=1, 129 do
        if bytes[index] > 0 then
            name = name..string.char(bytes[index])
        end
        index = index + 1
    end
    index = index + 3
    local progsize = readInt()
    local comment = ""
    for i=1, 2049 do
        if bytes[index] > 0 then
            comment = comment..string.char(bytes[index])
        end
        index = index + 1
    end
    return ".name \""..name.."\"\n.comment \""..comment.."\"\n\n"
end

function readCodingByte(short)
    local cbyte = readByte()
    local data = {}
    
    for i=0, 3 do
        local p = (cbyte >> ((3 - i) * 2)) & 0x3
        if p == 1 then
            data[#data + 1] = "r"..readByte()
        elseif p == 2 then
            if short then
                data[#data + 1] = "%"..readShort()
            else
                data[#data + 1] = "%"..readInt()
            end
        elseif p == 3 then
            data[#data + 1] = readShort()
        end
    end
    return table.concat(data, ", ")
end

local funcs = {
    [1] = function()
        return "live %"..readInt()
    end,
    [2] = function()
        return "ld "..readCodingByte()
    end,
    [3] = function()
        return "st "..readCodingByte()
    end,
    [4] = function()
        return "add "..readCodingByte()
    end,
    [5] = function()
        return "sub "..readCodingByte()
    end,
    [6] = function()
        return "and "..readCodingByte()
    end,
    [7] = function()
        return "or "..readCodingByte()
    end,
    [8] = function()
        return "xor "..readCodingByte()
    end,
    [9] = function()
        return "zjmp %"..readShort()
    end,
    [10] = function()
        return "ldi "..readCodingByte(true)
    end,
    [11] = function()
        return "sti "..readCodingByte(true)
    end,
    [12] = function()
        return "fork %"..readShort()
    end,
    [13] = function()
        return "lld "..readCodingByte()
    end,
    [14] = function()
        return "lldi "..readCodingByte(true)
    end,
    [15] = function()
        return "lfork %"..readShort()
    end,
    [16] = function()
        return "aff r"..readByte()
    end,
}


if #args > 0 then
    local handle = io.open(args[1])
    if handle then
        local inp = handle:read("*all")
        for i=1, #inp do
            bytes[i] = inp:sub(i,i):byte()
        end
        txt = readHeader()
        while index < #bytes do
            local code = readByte()
            if funcs[code] then
                txt = txt..funcs[code]().."\n"
            end
        end
        print(txt)
        handle:close()
    else
        print("File not found '"..args[1].."'")
    end
else
    print("Usage decompiler <file>")
end