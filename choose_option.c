#include "monty.h"


/**
 * m_push - function that pusher an element to the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	stack_t *tmp = *stack;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		freell(stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(head->cmd[1]);
	if (!(new_node->n) && ((*(head->cmd[1]) != '0') ||
			       (strlen(head->cmd[1]) != 1)))
	{
		dprintf(STDERR_FILENO, "L%d: usage: push integer\n", line_number);
		freell(stack);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	new_node->next = NULL;

	if (!(*stack))
	{
		new_node->prev = *stack;
		*stack = new_node;
		return;
	}

	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new_node;
	new_node->prev = tmp;
}

/**
 * m_pall - Function that print all values on the stack
 * starting from the top of the stack
 *
 * @stack: address of double linked list
 * @line_number: number of line
 *
 */

void m_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (tmp == NULL)
		return;
	while (tmp->next != NULL)
		tmp = tmp->next;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}

/**
 * execute_ops - Function to execute options
 *
 * @stack: address of double linked list
 *
 */

void execute_ops(stack_t **stack)
{
	int i = 0;

	instruction_t options[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", mega_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"nop", m_nop},
		{"sub", m_sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{NULL, NULL}
	};

	while (options[i].opcode)
	{
		if (!strcmp(options[i].opcode, head->cmd[0]))
		{
			(*options[i].f)(stack, head->line_number);
			break;
		}
		i++;
	}
	if (!options[i].opcode)
	{
		dprintf(STDERR_FILENO, "L%d: unknown instruction <opcode>\n",
				head->line_number);
		freell(stack);
		_exit(EXIT_FAILURE);
	}

}

/**
 * freell - Function free all linked list
 *
 * @stack: address of double linked list
 *
 */

void freell(stack_t **stack)
{
	stack_t *tmp = NULL;
	cmds *tmp2 = NULL;

	for (; *stack; *stack = (*stack)->next, free(tmp))
		tmp = *stack;
	for (; head; head = head->next, free(tmp2))
	{
		tmp2 = head;
		free(head->cmd[1]);
		free(head->cmd[0]);
	}
}
