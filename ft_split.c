/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdenk <bdenk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 15:28:13 by bdenk             #+#    #+#             */
/*   Updated: 2025/01/08 14:45:57 by bdenk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strings(const char *str, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (*str == c)
			in_word = 0;
		str++;
	}
	return (count);
}

static	void	skip_delimiter(const char **str, char c)
{
	while (**str == c)
		(*str)++;
}

static	size_t	extract_word_len(const char *str, char c)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static void	*ft_free(char **strings)
{
	int	i;

	i = 0;
	while (strings[i])
		free(strings[i++]);
	free(strings);
	return (NULL);
}

char	**ft_split(const char *str, char c)
{
	char	**result;
	int		i;
	int		j;
	int		word_count;
	size_t	word_len;

	i = 0;
	j = 0;
	word_count = count_strings(str, c);
	result = (char **)ft_calloc(word_count + 1, sizeof(char *));
	if (!result)
		return (NULL);
	while (j < word_count)
	{
		skip_delimiter(&str, c);
		word_len = extract_word_len(str, c);
		result[j] = ft_substr(str, 0, word_len);
		if (!result[j])
			return (ft_free(result));
		str += word_len;
		j++;
	}
	return (result);
}
