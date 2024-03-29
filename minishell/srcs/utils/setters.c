/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   setters.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pquintan <pquintan@student.42barcelona.	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/02/15 16:12:02 by pquintan		  #+#	#+#			 */
/*   Updated: 2024/03/26 14:15:49 by pquintan		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minishell.h"

char	*ft_after_set(char *str, char set)
{
	int		i;
	int		x;
	char	*dst;

	i = 0;
	x = 0;
	if (!str || !set)
		return (NULL);
	while (str[i] != '\0' && str[i] != set)
		i++;
	if (str[i] == '\0')
		return (ft_strdup(""));
	i++;
	dst = malloc(sizeof(char) * (ft_strlen(str + i) + 1));
	if (!dst)
		return (NULL);
	while (str[i] != '\0')
	{
		dst[x] = str[i];
		x++;
		i++;
	}
	dst[x] = '\0';
	return (dst);
}

char	*ft_before_set(char *str, char set)
{
	int		i;
	char	*dst;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != set)
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (dst == NULL)
		return (NULL);
	while (j < i)
	{
		dst[j] = str[j];
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
