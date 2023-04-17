#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1000
#endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;
