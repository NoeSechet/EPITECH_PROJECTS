/*
** EPITECH PROJECT, 2020
** PSU_nmobjdump_2019
** File description:
** sort_symb_list
*/

#include <nm.h>

void swap_elem(symblist_t *el1, symblist_t *el2)
{
    symblist_t temp;
    temp.addr = el1->addr;
    temp.type = el1->type;
    temp.name = el1->name;
    temp.isUScore = el1->isUScore;

    el1->addr = el2->addr;
    el1->type = el2->type;
    el1->name = el2->name;
    el1->isUScore = el2->isUScore;

    el2->addr = temp.addr;
    el2->type = temp.type;
    el2->name = temp.name;
    el2->isUScore = temp.isUScore;
}

int check_diff_chr(char lowlet1, char lowlet2, char unformatchr1,
char unformatchr2)
{
    if (lowlet1 == lowlet2)
        if (unformatchr1 < unformatchr2)
            return -1;
        else
            return 0;
    else {
        if ((lowlet1 > lowlet2 && lowlet2 != '_') ||
        ((lowlet1 == '_' && lowlet2 != '_') && !isupper(unformatchr2)))
            return -1;
        else
            return 1;
    }
}

bool check_last_chr(symblist_t *elem1, symblist_t *elem2, char chr1, char chr2)
{
    if (chr1 == '\0' && chr2 == '\0' &&
    elem1->isUScore == false && elem2->isUScore == true)
        return false;
    if (chr1 != '\0' && chr2 == '\0') {
        return false;
    }
    return true;
}

bool check_word_order(symblist_t *elem1, char *str1, symblist_t *elem2,
char *str2)
{
    char lowlet1 = 0;
    char lowlet2 = 0;
    int i = 0;
    int ret = 0;

    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i += 1)
    {
        lowlet1 = tolower(str1[i]);
        lowlet2 = tolower(str2[i]);
        if (lowlet1 != lowlet2) {
            ret = check_diff_chr(lowlet1, lowlet2, str1[i], str2[i]);
            if (ret == 1) {
                return true;
            } else if (ret == -1)
                return false;
            else
                continue;
        }
    }
    return check_last_chr(elem1, elem2, str1[i], str2[i]);
}

void sort_symb_list(symblist_t *list)
{
    char *str1 = NULL;
    char *str2 = NULL;

    for (symblist_t *temp = list; temp->next != NULL;)
    {
        str1 = skip_uscore(temp);
        str2 = skip_uscore(temp->next);
        if (check_word_order(temp, str1, temp->next, str2) == false) {
            swap_elem(temp, temp->next);
            temp = list;
        } else {
            temp = temp->next;
        }
    }
}