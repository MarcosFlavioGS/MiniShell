#include "../../include/minishell.h"
#include "../assertz/assertz.h"
#include "../../include/parser/list_token.h"
#include "../../include/parser/token.h"
#include <stdlib.h>
#include <stdio.h>

static const char *format = "%-30s%s";

static void	list_token_add_end_test()
{
	create_subtitle("list_add_token_end_test");

	t_token *head = NULL;
	t_token one;
	one.text = "one";
	one.next = NULL;
	list_token_add_end(&head, &one);
	assert_string("one", head->text, "first token");

	t_token two;
	two.text = "two";
	two.next = NULL;
	list_token_add_end(&head, &two);
	assert_string("two", head->next->text, "two token");

	t_token three;
	three.text = "three";
	three.next = NULL;
	list_token_add_end(&head, &three);
	assert_string("three", head->next->next->text, "three token");
}

static void	list_token_add_index_test()
{
	int returnz = 1;
	create_subtitle("list_token_add_index");

	//null and invalid index
	t_token *list_null_head = NULL;
	t_token	add1;
	returnz = list_token_add_index(&list_null_head, &add1, 1);
	assert_svalue(1, returnz, "index 1 list_null");
	printf("====\n");

	//list one and invalid index;
	t_token list_one1_add;
	t_token list_one1_item1;
	t_token *list_one1_head;
	list_one1_add.next = NULL;
	list_one1_item1.next = NULL;
	list_one1_head = &list_one1_item1;
	returnz = list_token_add_index(&list_one1_head, &list_one1_add, 0);
	assert_svalue(0, returnz, "list_one1 add index 0");
	assert_address(&list_one1_add, list_one1_head, "%-30s", "list_one1 head");
	assert_address(&list_one1_item1, list_one1_head->next, "%-30s", "list_one1_head->next");
	returnz = list_token_add_index(&list_one1_head, &list_one1_add, 3);
	assert_svalue(1, returnz, "index 3 list_one1");
	printf("====\n");

	//list two
	t_token list_two1_add;
	t_token list_two1_item2;
	t_token list_two1_item1;
	t_token *list_two1_head;
	list_two1_add.next = NULL;
	list_two1_item2.next = NULL;
	list_two1_item1.next = &list_two1_item2;
	list_two1_head = &list_two1_item1;
	returnz = list_token_add_index(&list_two1_head, &list_two1_add, 1);
	assert_svalue(0, returnz, "list_two1 add index 1");
	assert_address(&list_two1_item1, list_two1_head, "%-30s", "list_two1 head");
	assert_address(&list_two1_add, list_two1_head->next, "%-30s", "list_two1 head->next");
	assert_address(&list_two1_item2, list_two1_head->next->next, "%-30s", "list_two1 head->next->next");
	returnz = list_token_add_index(&list_two1_head, &list_two1_add, 3);
	assert_svalue(1, returnz, "index 3 list_two1");
	printf("====\n");
}

static void	list_token_get_test()
{
	create_subtitle("list_token_get_test");

	t_token *nulll = NULL;
	assert_address(0, list_token_get(nulll, 1), "null");

	t_token two;
	two.text = "two";
	two.next = NULL;

	t_token one;
	one.text = "one";
	one.next = &two;

	t_token *head = NULL;
	head = &one;

	t_token *index_1 = list_token_get(head, 0);
	t_token *index_2 = list_token_get(head, 1);
	t_token *index_null = list_token_get(head, 2);

	assert_string("one", index_1->text, "index1");
	assert_string("two", index_2->text, "index2");
	assert_address(0, index_null, "index2");
}

static void	list_token_clear_test()
{
	create_subtitle("list_token_clear_test");

	t_token *nulll = NULL;
	list_token_clear(&nulll);
	assert_address(0, nulll, "clear empty list (null)");

	t_token *one = token_create("a", word);
	t_token *two = token_create("T", word);
	if (!one || !two)
	{
		fprintf(stderr, "Fatal: failed to allocate t_token.\n");
		abort();
	}
	two->next = NULL;
	one->next = two;
	t_token *head;
	head = one;
	list_token_clear(&head);
	assert_address(0, head, "clear list with itens");

	//free
	list_token_clear(&head);
}

