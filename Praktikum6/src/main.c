/*
 * main.c
 *
 *  Created on: 25.11.2022
 *      Author: oszi
 */

#include <stdio.h>
#include <stdlib.h>


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
	printf("element->next: %x \n", element->next);
	printf("\n");
}

Element *createElement()
{
	Element *element = (Element*) malloc(sizeof(Element));

	if (element == NULL)
	{
		return NULL;
	} else {
		element->next = NULL;
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
		return list;
	}
}

int main(void)
{
	printf("Hello Alihan! \n");

	return EXIT_SUCCESS;
}
