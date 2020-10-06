#include <stdlib.h>
#include <unistd.h>
#include <string>
#include <iostream>

#pragma once

std::string getBaseDirectory()
{
    long size;
    char *buf;
    char *ptr;
    ptr = getcwd(buf, (size_t)size);
    std::string cwd_str = std::string(ptr);

    // remove the build folder from path if needed
    if (cwd_str.substr(cwd_str.size() - 6, 6) == "/build")
        cwd_str = cwd_str.substr(0, cwd_str.size() - 6);

    if (cwd_str.empty())
        return "";
    else
        return cwd_str;
}

// does not work when both functions in this file are used...
std::string getCPP_Version()
{
    std::string version;
    if (__cplusplus == 201703L)
        version = "C++17";
    else if (__cplusplus == 201402L)
        version = "C++14";
    else if (__cplusplus == 201103L)
        version = "C++11";
    else if (__cplusplus == 199711L)
        version = "C++98";
    else
        version = "pre-standard C++";

    if (version.empty())
        return "";
    else
        return "version";
}