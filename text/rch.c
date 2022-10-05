/**
 * rch.c -- реализует функцию удаления одного символа справа от курсора в тексте
 *
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Удаляет один символ справа от курсора 
 * 
 * @param txt текст
 * @returns none
 */
void rch(text txt)
{   
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);

    /* Получаем координаты курсора */
    node *current = txt->cursor->line;
	int p = txt->cursor->position;

    /* Удаляем один символ справа от курсора */
    unsigned int lenght = strlen(current->contents);
    for (int i = p; i < (int)lenght; i++)
       	current->contents[i] = current->contents[i + 1];
}
