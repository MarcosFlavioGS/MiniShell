#include "debug_utils.h"
#include <string.h>

/**
 * compare_strings - compare two strings
 *
 * Return:
 * 	0 equals
 * 	1 not equals
 */
int	compare_strings(char *str1, char *str2)
{
	if((str1 && !str2) || (!str1 && str2))
		return 1;
	if(!str1 && !str2)
		return 0;
	else
		return strcmp(str1, str2);
}
