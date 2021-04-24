/*
 * Rishabh Tewari
 * CS 4352: Final Project
 *
 * */
#define BLKDEV_NAME          "os_block_dev"
#define BLOCK_MAJOR           240

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>

MODULE_AUTHOR("Rishabh Tewari");
MODULE_DESCRIPTION("CS 4352 Final project");
MODULE_VERSION("0.02");
MODULE_LICENSE("GPL");

/*Function called when the module is inserted into the kernel*/
int init_module()
{
    printk(KERN_INFO "This program was written by\nRishabh Tewari\nCS 4352 Final Project Module Loaded. The more adv version");
    int status;
    status = register_blkdev(BLOCK_MAJOR, BLKDEV_NAME);

    printk(KERN_INFO "CS 4352 Block device REGISTERED successfully - Rishabh Tewari");

    if(status < 0)
    {
             printk(KERN_ERR "unable to register mybdev block device\n");
             return -EBUSY;
    }

    return 0; //0 shows the module was loaded in successfully
}

/*Function called when the module is removed*/
void cleanup_module()
{
    printk(KERN_INFO "CS 4352 Final Project Module Removed\n");
    unregister_blkdev(BLOCK_MAJOR, BLKDEV_NAME);


}

