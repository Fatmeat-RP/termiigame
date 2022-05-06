
#include <header.h>

int main(int ac, char **av, char **envp)
{
	char *input;
	t_instance *game;

	game = init_instance();
	while(1)
	{
		input = render_prompt(game);
		if (input == NULL)
		{
			printf("\ncome play again soon !!! bye bye\n");
			return (0);
		}
		game_action(input, game);
//		render_game();
		usleep(100);
	}
	return (0);
}

int game_action(char *input, t_instance *game)
{
	printf("%s\n", input);
	if (strncmp("1", input, 1) == 0)
	{
		game->action = strdup("\n==> Going Back on my step");
//		game->here = game->map->iter->prev;
	}
	else if (strncmp("2", input, 1) == 0)
	{
		game->action = strdup("\n==> Going on the left path, seems pretty secure");
//		game->here = game->map->iter->left;
	}
	else if (strncmp("3", input, 1) == 0)
	{
		game->action = strdup("\n==> Going front, got no time to change path");
//		game->here = game->map->iter->center;
	}
	else if (strncmp("4", input, 1) == 0)
	{
		game->action = strdup("\n==> Going on the right, not the easiest but the path of the brave");
//		game->here = game->map->iter->right;
	}
	else
		game->action = strdup("\n==> Your action seems to have no success");
	return (0);
}

t_instance	*init_instance(void)
{
	t_instance *game;

	game = malloc(sizeof(t_instance *));
	if (!game)
		return (NULL);
	game->map = NULL;
	game->here = NULL;
	game->action = strdup("\n==> Welcome to the maze");
	return (game);
}

char	*render_prompt(t_instance *game)
{
	printf("\033c%s\n", game->action);
	printf("\n[1] : go back"
		"\n[2] : go on the left path"
		"\n[3] : go in front of me"
		"\n[4] : go on the right path\n");
	return (readline("\n[ACTION] :"));
}

int render_game()
{
	printf("walking boy here");
	return (0);
}