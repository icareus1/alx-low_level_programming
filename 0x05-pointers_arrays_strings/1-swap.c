#include "main.h"
/**
 * swap_int - swap integer values
 * @a: first integer
 * @b: second integer
 * */
void swap_int(int *a, int *b)
{
	int temp;
	temp = *b;
	*b = *a;
	*a = temp;
}
