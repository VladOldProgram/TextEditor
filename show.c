/**
 * show.c -- реализует команду вывода хранимого текста и курсора на экран
 * 
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

static void show_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла и курсор на экран
 */
void show(text txt)
{
    /* Применяем функцию show_line к каждой строке текста */
    process_forward(txt, show_line, NULL);
}

/**
 * Выводит содержимое текущей строки указанного файла на экран
 */
static void show_line(int index, char *contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(data);

    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Выводим текущую строку с курсором на экран */
    if (cursor == -1)	
        printf("%s\n", contents);
    else {
	for (int i = 0; i < cursor; i++)
	    printf("%c", contents[i]);
        printf("|");
        unsigned int lenght = strlen(contents);
        for (int i = cursor; i < (int)lenght; i++)
	    printf("%c", contents[i]);
	printf("\n");
    }
}
