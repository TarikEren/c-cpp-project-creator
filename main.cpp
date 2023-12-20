#include <iostream>
#include <fstream>
#include <string.h>
#include <filesystem>

void help_prompt() {
    printf("Creates a C or C++ project template that prints out 'Hello, World!'\n");
    printf("Usage: project-creator [flags] [project name]\n\n");
    printf("Flags:\n");
    printf("-h\t\tPrints out command list\n");
    printf("--no-make\tNo makefile\n");
    exit(EXIT_SUCCESS);
}

int create_c_makefile() {
    std::ofstream makefile("makefile");
	if (!makefile) 
		return 1;
	std::string makefile_code = "CC = gcc \n\ndefault: main.o\n\t${CC} main.o -o main\n\nmain.o: main.c\n\t${CC} main.c -c\n\nclean:\n\tdel *.o *.exe";
	makefile << makefile_code;
	makefile.close();
	return 0;
}

int create_cpp_makefile() {
	std::ofstream makefile("makefile");
	if (!makefile) 
		return 1;
	std::string makefile_code = "CC = g++\n\ndefault: main.o\n\t${CC} main.o -o main\n\nmain.o: main.cpp\n\t${CC} main.cpp -c\n\nclean:\n\tdel *.o *.exe";
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

void project_prompt(const char* project_name, int create_makefile) {
    std::filesystem::create_directory(project_name);
    std::filesystem::current_path(project_name);
    int opt;
    std::cout << "1- C Project\n2- C++ Project\n> ";
    std::cin >> opt; 
    if (create_makefile == 1) {
        if (opt == 1) {
            std::cout << "\nProject created successfully." << std::endl;
            create_c_project();
            create_c_makefile();
            exit(EXIT_SUCCESS);
        }
        else if (opt == 2) {
            std::cout << "\nProject created successfully." << std::endl;
            create_cpp_project();
            create_cpp_makefile();
            exit(EXIT_SUCCESS);
        }
        else {
            std::cout << "Wrong input" << std::endl;
            exit(EXIT_SUCCESS);
        }
    }
    else if (create_makefile == 0) {
        if (opt == 1) {
            std::cout << "\nProject created successfully." << std::endl;
            create_c_project();
            exit(EXIT_SUCCESS);
        }
        else if (opt == 2) {
            std::cout << "\nProject created successfully." << std::endl;
            create_cpp_project();
            exit(EXIT_SUCCESS);
        }
        else {
            std::cout << "Wrong input" << std::endl;
            exit(EXIT_SUCCESS);
        }
    }
}

int main(int argc, const char** argv) { 
    const char* flags[4] = {"-h", "--no-make"};
    for (int i = 1; i < argc; i++) {
        for (int j = 0; j < 2; j++) {
            if (!strcmp(flags[i], "-h") && !strcmp(argv[i], "-h"))
                help_prompt();
            else if (!strcmp(flags[i], "--no-make") && !strcmp(argv[i], "--no-make")) {
                printf("User opted for no makefile\n");
                project_prompt(argv[i+1], 0);
            }
            else {
                project_prompt(argv[i], 1);
            }
        }
    }
    
    return 0;
}