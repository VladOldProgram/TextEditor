/**
 * m.c -- реализует функцию перемещения курсора в заданную позицию в тексте
 *
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

/**
 * Перемещает курсор в заданную позицию в тексте
 * 
 * @param txt текст
 * @param l строка
 * @param p позиция
 * @returns none
 */
void m(text txt, int l, int p)
{   
    /* Проверяем, являются ли полученные параметры положительными числами */
	if (l < 0 || p < 0) {
        fprintf(stderr, "Arguments should be non-negative!\n");
        return;
    } 

    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    } 
    
    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Стартуем с начальной строки текста */
    node *current = txt->begin;
    int index = 0;

    /* К каждой строке текста применяем обработчик */
    while (current) {
		if (index == l)
	    	break;
    	current = current->next;
		index++;
    }
	
    /* Проверяем, существует ли заданная строка */
    if (current == NULL) {
		fprintf(stderr, "There is no such line %d in the text!\n", l);
    	return;
    } 

    /* Проверяем, существует ли заданная позиция в строке */
    if (p > (int)strlen(current->contents)) {
		fprintf(stderr, "There is no such position %d in the %d line!\n", p, l);
    	return;
    } 

    /* Устанавливаем курсор в строке l в позицию p */
    txt->cursor->line = current;
    txt->cursor->position = p;
}
