/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:33:36 by prochell          #+#    #+#             */
/*   Updated: 2021/07/29 12:33:38 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*chk_reminder(char **reminder, char **line)
{
	char	*tmp_chr;

	tmp_chr = NULL;
	if (*reminder)
	{
		tmp_chr = ft_strchr(*reminder, '\n');
		if (tmp_chr)
		{
			*tmp_chr = '\0';
			*line = ft_strdup(*reminder);
			ft_strcpy(*reminder, ++tmp_chr);
			return (tmp_chr);
		}
		else
		{
			*line = ft_strdup(*reminder);
			free(*reminder);
			*reminder = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (tmp_chr);
}

int	chk_rules(char **buf, int fd, char **line)
{
	if (!line || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (-1);
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	return (1);
}

void	get_tmp_chr(char **tmp_chr, char **reminder)
{
	**tmp_chr = '\0';
	(*tmp_chr)++;
	*reminder = ft_strdup(*tmp_chr);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			rdd_bts;
	char		*tmp_chr;
	static char	*reminder;
	char		*tmp;

	rdd_bts = chk_rules(&buf, fd, line);
	if (rdd_bts < 0)
		return (-1);
	tmp_chr = chk_reminder(&reminder, line);
	while (!tmp_chr && rdd_bts > 0)
	{
		rdd_bts = read(fd, buf, BUFFER_SIZE);
		buf[rdd_bts] = '\0';
		tmp_chr = ft_strchr(buf, '\n');
		if (tmp_chr)
			get_tmp_chr(&tmp_chr, &reminder);
		tmp = *line;
		*line = ft_strjoin(*line, buf);
		free(tmp);
	}
	free(buf);
	return (rdd_bts && reminder);
}
