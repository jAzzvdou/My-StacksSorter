#include "push_swap_bonus.h"

char	*free_function(char *wardrobe, char *buffer)
{
	char	*temp;

	temp = my_strjoin(wardrobe, buffer);
	free(wardrobe);
	return (temp);
}

char	*cutter(char *wardrobe)
{
	char	*single;
	int		end;

	end = 0;
	while (wardrobe[end] && wardrobe[end] != '\n')
		end++;
	if (wardrobe[end] == '\n')
		end++;
	single = malloc(end + 1);
	if (!single)
		return (NULL);
	single[end] = '\0';
	while (end--)
		single[end] = wardrobe[end];
	if (single[0] == '\0')
	{
		free(single);
		return (NULL);
	}
	return (single);
}

char	*remover(char *wardrobe)
{
	char	*new_wardrobe;
	int		end;

	end = 0;
	while (wardrobe[end] && wardrobe[end] != '\n')
		end++;
	if (wardrobe[end] == '\n')
		end++;
	if (wardrobe[end] == '\0')
	{
		free(wardrobe);
		return (NULL);
	}
	new_wardrobe = my_strdup(wardrobe + end);
	free(wardrobe);
	return (new_wardrobe);
}

char	*get_next_line(int fd)
{
	static char	*wardrobe;
	char		*buffer;
	char		*single;
	int			bytes;

	bytes = 1;
	buffer = malloc(sizeof(char) * (10 + 1));
	if (!buffer)
		return (NULL);
	while (bytes > 0 && (!wardrobe || !my_strchr(wardrobe, '\n')))
	{
		bytes = read(fd, buffer, 10);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		wardrobe = free_function(wardrobe, buffer);
	}
	free(buffer);
	single = cutter(wardrobe);
	wardrobe = remover(wardrobe);
	return (single);
}
