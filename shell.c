#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARGS 10

/**
 * read_command - parses a command line into an array of arguments
 * @line: the command line to parse
 * @args: a pointer to an array of pointers to store the parsed arguments
 *
 * Return: 0 on success
 */

int read_command(char *line, char **args)
{
char *token;
int i = 0;

/* Parse the command line */
token = strtok(line, " \n");
while (token != NULL && i < MAX_ARGS - 1)
{
args[i] = token;
token = strtok(NULL, " \n");
i++;
}
args[i] = NULL;

/* Return success */
return (0);
}

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, non-zero on failure
 */

int main(void)
{
char line[1024];
char *args[MAX_ARGS];
int status;

while (1)
{
printf("$ ");
fgets(line, sizeof(line), stdin);

/* Remove newline character */
line[strcspn(line, "\n")] = '\0';

/* Parse command line */
read_command(line, args);

/* Print arguments */
for (int i = 0; args[i] != NULL; i++)
{
printf("arg[%d]: %s\n", i, args[i]);
}
}

return (status);
}