static void list_token_remove_test()
{
	int returnz = 0;
	create_subtitle("list_token_remove_test");

	//empty list test (null);
	t_token *nulll = NULL;
	returnz = list_token_remove(&nulll, 0);
	assert_svalue(1, returnz, "empty list, index 0");
	returnz = list_token_remove(&nulll, 1);
	assert_svalue(1, returnz, "empty list, index 1");

	printf("====\n");

	//one item list test
	t_token *list_one1_item1 = assert_calloc(1, sizeof(*list_one1_item1), "Fatal: failed to allocate list_one1_item1 (1).\n");
	t_token *list_one1_head;
	list_one1_head = list_one1_item1;
	returnz = list_token_remove(&list_one1_head, 0);
	assert_svalue(0, returnz, "list_one_item remove index 0 returnz");
	assert_address(0, list_one1_head, "list_one_item remove index 0 head");
	printf("\n");

	list_one1_item1 = assert_calloc(1, sizeof(*list_one1_item1), "Fatal: failed to allocate list_one1_item1 (2).\n");
	list_one1_head = list_one1_item1;
	returnz = list_token_remove(&list_one1_head, 1);
	assert_svalue(1, returnz, "list_one_item remove index 1 (invalid index) returnz");
	assert_address(list_one1_item1, list_one1_head, "list_one1_head remove index 1 (invalid index)");

	printf("====\n");

	//two item list test
	t_token *list_two1_item1 = assert_calloc(1, sizeof(*list_two1_item1), "Fatal: failed to allocate list_two1_item1 malloc");
	t_token *list_two1_item2 = assert_calloc(1, sizeof(*list_two1_item2), "Fatal: failed to allocate list_two1_item2 malloc");
	t_token *list_two1_head = list_two1_item1;
	list_two1_item1->next = list_two1_item2;
	list_token_remove(&list_two1_head, 2);
	assert_address(list_two1_item1, list_two1_head,	format,	"list_two1_head", "remove index 2 (invalid index)");
	assert_address(list_two1_item2, list_two1_head->next,format, "list_two1_head->next", "remove index 2 (invalid index)");
	printf("\n");

	t_token *list_two2_item1 = assert_calloc(1, sizeof(*list_two2_item1), "Fatal: failed to allocate list_two2_item1 malloc");
	t_token *list_two2_item2 = assert_calloc(1, sizeof(*list_two2_item2), "Fatal: failed to allocate list_two2_item2 malloc");
	t_token *list_two2_head = list_two2_item1;
	list_two2_item1->next = list_two2_item2;
	list_token_remove(&list_two2_head, 0);
	assert_address(list_two2_item2, list_two2_head,	format,	"list_two2_head", "remove index 0");
	printf("\n");

	t_token *list_two3_item1 = assert_calloc(1, sizeof(*list_two3_item1), "Fatal: failed to allocate list_two3_item1 malloc");
	t_token *list_two3_item2 = assert_calloc(1, sizeof(*list_two3_item2), "Fatal: failed to allocate list_two3_item2 malloc");
	t_token *list_two3_head = list_two3_item1;
	list_two3_item1->next = list_two3_item2;
	list_token_remove(&list_two3_head, 1);
	assert_address(list_two3_item1, list_two3_head,	format,	"list_two3_head", "remove index 1");
	assert_address(NULL, list_two3_head->next,	format,	"list_two3_head->next", "remove index 1");

	printf("====\n");

	//three item list test
	t_token *list_three_head  = NULL;
	t_token *list_three_item1 = assert_calloc(1, sizeof(*list_three_item1), "Fatal: failed to allocate list_three_item1 malloc");
	t_token *list_three_item2 = assert_calloc(1, sizeof(*list_three_item2), "Fatal: failed to allocate list_three_item2 malloc");
	t_token *list_three_item3 = assert_calloc(1, sizeof(*list_three_item2), "Fatal: failed to allocate list_three_item3 malloc");
	list_three_head = list_three_item1;
	list_three_item1->next = list_three_item2;
	list_three_item2->next = list_three_item3;
	list_token_remove(&list_three_head, 1);
	assert_address(list_three_item1, list_three_head,	format,	"list_three_head", "remove index 1");
	assert_address(list_three_item3, list_three_head->next,	format,	"list_three_head->next", "remove index 1");
	assert_address(NULL, list_three_item3->next,	format,	"list_three_item3->next", "== NULL");
	printf("\n");

	//free all lists
	list_token_clear(&list_one1_head);
	list_token_clear(&list_two1_head);
	list_token_clear(&list_two2_head);
	list_token_clear(&list_two3_head);
	list_token_clear(&list_three_head);
}

// list_token_test.c
void	list_token_test()
{
	create_title("list_token_test");

	list_token_add_end_test();
	list_token_add_index_test();
	list_token_get_test();
	list_token_clear_test();
	list_token_remove_test();
}
