#ifndef FUNCTIONS_H
#define FUNCTIONS_H
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

std::string current_dir();

std::string get_string(std::string prompt);

std::string get_operation(std::string s);

void handle(std::string operation, std::string whole);

#endif //FUNCTIONS_H