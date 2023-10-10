#include "shell.h"

/**
 * _myenv -  It print moment env
 * @info: The struct contains elemental args. Must Maintain
 *          const func test case scenario.
 * Return: Forever 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - It gets the env value
 * @info: The structure contains potential arguments. Maintain
 * @name: envy the name
 *
 * Return: value/num of environment variable
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - It initialize new environment
 *             or modify for current nigga
 * @info: struct contains elemental args. Maintain
 *        const funct for test case scenario.
 *  Return: Forever 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - It remove envy container
 * @info: Struct containing elemental args. Should be Maintain
 *        const func test for case scenario.
 *  Return: Forever it 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - It populates envious linked list data structure
 * @info: Struct contains elemental args. Must be Maintain
 *        const func test for case scenario.
 * Return: Always it 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
