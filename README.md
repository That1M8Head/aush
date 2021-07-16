# `aush` - the Annoyingly Useless Shell
A command-line shell that when it wants to work, it's the most basic shell you can get, and when it doesn't want to work, it's super annoying.

## How it works
### TL;DR
RNG determines whether or not commands work.
### Detailed explanation (with code snippets)
A random number is generated between 0 and 1.
```c
randval = rand() % 2;

```
If the random number is nonzero, then it executes the command.
```c
if (randval)
{
    system(command);
}
```
Otherwise, it ignores the command. `strtok` isolates the first word of the command.
```c
else
{
    char* basecmd = strtok(command, " ");
    printf("aush: command ignored: %s\n", basecmd);
}
```

## Debugging
You can enable debug mode, which shows you what command you entered and what random value you got.

Run `aush` with `-d` or `--debug` to enable it.