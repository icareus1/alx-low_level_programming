#include "shell.h"
/**
 * handle_signal - Signal handler for the shell.
 * @sig_num: The signal number.
 */
void handle_signal(int sig_num)
{
	printf("\n%d\n", sig_num);
	exit(1);
}
