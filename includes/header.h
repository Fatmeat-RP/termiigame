#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_instance t_instance;
typedef struct s_binaries_tree t_binaries_tree;
typedef struct s_node t_node;

struct s_instance
{
	t_binaries_tree	*map;
	t_node			*here;
	char			*action;
};

struct s_binaries_tree
{
	t_node	*first;
	t_node	*iter;
};

struct s_node
{
	char	*elem;
	t_node	*prev;
	t_node	*left;
	t_node	*center;
	t_node	*right;
};

int			game_action(char *input, t_instance *game);
t_instance	*init_instance(void);
char		*render_prompt(t_instance *game);

#endif