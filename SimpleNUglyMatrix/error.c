#include "matrix.h"
#include <stdbool.h>

void voidpointer(int* input_pointer, const char funcname[]) {
	if (!input_pointer)
		printf("The input pointer of %s is NULL!\n", funcname), assert(input_pointer);
	return;
}