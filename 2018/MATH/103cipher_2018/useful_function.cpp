/*
** EPITECH PROJECT, 2018
** useful_function
** File description:
** useful function
*/

#include "cipher.hpp"

int help(int argc, char **argv)
{
    if (argc == 2 && std::string(argv[1]).compare("-h") == 0) {
        std::cout << "USAGE\n    ./103cipher message key flag\n\n"
        << "DESCRIPTION\n    message    a message, made of ASCII"
        << " characters\n    key        the encryption key, "
        << "made of ASCII characters\n    flag       "
        << "0 for the message to be encrypted, 1 to be decrypted"
        << std::endl;
    }
    return (84);
}

int str_cmp(char const *s1, char const *s2)
{
    return (std::string(s1).compare(s2) == 0);
}