/**
 * cn.c -- реализует функцию помещения текущей строки после следующей
 *
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Помещает текущую строку после следующей 
 * 
 * @param txt текст
 * @returns none
 */
void cn(text txt)
{   
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

    /* Получаем и сохраняем текущую строку */
    node *current = txt->cursor->line;
    char t[MAXLINE + 1];
    unsigned int lenght = strlen(current->contents);
    for (int i = 0; i <= (int)lenght; i++)
	t[i] = current->contents[i];

    /* Получаем следующую строку */
    node *next = current->next;
    /* Проверяем, существует ли следующая строка */
    if (next == NULL) {
	fprintf(stderr, "There is no next line in the text!\n");
    return;
    }

    /* Помещаем текущую строку после следующей */
    strcpy(current->contents, next->contents);
    strcpy(next->contents, t);

    /* Устанавливаем курсор в следующей строке в той же позиции p */
    txt->cursor->line = current->next; 
}
