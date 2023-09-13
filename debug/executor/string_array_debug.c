#include "string_array_debug.h"
#include "../debug_utils.h"
#include <stddef.h>
#include <stdio.h>

static int string_array_size(char **array)
{
	size_t	size = 0;

	while(array[size])
		size++;
	return size;
}

int string_array_compare(char **expected, char **actual)
{
	size_t size_exp;
	size_t size_act;

	if (!expected && !actual)
		return 0;
	if((expected && !actual) || (!expected && actual))
		return 1;
	size_exp = string_array_size(expected);
	size_act = string_array_size(actual);
	if (size_exp != size_act)
		return 1;
	while (expected[size_exp])
	{
		if (compare_strings(expected[size_exp], actual[size_exp]))
			return 1;
		size_exp++;
	}
	return 0;
}

void string_array_printf(char **array)
{
	char *line = NULL;
	printf("[");
	if (!array)
	{
		printf("%s", line);
	}
	else
	{
		while (*array)
		{
			if (*(array + 1))
				printf("%s, ", *array);
			else
				printf("%s", *array);
			array++;
		}
	}
	printf("]");
}