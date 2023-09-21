#include "monty.h"

/**
 * is_delim - checks for delimiter
 *
 * @ch: character in stream
 *
 * @delims: Pointer to null terminated array of delimitors
 *
 *Return: 1 (success) 0 (failure)
 */
int _isDelim(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}

	return (0);
}


/**
 * get_wl - gets the word length of cur word in str
 *
 * @str: string to get word length from current word
 * @delims: delimitors to use to delimit words
 *
 * Return: word length of current word
 */
int get_wl(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (_isDelim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && _isDelim(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}


/**
 * get_wc - gets the word count of a string
 *
 * @str: string to get word count from
 * @delims: delimitors to use to delimit words
 *
 * Return: the word count of the string
 */
int get_wc(char *str, char *delims)
{
	int word_c = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (_isDelim(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			word_c++;
		}
		i++;
	}
	return (word_c);
}


/**
 * get_nw - gets the next word in a string
 *
 * @str: string to get next word from
 * @delims: delimitors to use to delimit words
 *
 * Return: pointer to first char of next word
 */
char *get_nw(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	while (*(str + i))
	{
		if (_isDelim(str[i], delims))
			pending = 1;
		else if (pending)
			break;
		i++;
	}
	return (str + i);
}
