# PUSH SWAP

# free.c

## functions 

### ft_free

	void	ft_free(int *unordered, int *sorted, char *sms)
	This function accept three parameters, unordered, sorted and sms.
	unordered:	int pointer
	sorted: int pointer
	sms: the message for the error 

	what it does, free the unordered and sorted array
	show error message and exit the program.

###	free_matrix
	void free_matrix(char **matrix, int size)
	It accepts two parameters, char arr pointer matrix and int size.
	it iterates through the whole matrix and free the matrix.
	Important thing.
	We have 2 dimensional matrix, which is double pointer.
	but we've to iterate only once as for the char pointer, its continuous memory so
	we free each row and all values on this row is automatically freed as its a continuous memory.
	After freeing the row, we also have to set the pointer to point to the null as it will be pointing to the memory we just freed.
	after that, we free the double pointer.

###	free_and_exit
	We just free the matrix using free_matrix funciton and exit with error message.

### free_list_and_exit
	we free the linked list  and exit with error_message.

### free_stacks_and_arrays
	we free the stack_a and stack_b.
	we free the int arrays.


# bubble_sort.c

## functions 