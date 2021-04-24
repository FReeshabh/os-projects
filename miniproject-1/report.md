Rishabh Tewari
Operating Systems Miniproject 1

-------------------------------------
**strace output**:
Command used : strace ./main

execve("./main", ["./main"], 0x7ffcd7571a10 /* 66 vars */) = 0
brk(NULL)                               = 0x562e34062000
arch_prctl(0x3001 /* ARCH_??? */, 0x7ffeff009850) = -1 EINVAL (Invalid argument)
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=131172, ...}) = 0
mmap(NULL, 131172, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f1bdb30d000
close(3)                                = 0
openat(AT_FDCWD, "/usr/lib/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0@q\2\0\0\0\0\0"..., 832) = 832
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
pread64(3, "\4\0\0\0\20\0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0", 32, 848) = 32
pread64(3, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0\346~\200\347\6\31qw\t\343\30\16U*\21\242"..., 68, 880) = 68
fstat(3, {st_mode=S_IFREG|0755, st_size=2146832, ...}) = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f1bdb30b000
pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
pread64(3, "\4\0\0\0\20\0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0", 32, 848) = 32
pread64(3, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0\346~\200\347\6\31qw\t\343\30\16U*\21\242"..., 68, 880) = 68
mmap(NULL, 1860456, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f1bdb144000
mprotect(0x7f1bdb169000, 1671168, PROT_NONE) = 0
mmap(0x7f1bdb169000, 1363968, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x25000) = 0x7f1bdb169000
mmap(0x7f1bdb2b6000, 303104, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x172000) = 0x7f1bdb2b6000
mmap(0x7f1bdb301000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bc000) = 0x7f1bdb301000
mmap(0x7f1bdb307000, 13160, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f1bdb307000
close(3)                                = 0
arch_prctl(ARCH_SET_FS, 0x7f1bdb30c540) = 0
mprotect(0x7f1bdb301000, 12288, PROT_READ) = 0
mprotect(0x562e3274c000, 4096, PROT_READ) = 0
mprotect(0x7f1bdb359000, 4096, PROT_READ) = 0
munmap(0x7f1bdb30d000, 131172)          = 0
fstat(1, {st_mode=S_IFREG|0644, st_size=0, ...}) = 0
brk(NULL)                               = 0x562e34062000
brk(0x562e34083000)                     = 0x562e34083000
write(1, "Value of x: 10\nHello, world!\n", 29) = 29
exit_group(0)                           = ?
+++ exited with 0 +++

------------------------------------------------------------
**EXPLANATION OF THE SYSTEM CALLS**

1. 
a. execve("./main", ["./main"], 0x7ffcd7571a10 /* 66 vars */) = 0
    This system call loads the main executable file. The text within the parentheses are the arguments provided to the execve system call. The 0 after the '=' tells us the value returned by the execve system call.

b. close(3)                                = 0
  close is a system call that closes a file. This system call returns 0 as the value. The 3 is an argument passed to close.

c. write(1, "Value of x: 10\nHello, world!\n", 29) = 29
A write is a system call that outputs data. It takes three arguments - the file descriptor, the pointer to buffer where the data is stored, and the number of bytes to write from the buffer. It returns 29 as the value. 

------------------------------------------------------------
 Look for the disassembly of the function `f` and explain how (1) the loop iteration works, (2) how the increment of the variable x works, and (3) how arguments are passed to the ``printf()`` function. For example, use the command `objdump -d -M intel main` to get the disassembly of your program.
**EXPLANATION OF ASSEMBLY LANGUAGE INSTRUCTIONS**

(1) The loop iteration is contained in the disassembly of the function 'f'. The actual looping part occurs here "

    115f:       eb 08                   jmp    1169 <f+0x20>
    1161:       83 45 fc 01             add    DWORD PTR [rbp-0x4],0x1
    1165:       83 45 f8 01             add    DWORD PTR [rbp-0x8],0x1
    1169:       83 7d f8 09             cmp    DWORD PTR [rbp-0x8],0x9
    116d:       7e f2                   jle    1161 <f+0x18>
"

(1)The `jmp    1169 <f+0x20>` instruction performs an unconditional jump to `cmp    DWORD PTR [rbp-0x8],0x9`, where it makes a comparison of DWORD PTR [rbp-0x8] with 0x9, so if DWORD PTR [rbp-0x8] is less than or equal to 0x9, it jumps back to `add    DWORD PTR [rbp-0x4],0x1`, which is how this loop will continue to happen until the loop condition is satisfied. 
(2) How the increments work in this situation is what after adding 0x1 to DWORD PTR [rbp-0x4], and DWORD PTR [rbp-0x8], and then looping again as explained in (1).
(3). 'printf' calls the 'write' system call, and in this case it was 'write(1, "Value of x: 10\nHello, world!\n", 29) = 29
'.System calls require particular integers, and arguments to be placed in the correct predefined registers, to determine the type of the system call. 
`
