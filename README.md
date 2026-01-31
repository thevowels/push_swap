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

**PUSH_SWAP** is a sophisticated sorting algorithm project from the 42 curriculum that challenges you to sort a stack of integers using the minimum number of operations possible. The project implements a dual-stack sorting system with a limited set of operations, requiring efficient algorithmic thinking and optimization.

### Project Overview

The program takes a list of integers as input and sorts them using two stacks (A and B) with the following allowed operations:

- **sa/sb**: Swap the first two elements at the top of stack A or B
- **ss**: Swap the first two elements of both stacks simultaneously  
- **pa/pb**: Push the top element from one stack to another
- **ra/rb**: Rotate stack (move top element to bottom)
- **rr**: Rotate both stacks simultaneously
- **rra/rrb**: Reverse rotate stack (move bottom element to top)
- **rrr**: Reverse rotate both stacks simultaneously

### Algorithm Implementation

This implementation uses the **Turk Algorithm**, an optimized approach that:

1. **Initial Setup**: Keeps the smallest elements in stack A as a foundation
2. **Strategic Distribution**: Moves the majority of elements to stack B for processing
3. **Cost-Based Optimization**: Calculates the most efficient path to move each element back to stack A
4. **Final Positioning**: Ensures the final stack is properly sorted with minimal rotations

The algorithm excels at minimizing the total number of operations through intelligent cost analysis and simultaneous stack operations, making it highly efficient for the push_swap constraints.

### Key Features

- **Robust Input Validation**: Handles various input formats including quoted arguments
- **Error Management**: Comprehensive validation for duplicates, overflows, and invalid formats
- **Memory Safety**: Proper memory management with no leaks
- **Performance Optimization**: Consistently achieves near-optimal operation counts
- **Scalable Design**: Efficient performance across different input sizes

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

# Run with negative numbers
./push_swap 1 42 -23 4 83

# Run with quoted arguments (space-separated numbers in quotes)
./push_swap 1 "42 -23" 4 "83"

# Check the number of operations
./push_swap 1 5 3 2 4 | wc -l
```

## Input Handling

The push_swap program supports multiple input formats to provide flexibility in how you pass numbers to be sorted:

### Individual Arguments
```bash
./push_swap 1 42 -23 4 83
```
Each number is passed as a separate command-line argument. This is the most straightforward way to input numbers, where each space-separated value is treated as an individual integer.

### Quoted Space-Separated Arguments
```bash
./push_swap 1 "42 -23" 4 "83"
```
Numbers can be grouped within quotes, where space-separated values inside the quotes are parsed as individual integers. In this example:
- `1` is parsed as a single number
- `"42 -23"` is parsed as two numbers: `42` and `-23`
- `4` is parsed as a single number  
- `"83"` is parsed as a single number

This format is useful when you need to group numbers or when working with shell scripts that might generate space-separated number strings.

### Mixed Format Support
The program can handle a combination of both formats in the same command, giving you maximum flexibility in how you structure your input based on your specific needs.

### Input Validation
The program includes robust input validation that:
- Checks for valid integer format
- Handles negative numbers correctly
- Detects duplicate values
- Validates integer overflow/underflow
- Ensures all arguments are properly formatted numbers

#### Safe Integer Parsing (`ft_safe_atoi_ps`)
The program uses a custom safe integer parsing function that provides comprehensive validation:

**Features:**
- **Overflow/Underflow Protection**: Validates that numbers are within `INT_MIN` (-2147483648) to `INT_MAX` (2147483647) range
- **Leading Whitespace Handling**: Automatically skips leading spaces and tabs
- **Sign Support**: Properly handles both positive (`+`) and negative (`-`) signs
- **Trailing Character Detection**: Rejects strings with non-digit characters after the number (e.g., "123abc" is invalid)
- **Invalid Sign Handling**: Rejects malformed signs like "- 123" (space after sign)
- **Leading Zeros**: Correctly processes numbers with leading zeros like "00042" → 42

**Return Values:**
- Returns `0` on successful parsing with the integer value stored in the provided pointer
- Returns `-1` on any parsing error (invalid format, overflow, trailing characters, etc.)

**Examples of Valid Input:**
- `"123"` → 123
- `"-456"` → -456  
- `"  789"` → 789 (leading spaces ignored)
- `"+42"` → 42
- `"00042"` → 42 (leading zeros handled)
- `"2147483647"` → 2147483647 (INT_MAX)
- `"-2147483648"` → -2147483648 (INT_MIN)

**Examples of Invalid Input:**
- `"123abc"` → Error (trailing characters)
- `"2147483648"` → Error (overflow)
- `"-2147483649"` → Error (underflow)
- `"- 123"` → Error (space after sign)
- `"abc"` → Error (non-numeric)

---

## Resources

### Algorithm Theory & Implementation
- **[Push Swap Turk Algorithm Explained](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0)** - Comprehensive guide to the Turk algorithm implementation
- **[Sorting Algorithms Visualization](https://visualgo.net/en/sorting)** - Interactive visualization of various sorting algorithms
- **[Stack Data Structure](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))** - Understanding the fundamental data structure

### Testing & Debugging Tools
- **[Push Swap Visualizer by o-reo](https://github.com/o-reo/push_swap_visualizer)** - Visual representation of your sorting algorithm
- **[Push Swap Tester by gemartin99](https://github.com/gemartin99/Push-Swap-Tester)** - Comprehensive testing suite for validation
- **[Push Swap Tester by LeoFu9487](https://github.com/LeoFu9487/push_swap_tester)** - Alternative testing framework with performance metrics


### Development Tools
- **[Valgrind](https://valgrind.org/)** - Memory leak detection and debugging
- **[GDB Tutorial](https://www.gdbtutorial.com/)** - GNU Debugger for C programs
- **[Makefile Tutorial](https://makefiletutorial.com/)** - Understanding Makefiles for C projects

### Algorithm Analysis
- **[Big O Notation Guide](https://www.bigocheatsheet.com/)** - Time and space complexity reference
- **[Algorithm Complexity Calculator](https://www.calculator.net/big-o-calculator.html)** - Tools for analyzing algorithm performance
- **[Sorting Algorithm Comparisons](https://www.toptal.com/developers/sorting-algorithms)** - Interactive comparison of sorting methods

## Glossary

- **Stack**: Stack structures with a little bit of modifications
- **Cost**: The amount of operations to put the element in the right position relative to current nodes
```
while (stack_a->count > 2)
    push_command(stack_a, stack_b, "pb");
