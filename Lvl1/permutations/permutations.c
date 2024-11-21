/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bendixschmidt <bendixschmidt@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:39:50 by bendixschmi       #+#    #+#             */
/*   Updated: 2024/11/21 02:28:23 by bendixschmi      ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

/* Task:
Task: Write a program that generates and prints all permutations of a given string in lexicographical order.
Input: A single string provided as a command-line argument.
Output: All permutations of the input string, printed one per line, in lexicographical order.

Example: abc
Output: abc, acb, bac, bca, cab, cba
*/

#include <stdio.h>

#include <stdio.h>

void	get_new_letter(char *str, int i, int j)
{
	char	tmp;

	while (j > i)
	{
		tmp = str[j];
		str[j] = str[j - 1];
		str[j - 1] = tmp;
		j--;
	}
}

void	put_letter_back(char *str, int i, int j)
{
	char	tmp;

	while (i < j)
	{
		tmp = str[i];
		str[i] = str[i + 1];
		str[i + 1] = tmp;
		i++;
	}
}

void	permute(char *str, int start, int end)
{
	int i = start;

	if (start == end)
		printf("result: %s\n", str);
	else
	{
		while (i <= end)
		{
			get_new_letter(str, start, i);
			permute(str, start + 1, end);
			put_letter_back(str, start, i);
			i++;
		}
	}
}

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int	find_min(char *str, int i)
{
	int min = i;

	while (str[i])
	{
		if (str[i] < str[min])
			min = i;
		i++;
	}
	return (min);
}

void	sort(char *str)
{
	int i = 0;

	while (str[i])
	{
		 int j = find_min(str, i);
		 get_new_letter(str, i, j);
		 i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int n = ft_strlen(argv[1]);
	sort(argv[1]);
	permute(argv[1], 0, n - 1);
	return (0);
}