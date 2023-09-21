#include "monty.h"


/**
 *liner - Frees lineptr buffer malloc'd by getline
 *@lineptr: Pointer to the buffer containing the string
 *
 * Return: length of token
 */
size_t liner(char **lineptr)
{
	if (lineptr && *lineptr == 0)
	{
		free(lineptr);
		fprintf(stderr, "Error: malloc failed\n");
		return (EXIT_FAILURE);
	}

	free(lineptr);
	return (EXIT_SUCCESS);
}


/**
 *tok_len - Finds the length the token
 *
 * Return: length of token
 */
unsigned int tok_len(void)
{
	unsigned int len = 0;

	while (tok[len] != NULL)
		len++;

	return (len);
}


/**
 *find_opcodeFX - Finds the function associated with the opcode
 *@opcode: A token containing the opcode
 *
 * Return: Void
 */
void (*find_opcodeFX(char *opcode))(stack_t**, unsigned int)
{
	int i = 0;
	int is_opcode;
	instruction_t opcodeFXs[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{NULL, NULL}
	};

	while (opcodeFXs[i].opcode != NULL)
	{
		is_opcode = strcmp(opcode, opcodeFXs[i].opcode);
		
		if (is_opcode)
			return(opcodeFXs[i].f);
		i++;
	}

	return (NULL);
}

/**
 *tok_free - Frees Tokens
 *
 * Return: Void
 */
void tok_free(void)
{
	int i = 0;

	if (tok != NULL)
	{
		while (tok[i] != NULL)
		{
			free(tok[i]);
			i++;
		}

		free(tok);
	}
}

