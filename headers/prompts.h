#ifndef PROMPTS
#define PROMPTS

enum return_values { 
    PATH_EXISTS = -1,
    FAILURE = 1,
    SUCCESS = 0
};


void help_prompt();
int project_prompt(const char* project_name, int create_makefile);

#endif