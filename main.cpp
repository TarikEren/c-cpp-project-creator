#include "./headers/file_creation.h"
#include "./headers/prompts.h"
#include <string.h>

//TODO: This part requires some refactoring.

int main(int argc, const char** argv) { 
    if (argc == 1) {
        printf("ERROR: Provide a valid argument. Type project-creator -h for help\n");
        return FAILURE;
    }
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-h")) {
            help_prompt();
            return SUCCESS;
        }
        else if (!strcmp(argv[i], "-v")) {
            printf("version: 2.0.0");
            break;
        }
        else {
            project_prompt(argv[i]);
        }
    }
    
    return 0;
}