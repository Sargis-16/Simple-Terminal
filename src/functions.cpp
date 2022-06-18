#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Shlwapi.h>
#pragma comment(lib, "shlwapi.lib")
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <filesystem>
#include <direct.h>
#include <stdlib.h>
#include <fstream>

std::string read_from_file(const char *file_name)
{
    std::fstream file;
    file.open(file_name, std::ios::in);
    std::string result = "";
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            result.append(line).append("\n");
        }
    }
    else
    {
        std::cout << "ERROR: something worng with the file " << file_name << std::endl;
    }
    return result;
}

std::string current_dir()
{
    char path[MAX_PATH] = "";
    GetCurrentDirectoryA(MAX_PATH, path);
    return path;
}

std::string get_string(std::string prompt)
{
    std::cout << prompt;
    std::string s;
    std::getline(std::cin, s);
    return s;
}

std::string get_operation(std::string s)
{
    const char *separator = " ";
    std::vector<std::string> vals;
    std::string buff = "";
    char *token = strtok(const_cast<char *>(s.c_str()), separator);
    while (token != NULL)
    {
        vals.insert(vals.end(), token);
        token = strtok(NULL, separator);
    }
    return vals[0];
}

void handle(std::string operation, std::string whole)
{
    std::string rest;
    if (operation == "echo")
    {
        if (whole.size() <= operation.size() + 1)
        {
            std::cout << "ERROR: No arguments given to \'" << operation << "\'" << std::endl;
            return;
        }
        rest = whole.substr(operation.size() + 1, whole.size());
        std::cout << rest << std::endl;
    }
    else if (operation == "clear" || operation == "cls")
    {
        system("CLS");
    }
    else if (operation == "mkdir")
    {
        if (whole.size() <= operation.size() + 1)
        {
            std::cout << "ERROR: No arguments given to \'" << operation << "\'" << std::endl;
            return;
        }
        rest = whole.substr(operation.size() + 1, whole.size());
        _mkdir((current_dir().append("\\").append(rest)).c_str());
        std::cout << "The directory " << rest << " is created." << std::endl;
    }
    else if (operation == "exit")
    {
        exit(0);
    }
    else if (operation == "rmdir")
    {
        if (whole.size() <= operation.size() + 1)
        {
            std::cout << "ERROR: No arguments given to \'" << operation << "\'" << std::endl;
            return;
        }
        rest = whole.substr(operation.size() + 1, whole.size());
        std::string command = "rmdir /s /q " + rest;
        system(command.c_str());
        std::cout << "The directory " << rest << " is deleted." << std::endl;
    }
    else if (operation == "secret")
    {
        std::cout << "You entered a secret code. Congrats, you are now in cool guys group!" << std::endl;
    }
    else if (operation == "cd")
    {
        if (whole.size() <= operation.size() + 1)
        {
            std::cout << "ERROR: No arguments given to \'" << operation << "\'" << std::endl;
            return;
        }
        rest = whole.substr(operation.size() + 1, whole.size());
        chdir(rest.c_str());
    }
    else if (operation == "ls" || operation == "dir")
    {
        std::string command = "dir";
        system(command.c_str());
    }
    else if (operation == "cat")
    {
        if (whole.size() <= operation.size() + 1)
        {
            std::cout << "ERROR: No arguments given to \'" << operation << "\'" << std::endl;
            return;
        }
        rest = whole.substr(operation.size() + 1, whole.size());
        std::string result = read_from_file(rest.c_str());
        std::cout << result << std::endl;
    }
    else
    {
        std::cout << "ERROR: \'" << operation << "\'"
                  << " is not a command!" << std::endl;
    }
}
