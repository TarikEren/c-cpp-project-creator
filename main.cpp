#include "./headers/file_creation.h"
#include "./headers/prompts.h"
#include <string.h>

//TODO: Create a .gitignore file that ignores .o and .exe files.

int main(int argc, const char** argv) { 
    if (argc == 1) {
        printf("ERROR: Provide a valid argument. Type project-creator -h for help\n");
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-h")) {
            help_prompt();
            return 0;
        }
        else if (!strcmp(argv[i], "--no-make")) {
            printf("INFO: User opted for no makefile\n");
            if (argv[i+1] == NULL) {
                printf("ERROR: No project name provided.");
                return 1;
            }
            else project_prompt(argv[i+1], 0);
            if (project_prompt(argv[i+1], 0) == PATH_EXISTS) {
                return PATH_EXISTS;
            }
        }
        else if (!strcmp(argv[i], "-v")) {
            printf("version: 2.0.0");
        }
        else project_prompt(argv[i], 1);
        if (project_prompt(argv[i+1], 0) == PATH_EXISTS) {
            return PATH_EXISTS;
        }
    }
    
    return 0;
}