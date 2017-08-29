#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/version.h>

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Basic test module");
MODULE_AUTHOR("Justen");

int init_module(void) {
	printk(KERN_INFO "Loading\n");
	return 0;
}

void cleanup_module(void) {
	printk(KERN_INFO "Unloading\n"); 
}


