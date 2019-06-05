/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:12:06 by chbelan           #+#    #+#             */
/*   Updated: 2019/06/05 21:33:18 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
#define PILE_H
#include <stdio.h>
#include <stdlib.h>

typedef enum
{
		false,
		true
}							Bool;

typedef struct		QueueElement
{
		int					value;
		struct QueueElement *next;
}			QueueElement, *Queue;

	/* Paramètres de la File */
static QueueElement *first = NULL;
static QueueElement *last = NULL;
static int nb_elements = 0;

Bool is_empty_queue(void);
int queue_length(void);
int queue_first(void);
int queue_last(void);
void print_queue(void);
void push_queue(int x);
void pop_queue(void);
void clear_queue(void);

#endif
