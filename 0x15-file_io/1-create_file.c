#include "main.h"
/**
 * create_file - creates a file & write a string in it
 * @filename: name of the file to create
 * @text_content: string to be written to the file
 * Return: 1 if successful,if not -1
 */
int create_file(const char *filename, char *text_content)
{
	int fi, wr, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
		while (text_content[length])
			length++;

	fi = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fi == -1)
		return (-1);

	wr = write(fi, text_content, length);
	if (wr == -1)
	{
		close(fi);
		return (-1);
	}

	close(fi);
	return (1);
}

