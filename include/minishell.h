/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:55:25 by pingpanu          #+#    #+#             */
/*   Updated: 2023/04/09 22:40:20 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define _XOPEN_SOURCE 700
# include <stdio.h> //printf
# include "libft.h" //already have unistd.h and stdlib.h
# include <readline/readline.h> //readline, rl_*, and add_history
# include <readline/history.h> //readline, rl_*, and add_history
# include <fcntl.h> //open, unlink, dup, dup2,
# include <sys/types.h> //fork
# include <sys/wait.h> //wait, waitpid, wait3, wait4
# include <sys/stat.h> //stat, lstat, and fstat
# include <sys/ioctl.h> //ioctl
# include <signal.h> //signal, sigaction, sigemptyset, sigaddset, and kill
# include <dirent.h> //opendir, readdir, and closedir
# include <errno.h> //stderror, and perror
# include <term.h>
# include <termios.h> //tc*
# define BASH_IN 0
# define BASH_OPT 1
# define BASH_OUT 2

typedef struct s_system
{
	struct sigaction	act;
	struct sigaction	quit;
	struct termios		*myshell_term;
	char				**env_cop;
	char				**env_path;
	char				dis_str[500];
}		t_system;

typedef struct s_cmd_node
{
	char				**cmd_arr;
	struct s_cmd_node	*next;
}		t_cmd_node;

typedef struct s_cmd_table
{
	t_cmd_node	*cmds;
	char		*infile;
	char		*outfile;
}	t_cmd_table;

typedef struct s_executor
{
	pid_t	pid;
	int		node_ptr;
	int		nodesize;
	int		pipe_no;
	int		*pipe;
	int		in_fd;
	int		out_fd;
	int		old_stdin;
	int		old_stdout;
}		t_executor;

typedef struct s_data
{
	t_cmd_table		*cmd_table;
	char			*cmd_str;
	t_list			*cmd_ll;
	t_system		my_env;
}	t_data;

typedef struct s_stpar
{
	int	len;
	int	l;
	int	r;
	int	quote;
}	t_stpar;

void		sighandler(int signal);
void		exit_shell(t_data *data, int s);
char		*curr_dir(void);
void		lexer(t_data *data, t_stpar stpar);
void		free_token(void *content);
void		free_arr(char **arr);
void		free_cmdtable(t_data *data);
void		free_temp(t_list *temp);
t_cmd_table	*parser(t_list *cmd_ll);
char		**ll_to_strarr(t_list *cmd_ll);
t_list		*sub_linklist(t_list *left, t_list *right);
int			isredirection(t_list *ptr);
void		redirection_parse(t_list *ptr, t_cmd_table *cmd_table);
t_cmd_node	*newnode(t_list *temp);
void		node_addback(t_cmd_node **node, t_cmd_node *newn);
int			nodesize(t_cmd_node *cmds);
void		expander(t_list **cmd_ll);
int			executor(t_data *data);
int			exec(t_system *env, t_cmd_node *node);
void		signal_operator(t_system *my_env, int status);
int			single_executor(t_data *data, t_executor *exe);
int			pipe_executor(t_data *data, t_executor *exe);
void		dup_back(t_executor *exe);
void		init(t_data *data, char **ev);
void		init_terminal(t_system *env);
void		init_stpar(t_stpar *stpar);
void		init_exe(t_executor *exe, t_cmd_table *cmd_table);
void		write_hdoc(char *infile, t_executor *exe);
void		node_clear(t_cmd_node **node);
int			is_buildins(char *cmd);
int			buildins(t_data *data, t_executor *exe);
int			exe_cd(t_system *env, char *path);
int			exe_echo(t_executor *exe, t_cmd_node *node);
int			exe_env(t_system *env, t_cmd_node *node);
int			exe_pwd(t_cmd_node *node);
int			exe_unset(t_cmd_node *node, t_system *env);
int			exe_export(t_cmd_node *node, t_system *env);
#endif
