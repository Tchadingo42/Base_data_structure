/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:48:28 by chbelan           #+#    #+#             */
/*   Updated: 2019/06/05 23:02:47 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
#define LIST_H
#include <stdio.h>
#include <stdlib.h>

typedef	enum
{
	false,
	true,
}					bool;

typedef	struct			s_list
{	
	int					value;
	struct	s_list		*next;
}						t_list;

t_list					*list_push_front(t_list *list, int x);
t_list					*list_push_back(t_list *list, int x);
t_list					*destack_list(t_list *list);
t_list					*new_list(void);
bool					list_is_empty(t_list *list);
int						list_size(t_list *list);
void					print_list(t_list *list);

#endif 
