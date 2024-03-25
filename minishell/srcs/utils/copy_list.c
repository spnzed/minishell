/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   copy_list.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pquintan <pquintan@student.42barcelona.	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/14 19:11:39 by pquintan		  #+#	#+#			 */
/*   Updated: 2024/02/14 19:16:05 by pquintan		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

t_list	*ft_copy_list(const t_list *src)
{
	t_list	*head;
	t_list	*current_dest;

	head = malloc(sizeof(t_list));
	current_dest = head;
	if (!src)
		return (NULL);
	if (!head)
		return (NULL);
	while (src)
	{
		current_dest->content = src->content;
		src = src->next;
		if (src)
		{
			current_dest->next = malloc(sizeof(t_list));
			if (!current_dest->next)
			{
				free_list(head);
				return (NULL);
			}
			current_dest = current_dest->next;
		}
		else
		{
			current_dest->next = (NULL);
		}
	}
	return (head);
}
