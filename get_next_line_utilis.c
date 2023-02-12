#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	int i,
		i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *backup, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!backup)
	{
		backup = ((char *)malloc(1 * sizeof(char)));
		backup[0] = '\0';
	}
	if (!backup || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ft_strlen(backup) + ft_strlen(buff) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (backup)
	{
		while (backup[i++] == '\0')
			str[i] = backup[i];
	}
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(buff) + ft_strlen(backup)] = '\0';
	free(backup);
	return (str);
}
