/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialee <ialee@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:36:24 by ialee             #+#    #+#             */
/*   Updated: 2024/11/19 16:56:31 by ialee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Helper function used to create a new string where
/// 'scratch' is appended to theadress that 'loaded_buffer'
/// points to and 'loaded_buffer' moves to point to the new
/// string.
static void	*ft_joinswap(char **loaded_buffer, char *scratch)
{
	char	*swap_temp;

	if (!*loaded_buffer)
	{
		*loaded_buffer = (char *)malloc(1 * sizeof(char));
		if (!*loaded_buffer)
			return (NULL);
		**loaded_buffer = '\0';
	}
	swap_temp = ft_strjoin(*loaded_buffer, scratch);
	if (!swap_temp)
		return (NULL);
	free(*loaded_buffer);
	*loaded_buffer = swap_temp;
	return (*loaded_buffer);
}

/// Buffer Load.
/// This function calls the `read` system call and loads
/// the values of the FD into a `scratch` temporary region until
/// the call to `read` encounters a '\n' or EOF or returns 0.
/// The values in the scratch region is then pointed at by the `loaded_buffer`.
static char	*ft_bufload(int fd, char **loaded_buffer)
{
	char	*scratch;
	int		read_count;

	scratch = (char *)malloc(BUFFER_SIZE + 1);
	if (!scratch)
		return (NULL);
	while (1)
	{
		read_count = read(fd, scratch, BUFFER_SIZE);
		if (read_count < 0)
		{
			free(scratch);
			return (NULL);
		}
		if (read_count == 0)
			break ;
		scratch[read_count] = '\0';
		if (!ft_joinswap(&*loaded_buffer, scratch))
			return (NULL);
		if (ft_strchrnl(*loaded_buffer) || read_count < BUFFER_SIZE)
			break ;
	}
	free(scratch);
	return (*loaded_buffer);
}

/// Buffer Adjust.
/// This function assists in adjusting the static buffer if partial-reads
/// have occured.
/// If there is no newline, that means the entire
/// buffer was returned, we can safely assume that there is no 
/// need to adjust buffer and simply free the buffer.
static int	ft_bufadj(char **loaded_buffer)
{
	int		buf_index;
	char	*temp_buffer;
	char	*nl_addr;

	nl_addr = ft_strchrnl(*loaded_buffer);
	if (!nl_addr++)
		return (0);
	if (ft_strlen(nl_addr) == 0)
		return (0);
	temp_buffer = (char *)malloc(ft_strlen(nl_addr) + 1);
	if (!temp_buffer)
		return (0);
	buf_index = 0;
	while (*nl_addr)
		temp_buffer[buf_index++] = *nl_addr++;
	temp_buffer[buf_index] = '\0';
	free(*loaded_buffer);
	*loaded_buffer = temp_buffer;
	return (1);
}

/// RETURN(s):
/// `char *` - The next 'line' (up to the '\n' character) read-able from a FD.
/// (If EOF is met, the line is returned without a '\n').
/// `NULL` - If memory allocation fails or 
/// the FD has been read and returned EOF.
char	*get_next_line(int fd)
{
	char				*result;
	char				*buf_temp;
	static char			*buffer[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf_temp = ft_bufload(fd, &buffer[fd]);
	if (!buf_temp)
		return (NULL);
	result = ft_strtonl(buf_temp);
	if (!result)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	if (!ft_bufadj(&buffer[fd]))
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (result);
}
