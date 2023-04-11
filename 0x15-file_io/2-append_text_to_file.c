#include "main.h"
/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file
 * @text_content: string to be written to the file
 * Return: 1 if successful,if not -1
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fi, wr, length = 0;

	if (filename == NULL)
		return (-1);

	if (text_content)
		while (text_content[length])
			length++;

	fi = open(filename, O_WRONLY | O_APPEND);
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

