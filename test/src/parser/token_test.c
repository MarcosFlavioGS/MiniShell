#include "token_test.h"
#include "../../../include/minishell.h"
#include "../../../include/parser/token.h"
#include "../../../include/parser/list_token.h"
#include "../../../include/minishell.h"
#include "../../assertz/assertz.h"
#include <stdio.h>

static void	token_separator_test()
{
	create_subtitle("handler_separator_test");

	//1 space default
	t_stream tok1;
	tok1.line = " ";
	tok1.index = 0;

	t_token *token1 = token_separator(&tok1);
	assert_string(" ", token1->text, "default 1 space text");
	assert_svalue(separator, token1->type, "default 1 space type");
	assert_svalue(0, tok1.line[tok1.index], "default space 1 \\0 index");

	//1 space not default
	t_stream tok2;
	tok2.line = "  ";
	tok2.index = 0;

	t_token *token2 = token_separator(&tok2);
	assert_string("  ", token2->text, "not default 2 space text");
	assert_svalue(separator, token2->type, "default 2 space type");
	assert_svalue(0, tok2.line[tok2.index], "not default space 2 \\0 index");

	//free
	list_token_clear(&token1);
	list_token_clear(&token2);

}

static void	token_redict_in_test()
{
	create_subtitle("handler_redict_in_test");
	//1 <
	t_stream tok1;
	tok1.line = "<";
	tok1.index = 0;
	t_token *token1 = token_redir_in(&tok1);
	assert_string("<", token1->text, "redirect in <");
	assert_svalue(redir_in, token1->type, "redirect in type");
	assert_svalue(0, tok1.line[tok1.index], "redirect in < index \\0");
	printf("====\n");

	//2 <<
	t_stream tok2;
	tok2.line = "<<";
	tok2.index = 0;
	t_token *token2 = token_redir_in(&tok2);
	assert_string("<<", token2->text, "heredoc text <<");
	assert_svalue(heredoc, token2->type, "heredoc type");
	assert_svalue(0, tok2.line[tok2.index], "heredoc << index \\0");

	//free
	list_token_clear(&token1);
	list_token_clear(&token2);
}

static void	token_redict_out_test()
{
	create_subtitle("handler_redict_out_test");
	//1 >>
	t_stream tok1;
	tok1.line = ">";
	tok1.index = 0;
	t_token *token1 = token_redir_out(&tok1);
	assert_string(">", token1->text, "redirect out >");
	assert_svalue(redir_out, token1->type, "redirect in type");
	assert_svalue(0, tok1.line[tok1.index], "redirect in > index \\0");
	printf("====\n");

	//2 >>
	t_stream tok2;
	tok2.line = ">>";
	tok2.index = 0;
	t_token *token2 = 	token_redir_out(&tok2);
	assert_string(">>", token2->text, "append text >>");
	assert_svalue(append, token2->type, "append type");
	assert_svalue(0, tok2.line[tok2.index], "append >> index \\0");

	//free
	list_token_clear(&token1);
	list_token_clear(&token2);
}

static void	token_pipe_test()
{
	create_subtitle("handler_pipe_test");
	//1 >>
	t_stream tok1;
	tok1.line = "|";
	tok1.index = 0;
	t_token *token1 = token_pipe(&tok1);
	assert_string("|", token1->text, "pipe text |");
	assert_svalue(pipez, token1->type, "pipe type");
	assert_svalue(0, tok1.line[tok1.index], "pipe | index \\0");

	//free
	list_token_clear(&token1);
}

static void	token_expand_test()
{
	create_subtitle("handler_expand_test");
	//1 >>
	t_stream tok1;
	tok1.line = "$";
	tok1.index = 0;
	t_token *token1 = token_expand(&tok1);
	assert_string("$", token1->text, "expand text $");
	assert_svalue(expand, token1->type, "expand type");
	assert_svalue(0, tok1.line[tok1.index], "expand $ index \\0");

	//free
	list_token_clear(&token1);
}

