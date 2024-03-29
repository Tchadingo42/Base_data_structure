/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbelan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 19:51:44 by chbelan           #+#    #+#             */
/*   Updated: 2019/06/05 22:09:10 by chbelan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
#define FILE_H
#include <stdio.h>
#include <stdlib.h>

typedef	enum
{
	false,
	true,
}					bool;

typedef	struct		s_file
{
	int				data;
	struct	s_file	*next;
}					t_file;

static	t_file		*first = NULL;
static	t_file		*last = NULL;
static	int	nb_elem	= 0;

bool				file_is_empty(void);
#endif
