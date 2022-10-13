#include <stdio.h>
#include <stdlib.h>

#include "failloc.h"

int main(void)
{
	char *alloc_checked = malloc(12);

	if (!alloc_checked)
		printf("`alloc_checked` alloc faild !\n");
	else
		alloc_checked[3] = 'e';

	char *alloc_not_checked = malloc(12);
	alloc_not_checked[3] = 'e';

	free(alloc_checked);
	free(alloc_not_checked);
	return (0);
}
