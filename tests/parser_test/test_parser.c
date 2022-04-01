/*
** EPITECH PROJECT, 2021
** test_parser
** File description:
** Test the parser
*/

#include "parser.h"
#include <stdlib.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include <fcntl.h>
#include <stdio.h>

Test(doesnt_exist, bad_file)
{
    char *str = read_file("er");
    cr_expect_eq(str, NULL);
}

Test(empty_file, bad_file)
{
    char *str = read_file("./tests/parser_test/read_file/empty.txt");
    cr_expect_eq(str, NULL);

}

Test(good_file, good_file)
{
    char *str = read_file("./tests/parser_test/read_file/good.txt");
    cr_expect_str_eq(str, "florian sketumet");
    free(str);
}

Test(object, test_type)
{
    char *str = "{\nlol\n";
    int type = check_type(str, 0);
    cr_expect_eq(type, object);
}

Test(string, test_type)
{
    char *str = "\"id\"\nlol\n";
    int type = check_type(str, 0);
    cr_assert_eq(type, string);
}

Test(int, test_type)
{
    char *str = "1234\nlol\n";
    int type = check_type(str, 0);
    cr_assert_eq(type, integer);
}

Test(arr, test_type)
{
    char *str = "[\nlol\n";
    int type = check_type(str, 0);
    cr_assert_eq(type, array);
}

Test(id, get_id)
{
    char *str = "\"id\":lol\n";
    int i = 0;
    char *compare = get_id(str, &i);
    cr_expect_str_eq(compare, "id");
}

Test(plusgrosid, get_id)
{
    json_t *parser = NULL;
    char *str = "\"plusgrosid\":lol\n";
    int i = 0;
    char *compare = get_id(str, &i);
    cr_expect_str_eq(compare, "plusgrosid");
}

Test(jetestle_id, get_id)
{
    char *str = "\"jetestle_id\":lol\n";
    int i = 0;
    char *compare = get_id(str, &i);
    cr_expect_str_eq(compare, "jetestle_id");
}

Test(bad_type, bad_type)
{
    char *str = "@\"nebur le bogosse\"";
    int i = 0;
    int type = check_type(str, 0);
    cr_expect_eq(type, -1);
}

Test(count_data, count_data)
{
    char *str = read_file("./tests/parser_test/read_file/second_test.json");
    int i = 0;
    int data = count_nbr_data(str, i);
    cr_expect_eq(data, 4);
}

Test(count_arr, count_data)
{
    char *str = read_file("./tests/parser_test/read_file/test.json");
    int i = 0;
    int data = count_nbr_data(str, i);
    cr_expect_eq(data, 7);
}

Test(count_arr2, count_data)
{
    char *str = read_file("./tests/parser_test/read_file/test.json");
    int i = 0;
    for (; str[i] != '['; i++);
    int data = count_nbr_data(str, i);
    cr_expect_eq(data, 3);
}

Test(get_arr, get_value_arr)
{
    char *str = read_file("./tests/parser_test/read_file/test.json");
    int i = 0;
    int type = 0;
    json_t *parser;

    for (; str[i] != '['; i++);
    type = check_type(str, i);
    parser = get_value(str, &i, type, "lol");
    cr_expect_eq(1234, ((json_t *)parser->data[0])->data[0]);
    cr_expect_eq(4543, ((json_t *)parser->data[1])->data[0]);
    cr_expect_eq(2340, ((json_t *)parser->data[2])->data[0]);
    for (int j = 0; parser->data[j]; j++)
        free(parser->data[j]);
    free(parser);
}

Test(get_int, get_value_int)
{
    char *str = read_file("./tests/parser_test/read_file/test.json");
    int i = 187;
    int type = 0;
    json_t *parser;

    type = check_type(str, i);
    parser = get_value(str, &i, type, "lol");
    cr_expect_eq(1235, ((json_t *)parser->data[0])->data[0]);
    free(parser->data[0]);
    free(parser);
}

