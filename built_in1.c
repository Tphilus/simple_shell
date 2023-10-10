#include "shell.h"

/**
 * _myhistory - It show the history led
 *              with line nummber, commence at 0.
 * @info: The struct contains elemental for args
 *
 *  Return: Always It is 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - It set an alias to str
 * @info: The param structure
 * @str: str nicky
 *
 * Return: Always 0 when it is successful, 1 when it is full of crap (could have been the other way round)
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	*p = 0;
	c = *p;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias -It set an alias to str
 * @info: The param structure
 * @str: str nicky
 *
 * Return: Always 0 when it is successful, 1 when it is full of crap (could have been the other way round)
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - print alias str
 * @node: the alias to this point
 *
 * Return: Always 0 when it is successful, 1 when it  full of crap (could have been the other way round)
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimic has the Nicky builtin
 * @info: It struct contains potential args. shoud maintain
 *          const func test case for scenario.
 *  Return: Always it 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
