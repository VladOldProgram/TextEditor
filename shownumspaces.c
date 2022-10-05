/**
 * shownumspaces.c -- реализует команду подсчета количества пробелов каждой строки в прямой их последовательности
 * 
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void show_number(int index, char *contents, int cursor, void *data);

/**
 * Выводит количество пробелов в строках загруженного текста на экран
 */
void shownumspaces(text txt)
{
    /* Применяем функцию show_number к каждой строке текста */
    process_forward(txt, show_number, NULL);
}

/**
 * Выводит количество пробелов текущей строки
 */
static void show_number(int index, char *contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);

    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);

    /* Подсчитываем количество пробелов в текущей строке */
    int k = 0;
    unsigned int lenght = strlen(contents);
    for (unsigned int i = 0; i < lenght; i++) {
	if(isspace(contents[i]))
	    k++;
    }
    
    /* Выводим количество пробелов в текущей строке */
    printf("Количество пробелов в строке: %d\n", k);
}
