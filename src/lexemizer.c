#include "../mini_shell.h"

int token_counter(char **line)
{}

char **lexemizer(char *line)
{
    int  i;
    int  count;
    char **lexemes;

    i = 0;
    count = token_counter(&line);
    lexemes = (char **)malloc(sizeof(char *) * count);
    while (*line)
    {
        while (*line == ' ')
            line++;
        if (*line == 34 || *line == 39)
        {
            lexemes[i] = ft_substring(line, 0, get_last_quote(line));
        }
        else
        {
            lexemes[i] = ft_substring(line, 0, special_strlen(line, ' '));
        }
    }
    return (lexemes);
}
