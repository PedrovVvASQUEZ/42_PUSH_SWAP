# push_swap

A C algorithm project based on 42's **push_swap** assignment. The program sorts a sequence of integers using two stacks and outputs a limited set of operations, aiming to minimize the number of moves.

## How it works

Values are stored in two stacks, **A** and **B**, represented by doubly linked lists. The program first moves some of the values to B, then reinserts them into A in the correct order. For each insertion, it finds a target position, estimates the cost of the required rotations, and chooses the least expensive move. Rotations shared by both stacks are combined whenever possible. Small input sizes are handled separately, and the minimum value is then moved to the top of A.

The program writes a list of instructions to standard output. Already-sorted input requires no instructions.

## Build

Build the project with `make`:

```sh
make
```

This builds `push_swap` and the local C library `pedro_lib/pedro_lib.a`. The bonus checker is built separately:

```sh
make bonus
```

Available cleanup commands: `make clean`, `make fclean`, and `make re`.

## Usage

Pass the integers as a single, space-separated argument:

```sh
./push_swap "4 67 3 0 -1"
```

To verify the operation sequence with the bonus program:

```sh
ARG="4 67 3 0 -1"
./push_swap "$ARG" | ./checker "$ARG"
```

The checker reads operations from standard input and prints `OK` if A is sorted in ascending order and B is empty; otherwise, it prints `KO`. An unknown instruction produces `Error`.

## Available operations

| Instruction | Effect |
| --- | --- |
| `sa`, `sb`, `ss` | Swap the first two elements of A, B, or both stacks. |
| `pa`, `pb` | Move the top element from one stack to the other. |
| `ra`, `rb`, `rr` | Rotate A, B, or both stacks upward. |
| `rra`, `rrb`, `rrr` | Rotate A, B, or both stacks downward. |

Operations without a combined suffix affect a single stack; `ss`, `rr`, and `rrr` apply the operation to both stacks.

## Input and errors

Arguments must be integers representable by the `int` type, with no duplicates. Invalid input (a non-numeric value, duplicate, or out-of-range value) prints `Error`.

## Repository structure

- The C files in the repository root contain the sorting program, argument parsing, stack operations, and reinsertion logic.
- `push_swap_bonus/` contains the `checker` program and its operations for applying the received instructions.
- `pedro_lib/` contains the project's C library, including string and I/O functions and `get_next_line`.

## Technologies

- C
- Make
- Project library in `pedro_lib/`