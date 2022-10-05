/**
 * save.c -- реализует команду сохранения содержимого файла
 * 
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "common.h"
#include "text/text.h"

static void save_line(int index, char *contents, int cursor, void *data);

/**
 * Сохраняет содержимое загруженного файла в файле, заданный параметром
 */
void save(text txt, char *filename)
{
    FILE *f;

    /* Открываем файл для записи, контролируя ошибки */
    if ((f = fopen(filename, "w")) == NULL) {
        printf("The file %s cannot be opened\n", filename);
        return;
    }
    
    /* Применяем функцию save_line к каждой строке текста */
    process_forward(txt, save_line, (void *)f);

	/* Закрываем файл */
	fclose(f);
}

/**
 * Сохраняет содержимое текущей строки загруженного файла в файле, заданном параметром
 */
static void save_line(int index, char *contents, int cursor, void *data)
{
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);

    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Сохраняем текущую строку в файл */
	fprintf((FILE *)data, "%s\n", contents);
}
