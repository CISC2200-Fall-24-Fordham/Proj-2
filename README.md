# CISC 2200 SE2 Project - Part II

This is part 2 of the SE2 project. This part of the project focuses on parsing infix expressions and converting them to postfix expressions, as well as computing results based on the postfix expressions.

## Provided code

From your terminal (mac or WSL/Ubunto) window, you can use the following command to download the repo:

```
git clone https://github.com/CISC2200-Fall-24-Fordham/Proj-2.git
```

## Programming Environment Setup

If you haven't done so already, please set up programming environment our our own computer, by following [Setup Tutorial](https://eecs280staff.github.io/tutorials/).

- The _Commannd Line Tools_ are required.

- The _C++ Dev Environment_ (VSCode) is highly recommened.

**Please follow these tutorials closely and carefully.**

## Requirements

Implement the methods outlined with `TODO` markings in the code comments.

You will submit the following files to the autograder:

- `BigInt.cpp`
- `Calculator.cpp`
- `Transformer.cpp`

## Hints

- [Reverse Polish Notation Wikipedia](https://en.wikipedia.org/wiki/Reverse_Polish_notation)
- [Infix-to-postfix Online Tool](https://www.web4college.com/converters/infix-to-postfix-prefix.php)

## Workflows

New to this project, there are a few different ways to build / test your code:

1. While viewing the relevant file, you can use the `magic button` to compile and run your code.
2. You can use the `make all` composite makefile command to compile and run your code.
3. You can add your own workflows to the Makefile / add tests as required
4. Run you calculator from the command line `make clean; make main.out; ./main.out`

## Style

The coding style part is worth 20 points. The rubrics for the style requirement is as follows:

- Insufficient or no comments: -1 point (-2 max)
- Code not indented correctly: -1 point (-2 max)
- Redundant code: -1 point (-2 max)
- Overly complicated code: -1 point (-2 max)

### `make check`

In your `Makefile`, I have added support for `make check` which helps give you friendly suggestions.

Feel free to ignore them, however I find that these suggestions help simplify and clarify my code, so I suggest you run this as you are developing as well.

## Submission

The Autograder will be setup shortly.
