#include "../headers/prompts.h"
#include "../headers/file_creation.h"

//File creation functions require refactoring.

void help_prompt() {
    printf("Creates a C or C++ project template that prints out 'Hello, World!'\n");
    printf("Usage: project-creator [flags] [project name]\n\n");
    printf("Flags:\n");
    printf("-h\tPrints out command list\n");
    printf("-v\tPrints out the version\n");
    return;
}

std::filesystem::file_status status = {};

int project_prompt(const char* project_name) {
    int git_ignore;
    int file;
    int makefile;
    if (dir_exists(project_name, status)) {
        printf("ERROR: Path already exists\n");
        return PATH_EXISTS;
    }
    else {
        fs::create_directory(project_name);
        fs::current_path(project_name);
        int opt;
        std::cout << "1- C Project\n2- C++ Project\n> ";
        std::cin >> opt; 

        //May God forgive me for this abomination I've spawned.
        if (opt == 1) {
            file = create_c_project();
            if (file) {
                makefile = create_makefile();
                if (makefile) {
                    git_ignore = create_gitignore();
                    if (git_ignore){
                        std::cout << "\nINFO: Project created successfully." << std::endl;
                        return SUCCESS;
                    }
                    else {
                        std::cerr << "ERROR: Failed to create .gitignore. Aborting." << std::endl;
                        return FAILURE;
                    }
                }
                else {
                    std::cerr << "ERROR: Failed to create makefile. Aborting." << std::endl;
                    return FAILURE;
                }
            }
            else {
                std::cerr << "ERROR: Failed to create main.c. Aborting." << std::endl;
                return FAILURE;
            }
        }
        else if (opt == 2) {
            file = create_cpp_project();
            if (file) {
                makefile = create_cmakelists();
                if (makefile) {
                    git_ignore = create_gitignore();
                    if (git_ignore){
                        std::cout << "\nINFO: Project created successfully." << std::endl;
                        return SUCCESS;
                    }
                    else {
                        std::cerr << "ERROR: Failed to create .gitignore. Aborting." << std::endl;
                        return FAILURE;
                    }
                }
                else {
                    std::cerr << "ERROR: Failed to create CMakeLists. Aborting." << std::endl;
                    return FAILURE;
                }
            }
            else {
                std::cerr << "ERROR: Failed to create main.cpp. Aborting." << std::endl;
                return FAILURE;
            }
        }
        else {
            std::cout << "ERROR: Wrong input" << std::endl;
            return FAILURE;
        }
    }
    return SUCCESS;
}
