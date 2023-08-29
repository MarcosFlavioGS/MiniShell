#include "assertz.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	char *str_1 = "potato";
	char *str_2 = "potato";
	char *str_3 = "potato1";
	char *str_4 = NULL;

	printf("=== simple format string test ===\n");
	// ----- simple format test
	//		        expected value	  actual->(any value to test)     mandatory text to show in text (printf format)	
	//              vvvv			  vvvv                            vvvvv
	ASSERT_STRING("potato"			, str_1							, "test");
//	                                                                            optional format arg (printf format)
//                                                                              vvvvv
	ASSERT_STRING("potato"			, str_1							, "test %s",    "Hi!");
	printf("\n\n");


	// ----- test string
	printf("=== string test ===\n");
	ASSERT_STRING("potato"	, str_1	, "string [ok  test]");
	ASSERT_STRING(str_1		, str_2	, "string [ok  test]");
	ASSERT_STRING(NULL		, str_4	, "string [ok  test]");
	ASSERT_STRING(str_1		, str_3	, "string [err test]");
	ASSERT_STRING(NULL		, str_3	, "string [err test]");
	printf("\n");

	// ----- test address
	printf("=== pointer test ===\n");
	ASSERT_ADDRESS(str_1, str_1, "pointer [ok  test]");
	ASSERT_ADDRESS(str_1, str_2, "pointer [err test]");
	printf("\n");

	//assert_address(((const char *) (&b1)), ((const char *) (&b2)), "pointer");
}