static void	token_eol_test()
{
	create_subtitle("handler_eol_test");
	//1 >>
	t_stream	tok1;
	tok1.line = "\0";
	tok1.index = 0;
	t_token *token1 = token_eol();
	assert_string("\0", token1->text, "eol text $");
	assert_svalue(eol, token1->type, "eol type");
	assert_svalue(0, tok1.line[tok1.index], "eol index \\0");

	//free
	list_token_clear(&token1);
}

static void	token_dquote_test()
{
	create_subtitle("handler_dquote_test");
	//1 >>
	t_stream tok1;
	tok1.line = "\"";
	tok1.index = 0;
	t_token *token1 = token_expand(&tok1);
	assert_string("$", token1->text, "dquote text \"");
	assert_svalue(expand, token1->type, "dquote type");
	assert_svalue(0, tok1.line[tok1.index], "dquote \" index \\0");

	//free
	list_token_clear(&token1);
}

void	token_squote_test()
{
	create_subtitle("handler_squote_test");
	//1 >>
	t_stream tok1;
	tok1.line = "\'";
	tok1.index = 0;
	t_token *token1 = token_expand(&tok1);
	assert_string("$", token1->text, "squote text \'");
	assert_svalue(expand, token1->type, "squote type");
	assert_svalue(0, tok1.line[tok1.index], "squote \' index \\0");

	//free
	list_token_clear(&token1);
}

static void	token_word_test()
{
	create_subtitle("handler_word_test");

	//1 word
	t_stream tok1;
	tok1.line = "1";
	tok1.index = 0;
	t_token *token1 = token_word(&tok1);
	assert_string("1", token1->text, "word text");
	assert_svalue(word, token1->type, "word type");
	assert_svalue(0, tok1.line[tok1.index], "word \\0 index");

	//big word
	t_stream tok2;
	tok2.line = "batata";
	tok2.index = 0;
	t_token *token2 = token_word(&tok2);
	assert_string("batata", token2->text, "word text");
	assert_svalue(word, token2->type, "word type");
	assert_svalue(0, tok2.line[tok2.index], "word \\0 index");

	//free
	list_token_clear(&token1);
	list_token_clear(&token2);
}

void	token_create_and_destroy_tests()
{
	create_subtitle("token_create_and_destroy_tests");

	t_token *token_with_text = token_create("foo", word);
	if(token_with_text)
	{
		assert_string("foo", token_with_text->text,     "token_with_text (text)");
		assert_string("foo", token_with_text->text_aux, "token_with_text (text_aux)");
		token_destroy(token_with_text);
		assert_utils_print_ok("token_destroy (token_with_text)");
	}
	else
		assert_utils_die("t_token *token_with_text malloc error!!");

	t_token *token_without_text = token_create(NULL, word);
	if(token_without_text)
	{
		assert_string(NULL, token_without_text->text,     "token_without_text (text)");
		assert_string(NULL, token_without_text->text_aux, "token_without_text (text_aux)");
		token_destroy(token_without_text);
		assert_utils_print_ok("token_destroy (token_without_text)");
	}
	else
		assert_utils_die("t_token *token_with_text malloc error!!");
}

static void token_dup_test()
{
	create_subtitle("token_dup_test");

	t_token fake;
	fake.text     = "foo";
	fake.text_aux = "bar";
	fake.type     = word;

	t_token *dup = token_dup(&fake);
	if (dup)
	{
		assert_string(fake.text, dup->text, "text");
		assert_string(fake.text_aux, dup->text_aux, "text_aux");
		assert_svalue(fake.type, fake.type, "type");
	}
	else
		assert_utils_die("t_token *dup malloc error!!");
	list_token_clear(&dup);
}

//token_test.c
void token_test(int argc, char *argv[])
{
	if (argc != 1 && strcmp(argv[1], "token_test") != 0)
		return ;
	create_title("token_test");

	token_create_and_destroy_tests();
	token_dup_test();

	token_separator_test();
	token_redict_in_test();
	token_redict_out_test();
	token_pipe_test();
	token_expand_test();
	token_eol_test();
	token_dquote_test();
	token_squote_test();
	token_word_test();

}
