#ifndef ASSERTZ_H
#define ASSERTZ_H
#include <stddef.h>
#include <stdint.h>

#define POINTER(x) ((const char *) (x))
#define ADDRESS(x) ((const char *) (&(x)))

/**
 * Test if one string is equal to another.
 */
#define ASSERT_STRING(x, y, ...) \
	assert_string(POINTER(x), POINTER(y), __VA_ARGS__)

/**
 * Tests whether the addresses of two objects are the same. This method takes
 * the address of the objects to make the comparison. Therefore DO NOT PASS THE
 * POINTERS, but the objects. This method will capture the addresses.
 */
#define ASSERT_ADDRESS(x, y, ...) \
	assert_address(ADDRESS(x), ADDRESS(y), __VA_ARGS__)

void	create_title(const char *title);

void	create_subtitle(const char *subtitle);

void 	assert_print_function_name(const char *function_name);

void	assert_print_subtest_text(const char *subtext);

int		assert_string(const char *str_expected, const char *str_actual, const char *format, ...);

int		assert_address(const void *expected, const void *actual, const char *format, ...);

int		assert_uvalue(uintmax_t value_expected, uintmax_t value_actual, const char *format, ...);

int		assert_svalue(intmax_t value_expected, intmax_t value_actual, const char *format, ...);

//memory

void	*assert_calloc(size_t nitems, size_t size, char *error_msg);

void	*assert_malloc(size_t size, char *error_msg);


//utils

void	assert_utils_die(const char *format, ...);

void	assert_utils_separator();

void	assert_utils_print_ok(const char *format, ...);

void	assert_utils_print_error(const char *format, ...);

#endif
