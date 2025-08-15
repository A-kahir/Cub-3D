

#include "../parsing.h"

static void	free_leaks_list(t_leaks **head)
{
	t_leaks	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->ptr);
		free(tmp);
	}
}

static void	*ft_cantinue(size_t size, t_leaks **head)
{
	void		*ptr;
	t_leaks		*new_node;

	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	new_node = malloc(sizeof(t_leaks));
	if (!new_node)
	{
		free(ptr);
		return (NULL);
	}
	new_node->ptr = ptr;
	new_node->next = *head;
	*head = new_node;
	return (ptr);
}

void *malloc_cl(size_t size, t_mal *mode)
{
	static t_leaks *node = NULL;

	if (mode == 1)
	{
		free_leaks_list(&node);
		return (NULL,)
	}
	return (ft_allocate(size, &node));
}