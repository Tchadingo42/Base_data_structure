/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:16:47 by chbelan           #+#    #+#             */
/*   Updated: 2019/06/05 21:38:52 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int			main(void)
{
	printf("the file size -> %d\n", queue_length());
	print_queue();
	push_queue(27);
	printf("the file size -> %d\n", queue_length());
	pop_queue();
	return (0);
}

Bool		is_empty_queue(void)
{
	if (first == NULL && last == NULL)
		return (true);
	return (false);
}

int			queue_length(void)
{
	return (nb_elements);
}

int			queue_first(void)
{
	if (is_empty_queue())
		exit(1);
	return (first->value);
}

int			queue_last(void)
{
	if (is_empty_queue())
		exit(1);
	return (last->value);
}

void		print_queue(void)
{
	if (is_empty_queue())
	{
		printf("Rien a afficher, la File est vide.\n");
		return;
	}
	QueueElement *tmp = first;
	while (tmp != NULL)
	{
		printf("[%d] ", tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

void			push_queue(int x)
{
	QueueElement *element;

	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}
	element->value = x;
	element->next = NULL;
	if (is_empty_queue())
	{
		first = element;
		last = element;
	}
	else
	{
		last->next = element;
		last = element;
	}

	nb_elements++;
}

void			pop_queue(void)
{
	if (is_empty_queue())
	{
		printf("Rien a retirer, la File est deja vide.\n");
		return;
	}
	QueueElement *tmp = first;
	if (first == last)
	{
		first = NULL;
		last = NULL;
	}
	else
		first = first->next;

	free (tmp);
	nb_elements--;
}

void		clear_queue(void)
{
	if (is_empty_queue())
	{
		printf("Rien a nettoyer, la File est deja vide.\n");
		return;
	}

	while (!is_empty_queue())
		pop_queue();
}
