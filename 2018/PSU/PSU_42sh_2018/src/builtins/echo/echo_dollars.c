/*
** EPITECH PROJECT, 2019
** echo
** File description:
** echo
*/

#include "mysh.h"
#include "lib.h"
#include "struct_list.h"
#include "env_loc.h"

int echo_loop_env_loc(main_list_t *list, char *command, int n)
{
    for (int i = 0;  i < list->env_loc->nb_elem; i++) {
        if (strcmp(command,
        ((env_loc_t *)list->env_loc->array[i])->var) == 0) {
            if (((env_loc_t *)list->env_loc->array[i])->val != NULL)
                my_printf("%s", ((env_loc_t *)list->env_loc->array[i])->val);
            n == true ? my_printf(" ") : 0;
            return (0);
        }
    }
    free(command);
    return (0);
}

int echo_loop_env(main_list_t *list, char *command, int n)
{
    char **array = NULL;

    for (elem_t *tmp = list->env.start; tmp != NULL; tmp = tmp->next) {
        array = my_str_to_word_array(tmp->data, '=');
        if (strcmp(array[0], command) == 0) {
            my_printf("%s", array[1]);
            free(command);
            free_tabs(array);
            n == true ? my_printf(" ") : 0;
            return (0);
            break;
        }
    }
    return (1);
}

int echo_command(char *command, main_list_t *list, int n)
{
    if (strcmp(command, "?") == 0) {
        my_printf("%d", list->value_return);
        n == true ? my_printf(" ") : 0;
        free(command);
        return (0);
    } else if (strcmp(command, "$") == 0) {
        my_printf("%d", (int)getpid());
        n == true ? my_printf(" ") : 0;
        free(command);
        return (0);
    }
    return (1);
}

int echo_dollars(char *str, main_list_t *list, int n)
{
    char *command = strcopy_pos(str, 1);

    if (echo_command(command, list, n) == 0)
        return (0);
    if (echo_loop_env(list, command, n) == 0)
        return (0);
    if (echo_loop_env_loc(list, command, n) == 0)
        return (0);
    return (1);
}