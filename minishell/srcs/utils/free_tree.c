/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaespino <aaespino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:26:14 by aaespino          #+#    #+#             */
/*   Updated: 2024/01/24 19:33:45 by aaespino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	free_tree(t_tree *root, void (*del)(void *))
{
	if (!root)
		return ;
	if (root->left || root->right)
	{
		free_tree(root->left, del);
		free_tree(root->right, del);
	}
	if (root)
	{
		(*del)(root->content);
		root->left = 0;
		root->right = 0;
		free(root);
		root = 0;
	}
}