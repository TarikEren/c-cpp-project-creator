# project-creator (WIP)

#### Lets the user create simple project templates using the terminal.

Creates C and C++ projects that output a "Hello, World!" message.

### Setup:
    Windows:
    - Make sure you have make installed.
    - Start a terminal instance.
    - Navigate to the folder that includes the main.cpp file.
    - Run "make".
    - Add the location of the "project-creator.exe" to your PATH variable.
    
    You should be able to run the program through the terminal now.

### Usage:
    project-creator [flags] [project name]
    
    Flags:
    - -h: Help command that displays available commands (Only prints "help" for now)
    - --no-make: Creates project without a makefile.
    