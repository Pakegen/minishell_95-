static void	apply_redirections(t_command *cmd)
{
	int		i;
	int		j;
	char	**new_args;
	char	*op;
	char	*target;

	i = 0;
	j = 0;
	new_args = malloc(sizeof(char *) * (count_strings(cmd->args) + 1));
	if (new_args == NULL)
		exit(EXIT_FAILURE);
	while (cmd->args[i])
	{
		if (ft_strcmp(cmd->args[i], ">") == 0 ||
		    ft_strcmp(cmd->args[i], ">>") == 0 ||
		    ft_strcmp(cmd->args[i], "<") == 0)
		{
			op = cmd->args[i];
			if (cmd->args[i + 1] == NULL)
				break;
			target = cmd->args[i + 1];
			adv_handle_redirect(target, op,
				(ft_strcmp(op, "<") == 0) ? STDIN_FILENO : STDOUT_FILENO);
			i = i + 2;
		}
		else
		{
			new_args[j] = ft_strdup(cmd->args[i]);
			j = j + 1;
			i = i + 1;
		}
	}
	new_args[j] = NULL;
	free_2d_array(cmd->args);
	cmd->args = new_args;
}
