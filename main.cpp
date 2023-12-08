#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>

int create_c_project() {
	std::ofstream main_file("main.c");
	if (!main_file) 
		return 1;
	std::string c_code = "#include <stdio.h>\n\nint main(int argc, char** argv) { \n\n    printf(\"Hello, World!\");\n    return 0;\n}";
	main_file << c_code;
	main_file.close();
	
	std::ofstream makefile("makefile");
	if (!makefile) 
		return 1;
	std::string makefile_code = "CC = gcc \n\ndefault: main.o\n\t${CC} main.o -o main\n\nmain.c:\n\t${CC} main.c -c\n\nclean:\n\tdel *.o *.exe";
	makefile << makefile_code;
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
	
	std::ofstream makefile("makefile");
	if (!makefile) 
		return 1;
	std::string makefile_code = "CC = g++\n\ndefault: main.o\n\t${CC} main.o -o main\n\nmain.cpp:\n\t${CC} main.cpp -c\n\nclean:\n\tdel *.o *.exe";
	makefile << makefile_code;
	main_file.close();
	return 0;
}
int create_py_project() {
	std::ofstream main_file("main.py");
	if (!main_file) 
		return 1;
	main_file << "print(\"Hello, World!\")";
	main_file.close();
	return 0;	
}
void project_prompt(char* project_name) {
    std::filesystem::create_directory(project_name);
    std::filesystem::current_path(project_name);
    int opt;
    std::cout << "1- C Project\n2- C++ Project\n3- Python Project\n> ";
    std::cin >> opt; 
    switch (opt) {
        case 1:
            create_c_project();
            if (create_c_project() == 0) {
                std::cout << "\nProject created successfully.\nType cd ./" << project_name << "; make; ./main.exe to run." << std::endl;
            }
            break;
        case 2:
            create_cpp_project();
            if (create_cpp_project() == 0) {
                std::cout << "\nProject created successfully.\nType cd ./" << project_name << "; make; ./main.exe to run." << std::endl;
            }
            break;
        case 3:
            create_py_project();
            if (create_py_project() == 0) {
                std::cout << "\nProject created successfully." << std::endl;
            }
            break;
        default:
            std::cout << "\nWrong input." << std::endl;
            break;
    }
}
int main(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-h")) {
            printf("help\n");
        }
        else if (!strcmp(argv[i], "-f")) {
            printf("Flag");
        }
        else {
            char* project_name = argv[i];
            project_prompt(project_name);
        }
    }
    return 0;
}