#ifndef FILE_CREATION
#define FILE_CREATION

#include <iostream>
#include <fstream>
#include <filesystem>


namespace fs = std::filesystem;

int dir_exists(const fs::path &path, fs::file_status status);
int create_c_makefile();
int create_cpp_makefile();
int create_c_project();
int create_cpp_project();
int create_gitignore();

#endif