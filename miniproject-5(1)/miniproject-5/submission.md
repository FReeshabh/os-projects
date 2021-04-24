Name: Rishabh Tewari

Title: Miniproject 5


1. I compiled the 5.1.0 version of the Linux kernel.

2. uname -a gave me "Linux CasaDelSquirrel 5.4.66-1-lts #1 SMP Thu, 17 Sep 2020 18:00:06 +0000 x86_64 GNU/Linux" from the old kernel. The new kernel gave me "Linux CasaDelSquirrel 5.10.0-rc2+ #1 SMP Fri, 6 Nov 2020 20:42:48 +0000 x86_64 GNU/Linux" 

3.  * vmlinuz is the name of the Linux kernel executable that's also bootable
    * A System.map is used as a kernel symbol table
    * config is the Linux kernel configuration file.
    * initrd.img lets the bootloader load up a RAM disk which can be mounted as the root file system and programs can be run from it.

4. My Linux kernel binary is 6.2MB

5. This configuration option lets us configure the timer frequency. The timer frequency affects real time and multimedia applications to process events at high frequencies (anything above 100Hz). A higher vallue is usually used when valuing latency, and a lower value when valuing throughput.

6. "It is customary to have the timer interrupt run at 1000 Hz but 100 Hz may be more beneficial for servers and NUMA systems that do not need to have a fast response for user interaction and that may experience bus contention and cacheline bounces as a result of timer interrupts."

7. A netfliter is a framework within Linux that filters and mangles network packets that pass through the Linux machine.

8. KASLR randomizes the physical addresses and maps the virtual addresses to these physical addreses, rather than have fixed, known addresses. It's a security feature 

9. The help message for this option says 
"This feature reduces the number of hardware side channels by ensuring that the majority of kernel addresses are not mapped into userspace. See Documentation/x86/pti.rst for more details."

10. The kernel is not compiled against C libraries like the regular user-space programs. Rather they have their own implementations of it. The reason behind that is that userspace programs can't be accessed by the kernel space programs







References used:
* The Kernel Config itself
* https://rlworkman.net/system.map/
* https://kernelnewbies.org/
* https://www.advenage.com/topics/linux-timer-interrupt-frequency
* https://stackoverflow.com/questions/14925568/lowering-linux-kernel-timer-frequency
* https://kernelnewbies.org/FAQ/LibraryFunctionsInKernel