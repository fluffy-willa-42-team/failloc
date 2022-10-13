#ifndef FAILLOC_H
# define FAILLOC_H

# include <stdio.h>
# include <stdlib.h>

static inline void	*failloc(int size, const char *f, const char *func, int l)
{
	char prompt = '\0';

	while (prompt != 'y' && prompt != 'n')
	{
		printf ("Make fail this malloc(%d) %s/%s:%d\n  ? [y/n] : ",
			size, f, func, l);
		prompt = getchar();
		getchar();
	}
	if (prompt == 'y')
		return NULL;
	return malloc(size);
}


# ifdef malloc
#  undef malloc
# endif

# define malloc(x) failloc(x, __FILE__, __FUNCTION__, __LINE__)

#endif