/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 23:21:26 by chbelan           #+#    #+#             */
/*   Updated: 2019/06/06 23:23:38 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H_
#define DLIST_H_
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
	false,
	true
}						Bool;

typedef struct			DListNode
{
	int value;
	struct DListNode	*back;
	struct DListNode	*next;
}						DListNode;

typedef struct			DList
{
	int					length;
	struct DListNode	*begin;
	struct DListNode	*end;
}						*DList;

	DList new_dlist(void);
	Bool is_empty_dlist(DList list);
	int dlist_length(DList list);
	int dlist_first(DList list);
	int dlist_last(DList list);
	void print_dlist(DList list);
	DList push_back_dlist(DList list, int x);
	DList push_front_dlist(DList list, int x);
	DList pop_back_dlist(DList list);
	DList pop_front_dlist(DList list);
	DList clear_dlist(DList list);

#endif
