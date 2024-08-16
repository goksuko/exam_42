/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_list_size.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/11 22:44:40 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/11 22:44:42 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list != NULL)
	{
		i++;
		begin_list = begin_list->next;
	}
	return (i);
}

// Assignment name  : ft_list_size
// Expected files   : ft_list_size.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that returns the number of elements in the linked list that is
// passed to it.

// It must be declared as follows:

// int	ft_list_size(t_list *begin_list);

// You must use the following structure in your program ft_list_size.c :

// typedef struct    s_list
// {
//     struct s_list *next;
//     void          *data;
// }                 t_list;
