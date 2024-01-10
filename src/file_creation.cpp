#include "../headers/file_creation.h"

enum errors	{
	FILE_START_ERROR = -1,
	SUCCESS = 0,
	FAILURE = 1
};

int dir_exists(const fs::path &path, fs::file_status status = fs::file_status{}) {
    if (fs::status_known(status) ? fs::exists(status) : fs::exists(path)) return FAILURE;
    else return SUCCESS;
};

int create_c_makefile() {
    std::ofstream makefile("makefile");
	if (!makefile) 
		return FAILURE;
	std::string makefile_code = "CC = gcc \n\ndefault: main.o\n\t${CC} main.o -o main\n\nmain.o: main.c\n\t${CC} main.c -c\n\nclean:\n\tdel *.o *.exe";
	makefile << makefile_code;
	makefile.close();
	return SUCCESS;
}

int create_cpp_makefile() {
	std::ofstream makefile("makefile");
	if (!makefile) 
		return FAILURE;
	std::string makefile_code = "CC = g++\n\ndefault: main.o\n\t${CC} main.o -o main\n\nmain.o: main.cpp\n\t${CC} main.cpp -c\n\nclean:\n\tdel *.o *.exe";
	makefile << makefile_code;
	makefile.close();
	return SUCCESS;
}

int create_c_project() {
	std::ofstream main_file("main.c");
	if (!main_file) 
		return FAILURE;
	std::string c_code = "#include <stdio.h>\n\nint main(int argc, char** argv) { \n\n    printf(\"Hello, World!\");\n    return 0;\n}";
	main_file << c_code;
	main_file.close();
    return SUCCESS;
}

int create_cpp_project() {
	std::ofstream main_file("main.cpp");
	if (!main_file) 
		return FAILURE;
	std::string cpp_code = "#include <iostream>\n\nint main(int argc, char** argv) { \n\n    std::cout << \"Hello, World!\" << std::endl;\n\treturn 0;\n}";
	main_file << cpp_code;
	main_file.close();
	return SUCCESS;
}

int create_gitignore() {
	std::ofstream git_file(".gitignore");
	if (!git_file) return FAILURE;
	std::string code = "*.o\n*.exe";
	git_file << code;
	git_file.close();
	return SUCCESS;
}
