Mini-project 1
============

**Due: Sep. 11, 2020 by 11:59 PM US Central Time**.

This is an introductory project to help you get comfortable with various tools we'll be using throughout the semester, including CMake, make, gcc, objdump, and strace. A small program is provided for you in main.c. You're going to compile, run, disassemble, and examine the system calls this program makes.

To build and run this program, do the following.

1. Create a build directory: `mkdir build`
2. Go to the build directory: `cd build`
3. Generate the build files by running CMake: `cmake ..`. The `..` tells CMake to look for a CMakeLists.txt file in the parent directory.
4. Generate the executable by running make: `make`
5. Run the program: `./main`

## Tasks

* Have a file named `report.md`.
* Use the strace command (`strace ./main`) to examine the system calls that the program makes when it runs. Pick three system calls that the program makes, including `execve`, and describe their arguments and what they do in your `report.md`. You can use the `man` pages to find information about system calls (for example, `man 2 execve`).
* Use `objdump` to examine the assembly language instructions for the program. Look for the disassembly of the function `f` and explain how (1) the loop iteration works, (2) how the increment of the variable x works, and (3) how arguments are passed to the ``printf()`` function. For example, use the command `objdump -d -M intel main` to get the disassembly of your program.

## Evaluation

Your effort will be graded according to the following criteria:

- **50 points** For your explanation of the system calls.
- **50 points** For your explanation of the assembly language instructions.
