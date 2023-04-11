#include "main.h"
/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: text file to be read
 * @letters: number of letters to be read
 * Return: the actual number of letters it could read and print, 0 if failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t fi, wr, re;
	char *buffer;

	fi = open(filename, O_RDONLY);
	if (fi == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	re = read(fi, buffer, letters);
	wr = write(STDOUT_FILENO, buffer, re);

	free(buffer);
	close(fi);
	return (wr);
}


