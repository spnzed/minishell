// int x = 0;
// if (ft_strcmp(split_cmd[0], "grep") == 0)
// {
// 	while(temp)
// 	{
// 		if (strcmp_len(temp->signal, split_cmd[1], ft_strlen(split_cmd[1])) == 0)
// 		{
// 			if (ft_strlen(temp->content) > 0)
// 			{
// 				while (temp->content[x])
// 				{
// 					if (ft_strchr(temp->content, ' '))
// 					{
// 						printf("declare -x %s=", temp->signal);
// 						printf("\"");
// 						while (temp->content[x] != ' ' && temp->content[x])
// 							printf("%c", temp->content[x++]);
// 						printf("\"");
// 						x++;
// 						printf("\ndeclare -x %s=", ft_after_set(ft_before_set(temp->content, '='), ' '));
// 						printf("\"");
// 						while(temp->content[x] != '=')
// 							x++;
// 						x++;
// 						while (temp->content[x])
// 							printf("%c", temp->content[x++]);
// 						printf("\"\n");
// 					}
// 					else
// 						printf("declare -x %s=\"%s\"\n", temp->signal, temp->content);
// 					break ;
// 				}
// 			}
// 			else
// 				printf("declare -x %s\n", temp->signal);
// 		}
// 		temp = temp->next;
// 	}
// 	return (0);
// }
else 