Test(get_neg_int, get_value_int)
{
    char *str = read_file("./tests/parser_test/read_file/test.json");
    int i = 383;
    int type = 0;
    json_t *parser;

    type = check_type(str, i);
    parser = get_value(str, &i, type, "lol");
    cr_expect_eq(-3245, ((json_t *)parser->data[0])->data[0]);
    free(parser->data[0]);
    free(parser);
}

Test(get_string, get_value_int)
{
    char *str = read_file("./tests/parser_test/read_file/test.json");
    int i = 187;
    int type = 0;
    json_t *parser;

    for (; str[i] != ']'; i++);
    for (; str[i] != '\"'; i++);
    for (;str[i] != 'm'; i++);
    i--;
    type = check_type(str, i);
    parser = get_value(str, &i, type, "lol");
    cr_expect_str_eq
    ("my_strlen(florian)", ((json_t *)parser->data[0])->data[0]);
    free(parser->data[0]);
    free(parser);
}

Test(get_arr_string, get_value_arr)
{
    char *str = read_file("./tests/parser_test/read_file/test.json");
    int i = 0;
    int type = 0;
    json_t *parser;

    for (; str[i] != '['; i++);
    i++;
    for (; str[i] != '['; i++);
    type = check_type(str, i);
    parser = get_value(str, &i, type, "lol");
    cr_expect_str_eq("nebur", ((json_t *)parser->data[0])->data[0]);
    cr_expect_str_eq("niarolf", ((json_t *)parser->data[1])->data[0]);
    cr_expect_str_eq("tnecniv", ((json_t *)parser->data[2])->data[0]);
    for (int j = 0; parser->data[j]; j++)
        free(parser->data[j]);
    free(parser);
}

Test(get_obj_string, get_value_obj)
{
    char *str = read_file("./tests/parser_test/read_file/test.json");
    int i = 1;
    int type = 0;
    json_t *parser;

    for (; str[i] != '{'; i++);
    type = check_type(str, i);
    parser = get_value(str, &i, type, "lol");
    cr_expect_str_eq
        ("string", ((json_t *)((json_t *)parser->data[0])->data[0])->data[0]);
    cr_expect_str_eq
        ("objet", ((json_t *)((json_t *)parser->data[0])->data[0])->id);
    cr_expect_eq
        (123, ((json_t *)((json_t *)parser->data[1])->data[0])->data[0]);
    cr_expect_str_eq
        ("objet2", ((json_t *)((json_t *)parser->data[1])->data[0])->id);
    cr_expect_eq
        (6543, ((json_t *)((json_t *)parser->data[2])->data[0])->data[0]);
    cr_expect_str_eq
        ("objet3", ((json_t *)((json_t *)parser->data[2])->data[0])->id);
    for (int j = 0; parser->data[j]; j++) {
        free(((json_t *)((json_t *)parser->data[j])->data[0])->data);
        free(((json_t *)parser->data[j])->data[0]);
        free(((json_t *)parser->data[j])->id);
        free(((json_t *)parser->data[j])->data);
        free(parser->data[j]);
    }
    free(parser);
}

Test(get_obj_string_two, get_value_obj)
{
    char *str = read_file("./tests/parser_test/read_file/test.json");
    int i = 1;
    int type = 0;
    json_t *parser;

    for (; str[i] != '{'; i++);
    i++;
    for (; str[i] != '{'; i++);
    type = check_type(str, i);
    parser = get_value(str, &i, type, "lol");
    cr_expect_eq
        (1234, ((json_t *)((json_t *)parser->data[0])->data[0])->data[0]);
    cr_expect_str_eq
        ("posx", ((json_t *)((json_t *)parser->data[0])->data[0])->id);
    cr_expect_eq
        (456, ((json_t *)((json_t *)parser->data[1])->data[0])->data[0]);
    cr_expect_str_eq
        ("posy", ((json_t *)((json_t *)parser->data[1])->data[0])->id);
    for (int j = 0; parser->data[j]; j++) {
        free(((json_t *)((json_t *)parser->data[j])->data[0])->data);
        free(((json_t *)parser->data[j])->data[0]);
        free(((json_t *)parser->data[j])->id);
        free(((json_t *)parser->data[j])->data);
        free(parser->data[j]);
    }
    free(parser);
}
