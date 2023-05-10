#include "../mini_shell.h"

static unsigned int char_sum(const char *str) {
    unsigned int n;
    int i;

    n = 0;
    i = 0;
    while (str[i])
    {
        n += str[i++];
    }
    return (n);
}

unsigned int hash(const char *str) {
    return ((char_sum(str) * 42) % 15);
}
