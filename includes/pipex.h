#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include<fcntl.h>
# include "../libft/libft.h"

void	error_message(void);
void	execute(char *argv, char **env);

#endif