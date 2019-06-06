/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 20:21:27 by chbelan           #+#    #+#             */
/*   Updated: 2019/06/06 23:24:11 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dlist.h"

DList		new_dlist(void)
{
	return NULL;
}

Bool		is_empty_dlist(DList list)
{
	if (list == NULL)
		return true;

	return false;
}
int			dlist_length(DList list)
{
	if (is_empty_dlist(list))
		return (0);

	return (list->length);
}

int			dlist_first(DList list)
{
	if (is_empty_dlist(list))
		exit(1);

	return (list->begin->value);
}

int			dlist_last(DList list)
{
	if (is_empty_dlist(list))
		exit(1);

	return (list->end->value);
}

void		print_dlist(DList list)
{
	if (is_empty_dlist(list))
	{
		printf("The link is empty.\n");
		return;
	}
	DListNode *tmp = list->begin;
	while (tmp != NULL)
	{
		printf("[%d] ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

DList		push_back_dlist(DList list, int x)
{
	DListNode *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "malloc fail\n");
		exit(EXIT_FAILURE);
	}
	element->value = x;
	element->next = NULL;
	element->back = NULL;
	if (is_empty_dlist(list))
	{
		list = malloc(sizeof(*list));

		if (list == NULL) 
		{
			fprintf(stderr, "malloc fail\n");
			exit(EXIT_FAILURE);
		}
		list->length = 0;
		list->begin = element;
		list->end = element;
	}
	else
	{
		list->end->next = element;
		element->back = list->end;
		list->end = element;
	}

	list->length++;
	return (list);
}

DList			push_front_dlist(DList list, int x)
{
	DListNode *element;

	element = malloc(sizeof(*element));

	if (element == NULL)
	{
		fprintf(stderr, "malloc fail\n");
		exit(EXIT_FAILURE);
	}
	element->value = x;
	element->next = NULL;
	element->back = NULL;
	if (is_empty_dlist(list))
	{
		list = malloc(sizeof(*list));
		if (list == NULL)
		{
			fprintf(stderr, "malloc fail\n");
			exit(EXIT_FAILURE);
		}
		list->length = 0;
		list->begin = element;
		list->end = element;
	}
	else
	{
		list->begin->back = element;
		element->next = list->begin;
		list->begin = element;
	}
	list->length++;
	return (list);
}

DList			pop_back_dlist(DList list)
{
	if (is_empty_dlist(list))
	{
		printf("The link is empty\n");
		return new_dlist();
	}
	if (list->begin == list->end)
	{
		free(list);
		list = NULL;
		return new_dlist();
	}
	DListNode *tmp = list->end;
	list->end = list->end->back;
	list->end->next = NULL;
	tmp->next = NULL;
	tmp->back = NULL;
	free(tmp);
	tmp = NULL;
	list->length--;
	return (list);
}

DList			pop_front_dlist(DList list)
{
	if (is_empty_dlist(list))
	{
		printf("The link is empty\n");
		return new_dlist();
	}

	if (list->begin == list->end)
	{
		free(list);
		list = NULL;
		return new_dlist();
	}

	DListNode *tmp = list->begin;
	list->begin = list->begin->next;
	list->begin->back = NULL;
	tmp->next = NULL;
	tmp->back = NULL;
	free(tmp);
	tmp = NULL;
	list->length--;
	return (list);
}

DList			clear_dlist(DList list)
{
	while (!is_empty_dlist(list))
		list = pop_back_dlist(list);
	return new_dlist();
}
