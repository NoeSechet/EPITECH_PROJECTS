/*
** EPITECH PROJECT, 2019
** utils
** File description:
** utils
*/

#ifndef UTILS_H_
#define UTILS_H_

#include "op.h"
#include "lib.h"

// ENUM
enum {
    false,
    true
};

// UTILS
int my_strlen(char const *str);
int str_ncomp(char *str1, char *str2, int length);
char *strcopy(char *str);
char **special_str_tab(char *str, char c);
char **fill_line(char *str, int word);
int count_word(char *str);
void free_array(char **array);
char *strcopy_spe(char *str, char s);
void swap_endian(void *obj, size_t size); // DEPEND OF "lib.h"
char **str_to_word_array(char *str, char c);
char *str_clean(char *str, char c, int bool);
char *cat(char *str_1, char *str_2);
char *strcopy_pos(char *str, int begin);
int char_in_str(char *str, char c);

// VECTOR
typedef struct vector_s {
    int alloc;
    int nb_element;
    void **array;
} vector_t;

vector_t *vector_new(int n);
void vector_pop(vector_t *vector, int i);
void *vector_get(vector_t *vector, int pos);
void vector_push(vector_t *vector, void *element);
void vector_realloc(vector_t *vector);
void vector_free(vector_t *vector);

// PROGRAM

typedef struct data_s {
    int pos;
    int line;
    vector_t *V_FILE;
    vector_t *V_LABEL;
    header_t header;
    int IS_NAME;
    int IS_COM;
} data_t;

void display_usage(void);
data_t *get_data(char *path, data_t *D);

int is_label(char *line);
int is_instruction(char *arg, int *byte);
int is_label_chars(char c);
int get_byte(char *arg, int dvalue);
void get_header(char **line, char *buffer, data_t *D);
void get_label(data_t *D, char **buffer, int *byte);
char *format_line(char *buffer, int *byte);
int get_nb_str_array(char **array);
void check_error(char **array, data_t *data, int *byte);

#endif /* !UTILS_H_ */