/*************************************************************************
	> File Name: simple.c
	> Author: Junjie Wang
	> Mail: dreamboy.gns@sjtu.edu.cn
  > Website:http://www.dbgns.com
  > Blog:http://www.dbgns.com/blog
	> Created Time: Tue 14 May 2019 07:07:47 PM PDT
 ************************************************************************/

#include <linux/init.h>
#include <linux/hash.h> 
#include <linux/gcd.h> 
#include <asm/param.h> 
#include <linux/jiffies.h> 
#include <linux/kernel.h>
#include <linux/module.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("simple module");
MODULE_AUTHOR("Junjie Wang");
MODULE_VERSION("1.0");

static int start, end;

static int __init simple_init(void){
    printk(KERN_INFO "Loading module...\n");
    printk("The GOLDEN_RATIO_PRIME value is:%llu\n", GOLDEN_RATIO_PRIME);
    printk("The HZ value: %d\n", HZ);
    start = jiffies;
    printk("Current jiffies value: %lu\n", jiffies);
    /* we must have a return value here */
    return 0;
}

static void __exit simple_exit(void){
    printk("\n");
    printk("The gcd result: %lu\n", gcd(3300, 24));
    end = jiffies;
    printk("Current jiffies value: %lu\n", jiffies);
    printk("%ds time has elapsed since the insertion.\n", (end-start)/HZ);
    printk(KERN_INFO "Removing module...\n");
}

module_init(simple_init);
module_exit(simple_exit);