```
This creates a foundation in stack A and moves the bulk of numbers to stack B for processing.

#### Phase 3: Optimized Return to Stack A (`move_back`) - **Core Algorithm**

This is where the sophisticated cost calculation happens:

##### Target Position Finding
For each element in stack B, the algorithm finds the correct insertion position in stack A:
- **Primary Strategy**: Find the smallest element in stack A that's larger than the current element
- **Fallback Strategy**: If no larger element exists, target the smallest element in stack A (wrap-around case)

##### Cost Calculation System
The algorithm calculates **four different movement strategies** for positioning each element:

1. **Same Up** (`same_up`): Both stacks rotate upward using `rr`
   - Cost = `max(a_up_rotations, b_up_rotations)`

2. **Same Down** (`same_down`): Both stacks rotate downward using `rrr`
   - Cost = `max(a_down_rotations, b_down_rotations)`

3. **Mix 1** (`mix_1`): Stack A rotates up, Stack B rotates down
   - Cost = `a_up_rotations + b_down_rotations`

4. **Mix 2** (`mix_2`): Stack A rotates down, Stack B rotates up
   - Cost = `a_down_rotations + b_up_rotations`

##### Cheapest Move Selection
- **Global Analysis**: The algorithm examines every element in stack B
- **Cost Comparison**: Calculates all four movement costs for each element
- **Optimal Choice**: Selects the element requiring the minimum total operations
- **Execution**: Performs the chosen movement strategy and pushes the element to stack A

##### Movement Optimization
The algorithm maximizes efficiency by:
- **Simultaneous Operations**: Uses combined rotations (`rr`, `rrr`) when both stacks rotate in the same direction
- **Smart Direction Choice**: Always chooses the shorter rotation path (up vs down)
- **Minimal Operations**: Reduces total command count through strategic movement combinations

#### Phase 4: Final Positioning
After all elements return to stack A:
1. **Find Minimum**: Locates the smallest element in the stack
2. **Optimal Rotation**: Rotates the stack to position the smallest element at the top
3. **Efficient Direction**: Uses the shorter rotation path (forward or reverse)

### Key Algorithm Features

#### 1. Greedy Optimization
At each step, the algorithm makes the globally optimal choice among all possible moves, not just locally optimal decisions.

#### 2. Cost-Benefit Analysis
Every potential move is evaluated for its total operational cost, ensuring the most efficient sorting path.

#### 3. Dual-Stack Coordination
The algorithm intelligently coordinates movements between both stacks to minimize the total number of operations.

#### 4. Adaptive Strategy
The cost calculation adapts to the current state of both stacks, always finding the most efficient positioning strategy.

### Algorithm Complexity
- **Time Complexity**: O(n²) - calculates costs for all elements in stack B for each iteration
- **Space Complexity**: O(n) - uses two stacks to store all elements
- **Operation Count**: Highly optimized for push_swap constraints, consistently produces near-optimal results

### Why This Algorithm Excels
1. **Minimizes Operations**: Comprehensive cost analysis ensures the fewest total operations
2. **Handles All Cases**: Robust target finding handles both normal insertion and edge cases
3. **Scalable Performance**: Efficient for both small and large input sizes
4. **Strategic Movement**: Simultaneous operations significantly reduce command count

