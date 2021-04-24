---
Rishabh Tewari
CS 4352 Final Project
---

***CHECK THE PDF VERSION***


# Project Description
To run this program, run `make`, and then `make test` to see the results of the program.

In this final project we were supposed to implement a simple ramdisk module that can be formatted with `mkfs.ext2`, and can be mounted and unmounted.

Requirements for the project:
  - Print out my name
  - Implement a ramdisk as a kernel module.
  - Allow an ext2 filesystem to be installed onto the ramdisk.
  - Allow the filesystem to be mounted and unmounted with “mount” and “unmount”.


# My attempt at the project
My attempt at the project partially meets the requirements needed for the project.

The makefile has instructions to compile and create the modules correctly. My `Makefile` also has a test component that you can test after running `make`, by running `make test`.

My code is in available in the `CS4352Adv.c` file.

Currently here's what my program does:
- Correctly compile the file
- Add information about the module: name, description, etc.
- Print out my name, and other information about the module when inserted
- Print out if there's any errors in loading the module
- Register a Block device
- Print out a message when removing the module
- Unregister the block device when `cleanup_module()` is called
