/**
 * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255

/**
 * Абстрактный тип текстовых объектов
 */
typedef struct _list *text;

/**
 * Абстрактный тип курсора
 */
typedef struct _crsr *cursor;


/**
 * Создает новый текстовый объект
 * @returns текст
 */
text create_text();

/**
 * Добавляет одну строку к тексту
 * @param txt текст
 * @param contents новая строка
 * @returns none
 */
void append_line(text txt, const char *contents);


/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);

/**
 * Перемещает курсор в заданную позицию в тексте
 * 
 * @param txt текст
 * @param l строка
 * @param p позиция
 * @returns none
 */
void m(text txt, int l, int p);

/**
 * Удаляет один символ справа от курсора 
 *
 * @param txt текст
 * @returns none
 */
void rch(text txt);
    
/**
 * Помещает текущую строку после следующей 
 *
 * @param txt текст
 * @returns none
 */
void cn(text txt);

/**
 * Удаляет весь текст
 * 
 * @param txt текст
 * @returns none
 */
void remove_all(text txt);

#endif
