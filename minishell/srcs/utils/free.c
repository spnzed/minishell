/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   free_environment.c								 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pquintan <pquintan@student.42barcelona.	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/26 18:47:13 by pquintan		  #+#	#+#			 */
/*   Updated: 2024/03/22 11:46:41 by pquintan		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

void free_array(char **array) 
{
	int		i;
	char	*str;

	if (array == NULL)
		return ;
	i = 0;
	while (array[i])
	{
		str = array[i];
		if (str)
			free(str);
		i++;
	}
	free(array);
}

void	free_environment(t_environment *env)
{
	t_environment *temp;

	while (env != NULL)
	{
		temp = env->next;
		if (env->signal != NULL)
		{
			free(env->signal);
			env->signal = NULL;
		}
		if (env->content != NULL)
		{
			free(env->content);
			env->content = NULL;
		}
		if (env->full_line != NULL)
		{
			free(env->full_line);
			env->full_line = NULL;
		}	
		free(env);
		env = temp;
	}
}

void	free_list(t_list *list)
{
	t_list *temp;

	while (list != NULL)
	{
		temp = list->next;
		if (list->content != NULL)
		{
			free(list->content);
			list->content = NULL;
		}
		free(list);
		list = temp;
	}
}

void free_info(t_info *info) 
{

	if (info->cmd_line)
		free(info->cmd_line);
	// if (info->cmd_clean)
	// 	free(info->cmd_clean);
	// if (info->home)
	// 	free(info->home);
	// if (info->str_trim)
	// 	free(info->str_trim);
	// if (info->root_path)
	// 	free(info->root_path);
	// if (info->from_file)
	// 	free(info->from_file);
	// if (info->string_infile)
	// 	free(info->string_infile);
	// if (info->string_outfile)
	// 	free(info->string_outfile);
	// if (info->string_overwrite)
	// 	free(info->string_overwrite);
	// if (info->string_heredoc)
	// 	free(info->string_heredoc);
	// if (info->string_append)
	// 	free(info->string_append);

	// free_array(info->env);
	// free_array(info->one_cmd);
	// free_array(info->mul_cmds);
	// free_array(info->split_line);
	// free_array(info->tab_var_env);
	// free_array(info->cmd_split);

	// free_list(info->list_env);
	// free_list(info->list_input);
	// free_list(info->list_path);
	// free_list(info->list_in_files);
	// free_list(info->list_out_files);
	// free_list(info->list_heredocs);

	// free_environment(info->signals_env);
	// free_environment(info->list_exp);
}

//	free_list(info->list_env);
//	free_environment(info->signals_env);
//	free_environment(info->list_exp);
//	free(info->root_path);
//	free_string_array(info->env);
//	free(info->home);