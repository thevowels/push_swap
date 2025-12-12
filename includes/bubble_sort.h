#ifndef BUBBLE_SORT_H
# define BUBBLE_SORT_H

# include <stdbool.h>

void	bubble_sort(int *arr, int size);
int		*copy_into_sorted(int *arr, int size);
bool	is_sorted(int *unordered, int size);
int		*get_nums(int nums_count, char **argv);

#endif   /* BUBBLE_SORT_H */
