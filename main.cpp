#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>

int create_c_makefile() {
    std::ofstream makefile("makefile");
	if (!makefile) 
		return 1;
	std::string makefile_code = "CC = gcc \n\ndefault: main.o\n\t${CC} main.o -o main\n\nmain.c:\n\t${CC} main.c -c\n\nclean:\n\tdel *.o *.exe";
	makefile << makefile_code;
	makefile.close();
	return 0;
}

int create_cpp_makefile() {
	std::ofstream makefile("makefile");
	if (!makefile) 
		return 1;
	std::string makefile_code = "CC = g++\n\ndefault: main.o\n\t${CC} main.o -o main\n\nmain.cpp:\n\t${CC} main.cpp -c\n\nclean:\n\tdel *.o *.exe";
	makefile << makefile_code;
	makefile.close();
	return 0;
}

int create_c_project() {
	std::ofstream main_file("main.c");
	if (!main_file) 
		return 1;
	std::string c_code = "#include <stdio.h>\n\nint main(int argc, char** argv) { \n\n    printf(\"Hello, World!\");\n    return 0;\n}";
	main_file << c_code;
	main_file.close();
    return 0;
}
int create_cpp_project() {
	std::ofstream main_file("main.cpp");
	if (!main_file) 
		return 1;
	std::string cpp_code = "#include <iostream>\n\nint main(int argc, char** argv) { \n\n    std::cout << \"Hello, World!\" << std::endl;\n\treturn 0;\n}";
	main_file << cpp_code;
	main_file.close();
	return 0;
}

void project_prompt(char* project_name, int create_makefile) {
    std::filesystem::create_directory(project_name);
    std::filesystem::current_path(project_name);
    int opt;
    std::cout << "1- C Project\n2- C++ Project\n> ";
    std::cin >> opt; 
    if (create_makefile == 1) {
        if (opt == 1) {
            std::cout << "\nProject created successfully.\nType cd " << project_name << "; make; main.exe to run." << std::endl;
            create_c_project();
            create_c_makefile();
            return;
        }
        else if (opt == 2) {
            std::cout << "\nProject created successfully.\nType cd " << project_name << "; make; main.exe to run." << std::endl;
            create_cpp_project();
            create_cpp_makefile();
            return;
        }
        else {
            std::cout << "Wrong input" << std::endl;
            return;
        }
    }
    else if (create_makefile == 0) {
        if (opt == 1) {
            std::cout << "\nProject created successfully.\nType cd " << project_name << "; make; main.exe to run." << std::endl;
            create_c_project();
            return;
        }
        else if (opt == 2) {
            std::cout << "\nProject created successfully.\nType cd " << project_name << "; make; main.exe to run." << std::endl;
            create_cpp_project();
            return;
        }
        else {
            std::cout << "Wrong input" << std::endl;
            return;
        }
    }
}
int main(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-h")) {
            printf("help\n");
            return 0;
        }
        else if (!strcmp(argv[i], "--no-make")) {
            printf("User opted for no makefile.\n");
            char* project_name = argv[i+1];
            project_prompt(project_name, 0);
            return 0;
        }
        else {
            char* project_name = argv[i];
            project_prompt(project_name, 1);
            return 0;
        }
    }
}