/*

aush - Annoyingly Useless Shell

This shell sometimes runs what it's asked to and sometimes just doesn't.

*/

/* Header declaration */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Main function */
int main(int argc, char* argv[])
{
    /* Variable initialisation */
    char command[100] = "";
    int randval = 0;
    int debugmode = 0;

    /* Handle command line arguments */
    if (argc > 1)
    {
        /* Enable debug mode */
        if (strcmp(argv[1], "-d") || strcmp(argv[1], "--debug"))
        {
            debugmode = 1;
        }
    }

    /* For-ever loop */
    for (;;)
    {
        /* Display prompt and get input */
        printf("> ");
        fgets(command, 100, stdin);

        /* Trim off whitespace */
        command[strcspn(command, "\n")] = 0;

        /* If the command is 'exit' then break the loop */
        if (!strcmp(command, "exit"))
        {
            break;
        }
        /* Otherwise, do the following */
        else
        {
            /* Store random number */
            randval = rand() % 2;

            /* Debugging */
            if (debugmode)
            {
                printf("Random value is %d\n", randval);
                printf("Command is %s\n", command);
            }

            /* If the random value is nonzero, then run the command.
               Otherwise, ignore the command. */
            if (randval)
            {
                system(command);
            }
            else
            {
                char* basecmd = strtok(command, " ");
                printf("aush: command ignored: %s\n", basecmd);
            }
        }
    }
    return 0;
}