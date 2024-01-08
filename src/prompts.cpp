#include "../headers/prompts.h"
#include "../headers/file_creation.h"

void help_prompt() {
    printf("Creates a C or C++ project template that prints out 'Hello, World!'\n");
    printf("Usage: project-creator [flags] [project name]\n\n");
    printf("Flags:\n");
    printf("-h\t\tPrints out command list\n");
    printf("--no-make\tNo makefile\n");
    printf("-v\tPrints out the version\n");
    exit(EXIT_SUCCESS);
}

std::filesystem::file_status status = {};

void project_prompt(const char* project_name, int create_makefile) {
    if (dir_exists(project_name, status)) {
        printf("ERROR: Path already exists\n");
        return;
    }
    else {
        fs::create_directory(project_name);
        fs::current_path(project_name);
        int opt;
        std::cout << "1- C Project\n2- C++ Project\n> ";
        std::cin >> opt; 
        if (create_makefile == 1) {
            if (opt == 1) {
                std::cout << "\nINFO: Project created successfully." << std::endl;
                create_c_project();
                create_c_makefile();
                exit(EXIT_SUCCESS);
            }
            else if (opt == 2) {
                std::cout << "\nINFO: Project created successfully." << std::endl;
                create_cpp_project();
                create_cpp_makefile();
                exit(EXIT_SUCCESS);
            }
            else {
                std::cout << "ERROR: Wrong input" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        else if (create_makefile == 0) {
            if (opt == 1) {
                std::cout << "\nINFO: Project created successfully." << std::endl;
                create_c_project();
                exit(EXIT_SUCCESS);
            }
            else if (opt == 2) {
                std::cout << "\nINFO: Project created successfully." << std::endl;
                create_cpp_project();
                exit(EXIT_SUCCESS);
            }
            else {
                std::cout << "ERROR: Wrong input" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }
}
