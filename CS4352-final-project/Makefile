obj-m += CS4352Adv.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	sudo dmesg -C
	sudo insmod CS4352Adv.ko
	sudo rmmod CS4352Adv.ko
	dmesg
