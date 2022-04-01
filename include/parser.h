/*
** EPITECH PROJECT, 2021
** parser
** File description:
** Parser headerfile
*/

#ifndef PARSER_H_
#define PARSER_H_

typedef struct json_s {
    char *id;
    int type;
    void **data;
}json_t;

typedef enum type_e {
    object,
    array,
    string,
    integer
}type_enum;

json_t *json_parser(char *filepath);
char *read_file(char *filepath);
int count_nbr_data(char *str, int i);
int check_type(char *str, int i);
char *get_id(char *str, int *i);
void *get_value(char *str, int *i, int type, char *id);
void parser_loop(json_t *parser, char *str, int *i, int nbr_data);
void print_json(json_t *parser);
void free_parser(json_t *parser);

#endif /* !PARSER_H_ */
