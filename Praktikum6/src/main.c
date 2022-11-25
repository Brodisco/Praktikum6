/*
 * main.c
 *
 *  Created on: 25.11.2022
 *      Author: oszi
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char boolean;
#define SUCCESS 1
#define FAIL 0


struct Element
{
	char wort[64];
	struct Element *next;
};
typedef struct Element Element;

struct List
{
	struct Element *head;
	int leangh;
};
typedef struct List List;

void printElement(const Element *element)
{
	printf("Wort: %s \n", element->wort);
}

void printListHead(const List *list)
{
	Element *element = list->head;

	while(element != NULL)
	{
		printElement(element);
		element = element->next;
	}
}

void printListTail(const List *list)
{
	Element *element = list->head;

	int listLeangh = list->leangh;

	while (listLeangh > 0)
	{
		int count = 0;

		element = list->head;

		while (++count < listLeangh && element != NULL)
		{
			element = element->next;
		}

		printElement(element);

		listLeangh--;
	}
}

Element *createElement(char wort[64])
{
	Element *element = (Element*) malloc(sizeof(Element));

	if (element == NULL)
	{
		return NULL;
	} else {
		element->next = NULL;
		strcpy(element->wort, wort);
		return element;
	}
}

List *createList()
{
	List *list = (List*) malloc(sizeof(List));

	if (list == NULL)
	{
		return NULL;
	} else {
		list->head = NULL;
		list->leangh = 0;
		return list;
	}
}

boolean PushElementHead(Element *element, List *list)
{
	if (element == NULL || list == NULL)
	{
		return FAIL;
	} else {
		element->next = list->head;
		list->head = element;
		list->leangh++;
		return SUCCESS;
	}
}



int main(void)
{
	List *list = createList();
	PushElementHead(createElement("Hallo"), list);
	PushElementHead(createElement("Alihan"), list);
	PushElementHead(createElement("wie"), list);
	PushElementHead(createElement("geht"), list);
	PushElementHead(createElement("es"), list);
	PushElementHead(createElement("dir"), list);
	PushElementHead(createElement("?"), list);
	PushElementHead(createElement(" "), list);
	PushElementHead(createElement("Mir"), list);
	PushElementHead(createElement("geht"), list);
	PushElementHead(createElement("es"), list);
	PushElementHead(createElement("gut"), list);
	//printElement(list->head);
	printListTail(list);

	return EXIT_SUCCESS;
}
