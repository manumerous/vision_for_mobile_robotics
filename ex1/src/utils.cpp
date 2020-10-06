#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>

#pragma once

std::string get_base_directory()
{
    long size;
    char *buf;
    char *ptr;
    ptr = getcwd(buf, (size_t)size);
    std::string str = std::string(ptr);

    if (str.substr(str.size() - 6, 6) == "/build")
    {
        str = str.substr(0, str.size() - 6);
    }

    // std::cout << str.substr(str.size() - 6);
    if (str.empty())
        return "";
    else
        return str;
}