/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:48:10 by chbelan           #+#    #+#             */
/*   Updated: 2019/06/05 23:02:31 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

int				main(void)
{
	t_list		*list;

	list = new_list();

	if (list_is_empty(list))
		printf("the list is empty\n");
	else
		printf("the list have elements\n");
	printf("the size of the list is %d\n", list_size(list));
	print_list(list);
	list = list_push_front(list, 27);
	print_list(list);
	return (0);
}

t_list			*new_list(void)
{
	return (NULL);
}

bool			list_is_empty(t_list *list)
{
	if (list == NULL)
		return (true);
	return (false);
}

int				list_size(t_list *list)
{
	int			size;

	size = 0;
	if (!list_is_empty(list))
		while (list != NULL)
		{
			size += 1;
			list = list->next;
		}
	return (size);
}

void			print_list(t_list *list)
{
	if (list_is_empty(list))
	{
		printf("the list is empty\n");
		return ;
	}
	while (list != NULL)
	{
		printf("->[%d]", list->value);
		list = list->next;
	}
	printf("\n");
}

t_list			*list_push_back(t_list *list, int x)
{
	t_list		*element;
	t_list		*tmp;

	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		fprintf(stderr," malloc fail\n");
		exit(-1);
	}
	element->value = x;
	element->next = NULL;
	if (list_is_empty(list))
		return (element);
	 tmp = list;
	 while (tmp->next != NULL)
	 {
		 tmp = tmp->next;
		 tmp->next = element;
	 }
	 return (list);
}

t_list			*list_push_front(t_list *list, int x)
{
	t_list		*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		fprintf(stderr, "malloc fail \n");
		exit(-1);
	}
	element->value = x;
	if (list_is_empty(list))
		element->next = NULL;
	else
		element->next = list;
	return (element);
}

t_list				*destack_list(t_list *list)
{
	t_list			*tmp;
	t_list			*before;

	if (list_is_empty(list))
		return (new_list());
	if (list->next == NULL)
	{
		free(list);
		list = NULL;
		return (new_list());
	}
	while (tmp->next != NULL)
	{
		before = tmp;
		tmp = tmp->next;
	}
	before->next = NULL;
	free(tmp);
	tmp = NULL;
	return (list);
}
