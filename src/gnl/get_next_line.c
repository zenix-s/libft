/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serferna <serferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:08:09 by serferna          #+#    #+#             */
/*   Updated: 2024/03/28 09:43:09 by serferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

#define BUFFER_SIZE 10

/**
 * @name get_line_leave_rest
 * This function divides the text into two parts,
	the first part is the text until the first '\n' character
 * and the second part is the rest of the text.
 * @param text Is a pointer to the text that will be divided,
	it will be modified to contain the rest of the text.
 * @return The first part of the text until the first '\n' character.
 */
static char	*extract_line(char **text)
{
	int		i;
	char	*line;
	char	*rest;

	i = 0;
	if (!(*text)[i])
		return (NULL);
	while ((*text)[i] != '\n' && (*text)[i] != '\0')
		i++;
	line = ft_substr(*text, 0, i + 1);
	if (line == NULL)
		return (free(*text), NULL);
	rest = ft_substr(*text, i + 1, ft_strlen(*text) - i);
	if (rest == NULL)
		return (free(line), free(*text), NULL);
	free(*text);
	*text = rest;
	return (line);
}

/**
 * @name read_file
 * This function reads the file and stores the text in a buffer.
 * @param fd File descriptor.
 * @param text The text previously read, and not returned due to being after '\n'.
 * @return The text read from the file that contains the first '\n' character, or the whole text if there is no '\n' EOF(End Of File).
*/
static char	*read_file(int fd, char *text)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes_read;

	bytes_read = 1;
	while (ft_strchr(text, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((bytes_read == 0 && !ft_strlen(text)) || bytes_read < 0)
			return (free(text), NULL);
		buffer[bytes_read] = '\0';
		tmp = text;
		text = ft_strjoin(text, buffer);
		if (text == NULL)
			return (free(tmp), NULL);
		free(tmp);
	}
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (text == NULL)
		text = ft_strdup("");
	if (text == NULL)
		return (NULL);
	text = read_file(fd, text);
	if (text == NULL)
		return (NULL);
	if (ft_strchr(text, '\n') == NULL)
	{
		line = ft_strdup(text);
		if (line == NULL)
			return (free(text), text = NULL, NULL);
		return (free(text), text = NULL, line);
	}
	return (extract_line(&text));
}