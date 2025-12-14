# PUSH SWAP

# GOAL
The goal is to sort random numbers in ascending order into stack_a with the minimum possible number of operations. 


### Glossary
	# stack
		stack structures with a little bit modifications
	# cost.
		the amount of operations to put the element in right position relative to current nodes.
	#

### My Algorithm

	1. Sort the numbers in descending orders on stack b.
	2. move those numbers back to stack a with pa(put a).

	1. how to sort the numbers in descending order in stack b?
		loop:
			put the next number to right position on stack b.

	2. move back to stack A


### finding biggest smaller

	// if there is no smaller than the value provided, return the biggest value.
	// if there is smaller node than provided value, return the biggest smaller.

## functions

