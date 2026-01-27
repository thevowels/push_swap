*This project has been created as part of the 42 curriculum by **aphyo-ht**.*

<div align="center">

# 🔄 Push Swap

[![42](https://img.shields.io/badge/42-Project-blue)](https://42.fr)
[![C](https://img.shields.io/badge/C-Language-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Algorithm](https://img.shields.io/badge/Algorithm-Sorting-green.svg)](https://en.wikipedia.org/wiki/Sorting_algorithm)
[![Data Structure](https://img.shields.io/badge/Data%20Structure-Linked%20List-orange.svg)](https://en.wikipedia.org/wiki/Linked_list)
[![Data Structure](https://img.shields.io/badge/Data%20Structure-Stacks-orange.svg)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

</div>

## Description
**PUSH_SWAP** is a project where we sort the stack with least moves as possible.

## Instructions

### Installation

```bash
# Clone the repository
git clone https://github.com/thevowels/push_swap.git

# Navigate to project directory
cd push_swap

# Compile the project
make
```

### Usage

```bash
# Run with random numbers
./push_swap 3 2 1 5 4

# Check the number of operations
./push_swap 1 5 3 2 4 | wc -l
```

---


## Resources

## Glossary

- **Stack**: Stack structures with a little bit of modifications
- **Cost**: The amount of operations to put the element in the right position relative to current nodes

## My Algorithm

The algorithm works in two main phases:

1. Sort the numbers in descending order on `stack_b`
2. Move those numbers back to `stack_a` with `pa` (push a)

### Phase 1: Sorting in Stack B

**Initial Setup:**
- At first, there are no nodes in `stack_b`
- Push the first two nodes from `stack_a` to `stack_b`

**Main Loop Process:**
1. For each remaining node in `stack_a`, calculate the cost (number of operations) to move it to the correct position in `stack_b`
2. Since we're sorting in descending order in `stack_b`, each node must be positioned:
   - **Above** the biggest value smaller than itself, OR
   - **Below** the smallest value bigger than itself
3. Calculate the cost for all nodes in `stack_a`
4. Execute the move with the least cost
5. Repeat until `stack_a` is empty

**Cost Calculation:**
The cost represents the total number of operations needed to:
- Rotate the target node to the top of `stack_a`
- Rotate `stack_b` to position the insertion point at the top
- Push the node from `stack_a` to `stack_b`

### Phase 2: Moving Back to Stack A

Move all numbers back to `stack_a` using the `pa` operation.

## Finding Biggest Smaller

The algorithm for finding the biggest smaller element:

- If there is no smaller value than the provided value, return the biggest value
- If there is a smaller node than the provided value, return the biggest smaller value

## Functions

<!-- Add function descriptions here -->

