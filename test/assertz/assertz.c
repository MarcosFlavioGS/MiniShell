#include "assertz.h"
#include "terminal_colors.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#define ERROR_MSG "%sERROR%s >> " 
#define OK_MSG    "%sOK%s    >> "

#define PRINT_ERROR	printf(ERROR_MSG, C_RED, C_NRM)
#define PRINT_OK	printf(OK_MSG, C_GRN, C_NRM)
 
const unsigned	title_size = 80;
const unsigned	subtitle_white_space = 20;
const unsigned	subsubtitle_white_space = 10;

void	create_title(const char *title)
{
	const char	x = '=';
	int			size = (title_size - strlen(title));
	size /= 2;
	size--;

	printf("\n");
	for(int a = 0; a < size; a++)
		printf("%c", x);
	printf("  %s  ", title);
	for(int a = 0; a < size; a++)
		printf("%c", x);
	printf("\n\n");
}

void	create_subtitle(const char *subtitle)
{
	const char	x = '+';
	int			size = (title_size - subtitle_white_space - strlen(subtitle));
	int			white_space = subtitle_white_space / 2;
	size /= 2;
	size--;

	printf("\n");

	for(int a = 0; a < white_space; a++)
		printf(" ");
	for(int a = 0; a < size; a++)
		printf("%c", x);
	printf("  %s  ", subtitle);
	for(int a = 0; a < size; a++)
		printf("%c", x);
	for(int a = 0; a < white_space; a++)
		printf(" ");
	printf("\n\n");
}

void 	print_function_name_test(const char *function_name)
{
	create_subtitle(function_name);
}

void	print_subtest_text(const char *subtext)
{

}

int		assert_string(const char *str_expected, const char *str_actual, const char *format, ...)
{
	int returnz = 1;
	va_list args;
	va_start(args, format);
	if(!str_expected && str_actual)
	{
		PRINT_ERROR;
		vprintf(format, args);
		printf(": expected{%sNULL%s}, actual{%s%s%s}\n",
			C_MAG,
			C_NRM,
			C_CYN,
			str_actual,
			C_NRM);
	}
	else if(str_expected && !str_actual)
	{
		PRINT_ERROR;
		vprintf(format, args);
		printf(": expected{%s%s%s}, actual{%sNULL%s}\n",
			C_CYN,
			str_expected,
			C_NRM,
			C_MAG,
			C_NRM);
	}
	else if(str_expected && str_actual && strcmp(str_expected, str_actual))
	{
		PRINT_ERROR;
		vprintf(format, args);
		printf(": expected{%s%s%s}, actual{%s%s%s}\n",
			C_CYN,
			str_expected,
			C_NRM,
			C_CYN,
			str_actual,
			C_NRM);
	}
	else
	{
		if(str_expected && str_actual)
		{
			PRINT_OK;
			vprintf(format, args);
			printf(": expected{%s%s%s}, actual{%s%s%s}\n",
				C_CYN,
				str_expected,
				C_NRM,
				C_CYN,
				str_actual,
				C_NRM);
		}
		else
		{
			PRINT_OK;
			vprintf(format, args);
			printf(": expected{%sNULL%s}, actual{%sNULL%s}\n",
				C_MAG,
				C_NRM,
				C_MAG,
				C_NRM);
		}
		returnz = 0;
	}
	va_end(args);
	return returnz;
}

int		assert_uvalue(uintmax_t value_expected, uintmax_t value_actual, const char *format, ...)
{
	int returnz = 0;
	va_list args;
	va_start (args, format);
	if(value_expected == value_actual)
	{
		PRINT_OK;
		vprintf(format, args);
		printf(": expected{%s%ju%s}, actual{%s%ju%s}\n",
			C_CYN,
			value_expected,
			C_NRM,
			C_CYN,
			value_actual,
			C_NRM);
	}
	else
	{
		PRINT_ERROR;
		vprintf(format, args);
		printf(": expected{%s%ju%s}, actual{%s%ju%s}\n",
			C_CYN,
			value_expected,
			C_NRM,
			C_CYN,
			value_actual,
			C_NRM);
		returnz = 1;
	}
	va_end(args);
	return (returnz);
}

int		assert_svalue(intmax_t value_expected, intmax_t value_actual, const char *format, ...)
{
	int returnz = 0;
	va_list args;
	va_start (args, format);
	if(value_expected == value_actual)
	{
		PRINT_OK;
		vprintf(format, args);
		printf(": expected{%s%jd%s}, actual{%s%jd%s}\n",
			C_CYN,
			value_expected,
			C_NRM,
			C_CYN,
			value_actual,
			C_NRM);
	}
	else
	{
		PRINT_ERROR;
		vprintf(format, args);
		printf(": expected{%s%jd%s}, actual{%s%jd%s}\n",
			C_CYN,
			value_expected,
			C_NRM,
			C_CYN,
			value_actual,
			C_NRM);
		returnz = 1;
	}
	va_end(args);
	return (returnz);
}

int		assert_address(const void *expected, const void *actual, const char *format, ...)
{
	int returnz = 0;
	const char *value_expected = (const char *)expected;
	const char *value_actual = (const char *) actual;

	va_list args;
	va_start (args, format);
	if(value_expected == value_actual)
	{
		PRINT_OK;
		vprintf(format, args);
		printf(": expected{%s%p%s}, actual{%s%p%s}\n",
			C_CYN,
			value_expected,
			C_NRM,
			C_CYN,
			value_actual,
			C_NRM);
	}
	else
	{
		PRINT_ERROR;
		vprintf(format, args);
		printf(": expected{%s%p%s}, actual{%s%p%s}\n",
			C_CYN,
			value_expected,
			C_NRM,
			C_CYN,
			value_actual,
			C_NRM);
		returnz = 1;
	}
	va_end(args);
	return (returnz);
}


void	*assert_calloc(size_t nitems, size_t size, char *error_msg)
{
	void	*returnz;

	returnz = calloc(nitems, size);
	if (!returnz)
	{
		if(error_msg)
			fprintf(stderr, "%s", error_msg);
		abort();
	}
	return returnz;
}

void	*assert_malloc(size_t size, char *error_msg)
{
	void	*returnz;

	returnz = malloc(size);
	if (!returnz)
	{
		if(error_msg)
			fprintf(stderr, "Fatal: failed to allocate list_one_item1 (2).\n");
		abort();
	}
	return returnz;
}
