# MiniShell

### Table of Contents

- Introdution
- Features
- Getting started
  - Prerequisites
  - Instalation
- Usage
- Commands

## Introdution

MiniShell 42 is a simple, lightweight Unix shell written in C, inspired by Bash. It is designed to provide a basic shell environment for users to interact with their operating system through a command-line interface.

This project was developed as part of the "42 School" curriculum, and it serves as a hands-on project to learn and practice systems programming concepts in Unix-like environments.

## Features

- Basic command execution.
- Simple command-line parsing.
- Support for built-in commands (e.g., cd, echo, pwd, env).
- Input and output redirection (e.g., >, >>, <).
- Heredoc.
- Pipes for chaining commands (e.g., command1 | command2).
- Enviroment variable expansions.
- Signal handling (e.g., Ctrl+C to interrupt).
- Error handling.

## Getting Started

### Prerequisites

To build and run MiniShell 42, you'll need:

- A Unix-like operating system (Linux recommended).
- A C compiler (e.g., GCC).
- Make utility.

### Instalation

Clone the repository:

``` sh
git clone https://github.com/MarcosFlavioGS/MiniShell
```

Change to the directory and run the *Make* command

``` sh
> cd MiniShell
> make
```

This will compile the MiniShell source code and create an executable called minishell.

## Usage

To start MiniShell 42, simply run the minishell executable from the project directory:

``` sh
./minishell
```

You will be presented with a command prompt where you can enter Unix-like commands. MiniShell 42 supports a variety of built-in commands as well as external commands available in your system's PATH.

To exit MiniShell 42, you can use the exit command or press Ctrl+D.

## Commands

MiniShell 42 supports both built-in commands and external commands. Here are some examples of built-in commands:

- cd [directory]: Change the current working directory.
- echo [text]: Display text.
- pwd: Print the current working directory.
- env: Display the environment variables.
- export: export a new environment variable or update an existing one.
- unset: Removes an environment variable.
- exit: Exits the shell.

You can also run external commands that are available in your system's PATH, such as:

- ls: List files and directories.
- cat [file]: Display the contents of a file.
- gcc [source.c] -o [output]: Compile a C program.
...

Feel free to explore more Unix commands and use them within MiniShell 42.
