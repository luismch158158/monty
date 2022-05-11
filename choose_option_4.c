#include "monty.h"

/**
 * m_pstr - prints the string starting at the top of the stack + '\n'
 * @stack: address of doubly linked list
 * @line_number: line number
 */
void m_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	char str[1028];
	size_t i = 0;
	(void)line_number;

	if (!tmp)
		printf("\n");
	for (; tmp->next; tmp = tmp->next)
		;
	for (; tmp && tmp->n; tmp = tmp->prev, i++)
	{
		if (tmp->n < 0 || tmp->n > 126)
			break;
		str[i] = tmp->n;
	}
	str[i] = '\0';
	printf("%s\n", str);
}

/**
 * isint - checks if s could be converted to an decimal int
 * @s: sourcer string
 * Return: 0 on success, otherwise 1
 */
int isint(char *s)
{
	size_t i;

	if (!s)
		return (1);
	for (i = 0; s[i]; i++)
	{
		if ((s[i] < 48 || s[i] > 57) && (s[i] != '-'))
			return (1);
	}
	return (0);
}
