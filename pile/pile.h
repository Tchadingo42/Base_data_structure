/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:12:36 by chbelan           #+#    #+#             */
/*   Updated: 2019/06/05 19:52:40 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PILE_H
#define PILE_H
#include <stdio.h>
#include <stdlib.h>

typedef	enum	
{	
	false,
	true,
}					bool;

typedef	struct		s_pile
{	
	int				data;
	struct	s_pile	*next;
}					t_pile;

t_pile				*new_pile(void);
t_pile				*push_in_pile(t_pile *pile, int x);
t_pile				*clear_pile(t_pile *pile);
t_pile				*destack(t_pile *pile);
bool				pile_is_empty(t_pile *pile);
void				print_pile(t_pile *pile);
int					top_pile(t_pile *pile);
int					pile_len(t_pile *len);

#endif
