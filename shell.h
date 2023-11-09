#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>

/**
 * display_prompt - Display the shell prompt and read user input
 */
void display_prompt(void);

/**
 * execute_command - Execute a command entered by the user
 * @command: The command to be executed
 */
void execute_command(const char *command);

/**
 * handle_eof - Handle the "end of file" condition (Ctrl+D)
 *
 * Return: 1 if Ctrl+D is detected, 0 otherwise
 */
int handle_eof(void);

#endif
