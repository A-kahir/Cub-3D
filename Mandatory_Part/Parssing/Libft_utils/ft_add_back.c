#include "../../parsing.h"

t_source	*ft_add_back(t_source *line, char *var, char *value)
{
	t_source	*new_node;
	t_source	*curr;

	new_node = malloc_cl(sizeof(t_source), 0);
	if (!new_node)
		return (line);
	new_node->var = ft_strdup(var, 0);
	if (value != NULL)
		new_node->value = ft_strdup(value, 0);
	else
		new_node->value = NULL;
	new_node->next = NULL;
	if (!line)
		return (new_node);
	curr = line;
	while (curr->next)
		curr = curr->next;
	curr->next = new_node;
	return (line);
}
