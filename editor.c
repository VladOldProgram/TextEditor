/**
 * editor.c -- строковый текстовый редактор, 15 вариант
 * 
 * Copyright (c) 2021, Vladislav Shkut <shkut@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
	char cmdline[MAXLINE + 1];
	char *cmd;
	char *arg1, *arg2;
	int l, p;

	/* Создаем объект для представления текста */
	text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL)
            continue;

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg1 = strtok(NULL, " \n")) == NULL)
                fprintf(stderr, "Usage: load filename\n");
	    else
                load(txt, arg1);
            continue;
        }

        /* Сохраняем содержимое загруженного файла в файл, заданный параметром */
        if (strcmp(cmd, "save") == 0) {
            if ((arg1 = strtok(NULL, " \n")) == NULL)
                fprintf(stderr, "Usage: save filename\n"); 
      	    else
                save(txt, arg1);
            continue;
        }

        /* Выводим текст с курсором на экран */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }
	
        /* Выводим количество пробелов в строках */
        if (strcmp(cmd, "shownumspaces") == 0) {
            shownumspaces(txt);
            continue;
        }

		/* Удаляем один символ справа от курсора */
        if (strcmp(cmd, "rch") == 0) {
            rch(txt);
            continue;
        }

		/* Помещаем текущую строку после следующей */
        if (strcmp(cmd, "cn") == 0) {
            cn(txt);
            continue;
        }

        /* Перемещаем курсор в тексте на строку l и позицию p */
        if (strcmp(cmd, "m") == 0) {
            if ((arg1 = strtok(NULL, " \n")) == NULL)
                fprintf(stderr, "Usage: m line position\n");
	    else {
			if ((arg2 = strtok(NULL, " \n")) == NULL)
		    	fprintf(stderr, "Usage: m line position\n");
			else {
		    	if (sscanf(arg1, "%d", &l) > 0 && sscanf(arg2, "%d", &p) > 0)
					m(txt, l, p);
		    	else
					fprintf(stderr, "m arguments should be integers\n");
		    }
	    }
            continue;
        }
	
        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
