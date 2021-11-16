#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **parse_args(char *line)
{
    char **args = malloc(5 * sizeof(char *));
    // the command 
    char *curr = line;
    // keeps track of each piece of the args 
    char *k;
    int i = 0;
    while ((k = strsep(&curr, " ")))
    {
        args[i] = k;
        i++;
    }
    return args;
}

int main()
{
    // the command will just be ls in this case
    char line[100] = "ls -a -l";
    // parse  the args
    char **args = parse_args(line);
    // run command
    execvp(args[0], args);
    return 0;
}