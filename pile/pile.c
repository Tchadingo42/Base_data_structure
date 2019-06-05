/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:48:40 by chbelan           #+#    #+#             */
/*   Updated: 2019/06/05 19:42:42 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int				main(void)
{
	t_pile		*pile;

	pile = new_pile();
	if (pile_is_empty(pile) == true)
	{
		printf("the pile is empty\n");
	}
	pile = push_in_pile(pile, 27);
	pile = push_in_pile(pile, 32);
	pile = push_in_pile(pile, 74);
	printf("the size of the pile is ->%d \n", pile_len(pile));
	print_pile(pile);
	if (pile_is_empty(pile) == false)
	{
		printf("the pile is not empty\n");
	}
	pile = destack(pile);
	print_pile(pile);
	pile = clear_pile(pile);
	if (pile_is_empty(pile) == true)
	{
		printf("the pile empty again\n");
	}
	return (0);
}

t_pile			*new_pile(void)
{
	return (NULL);
}

bool			pile_is_empty(t_pile *pile)
{
	if (pile == NULL)
		return (true);
	return (false);
}

t_pile			*push_in_pile(t_pile *pile, int x)
{
	t_pile		*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
	{
		fprintf(stderr, "malloc element have fail\n");
		exit(-1);
	}
	element->data = x;
	element->next = pile;
	return (element);
}

t_pile			*clear_pile(t_pile *pile)
{
	while (!pile_is_empty(pile))
	{
		pile = destack(pile);
	}
	return (new_pile());
}

void			print_pile(t_pile *pile)
{
	if (pile_is_empty(pile))
	{
		printf("the stack is empty\n");
		return ;
	}
	while (!pile_is_empty(pile))
	{
		printf("[%d]->", pile->data);
		pile = pile->next;
	}
}

t_pile			*destack(t_pile *pile)
{
	t_pile		*element;

	if (pile_is_empty(pile))
	{
		return (0);
	}

	element = pile->next;
	free(element);
	return (element);
}

int				top_pile(t_pile *pile)
{
	while (!pile_is_empty(pile))
		pile = destack(pile);
	return (0);
}

int				pile_len(t_pile *pile)
{
	int		len;

	len = 0;
	while (!pile_is_empty(pile))
	{
		len += 1;
		pile = pile->next;
	}
	return (len);
}
