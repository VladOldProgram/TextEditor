/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла и курсор на экран
 */
void show(text txt);

/**
 * Выводит количество пробелов в строках загруженного текста на экран
 */
void shownumspaces(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

/**
 * Сохраняет содержимое загруженного файла в файле, заданный параметром
 */
void save(text txt, char *filename);

#endif
