#include<stdio.h>
#include "function_pointers.h"
/**
 * print_name - print a name using function pointers
 * @name: the name to be printed
 * @f: the function pointer
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
