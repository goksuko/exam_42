/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   search_insert.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/09 13:17:17 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/08/09 13:17:20 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int searchInsert(int *nums, int numsSize, int target)
{
	int i;

	i = 0;
	while (target > nums[i] && i < numsSize - 1)
	{
		// printf("i: %d, nums[%d]: %d\n", i , i , nums[i]);
		i++;
	}
	if (i == numsSize - 1 && target > nums[i])
		i += 1;
	return (i);
}

// int main()
// {
// 	int nums[] = {1,3,5,6};

// 	searchInsert(nums, 4, 5);
// 	return 0;
// }