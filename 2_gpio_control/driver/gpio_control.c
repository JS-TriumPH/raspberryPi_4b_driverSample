#include <linux/init.h>
#include <linux/cdev.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/of.h>
#include <linux/of_address.h>

#include "gpio_control.h"


void __iomem *GPIO_BASE_ADDR;
#define GPIO_GPFSEL0_OFFSET 0x00
#define GPIO_GPFSEL1_OFFSET 0x04
#define GPIO_GPFSEL2_OFFSET 0x08
#define GPIO_GPFSEL3_OFFSET 0x0c
#define GPIO_GPFSEL4_OFFSET 0x10
#define GPIO_GPFSEL5_OFFSET 0x14

#define GPIO_GPSET0_OFFSET 0x1c
#define GPIO_GPSET1_OFFSET 0x20
						   
#define GPIO_GPCLR0_OFFSET 0x28
#define GPIO_GPCLR1_OFFSET 0x2c
						   
#define GPIO_GPLEV0_OFFSET 0x34
#define GPIO_GPLEV1_OFFSET 0x38
						   
#define GPIO_GPEDS0_OFFSET 0x40
#define GPIO_GPEDS1_OFFSET 0x44
						   
#define GPIO_GPREN0_OFFSET 0x4c
#define GPIO_GPREN1_OFFSET 0x50
						   
#define GPIO_GPFEN0_OFFSET 0x58
#define GPIO_GPFEN1_OFFSET 0x5c
						   
#define GPIO_GPHEN0_OFFSET 0x64
#define GPIO_GPHEN1_OFFSET 0x68
						   
#define GPIO_GPLEN0_OFFSET 0x70
#define GPIO_GPLEN1_OFFSET 0x74

#define GPIO_GPAREN0_OFFSET 0x7c
#define GPIO_GPAREN1_OFFSET 0x80
						    
#define GPIO_GPAFEN0_OFFSET 0x88
#define GPIO_GPAFEN1_OFFSET 0x8c

#define GPIO_PUP_PDN_CNTRL_REG0_OFFSET 0xe4
#define GPIO_PUP_PDN_CNTRL_REG1_OFFSET 0xe8
#define GPIO_PUP_PDN_CNTRL_REG2_OFFSET 0xec
#define GPIO_PUP_PDN_CNTRL_REG3_OFFSET 0xf0


volatile unsigned int __iomem *GPFSEL0;
volatile unsigned int __iomem *GPFSEL1;
volatile unsigned int __iomem *GPFSEL2;
volatile unsigned int __iomem *GPFSEL3;
volatile unsigned int __iomem *GPFSEL4;
volatile unsigned int __iomem *GPFSEL5;

volatile unsigned int __iomem *GPSET0;
volatile unsigned int __iomem *GPSET1;

volatile unsigned int __iomem *GPCLR0;
volatile unsigned int __iomem *GPCLR1;

volatile unsigned int __iomem *GPLEV0;
volatile unsigned int __iomem *GPLEV1;

volatile unsigned int __iomem *GPEDS0;
volatile unsigned int __iomem *GPEDS1;
                         
volatile unsigned int __iomem *GPREN0;
volatile unsigned int __iomem *GPREN1;
                         
volatile unsigned int __iomem *GPFEN0;
volatile unsigned int __iomem *GPFEN1;
                         
volatile unsigned int __iomem *GPHEN0;
volatile unsigned int __iomem *GPHEN1;
                         
volatile unsigned int __iomem *GPLEN0;
volatile unsigned int __iomem *GPLEN1;

volatile unsigned int __iomem *GPLEV0;
volatile unsigned int __iomem *GPLEV1;

volatile unsigned int __iomem *GPAREN0;
volatile unsigned int __iomem *GPAREN1;

volatile unsigned int __iomem *GPAFEN0;
volatile unsigned int __iomem *GPAFEN1;

volatile unsigned int __iomem *GPPULLCTL0;
volatile unsigned int __iomem *GPPULLCTL1;
volatile unsigned int __iomem *GPPULLCTL2;
volatile unsigned int __iomem *GPPULLCTL3;

static struct cdev *g_gpioDev;
static dev_t g_gpioNumber;
static struct class *g_gpioClass;

static int gpio_open(struct inode *inode, struct file *filp)
{
	return 0;
}

static int gpio_release(struct inode *inode, struct file *filp)
{
	return 0;
}

static ssize_t gpio_read(struct file *filp, char __user *buf, size_t count, loff_t *offset)
{
	return 0;
}

static ssize_t gpio_write(struct file *filp, const char __user *buf, size_t size, loff_t *offset)
{
	return 0;
}

static ssize_t gpio_unlocked_ioctl(struct file *filp, unsigned int cmd, unsigned long arg)
{
	struct GPIO_PARAM gpioParam;
	unsigned char number = 0;
	unsigned char value = 0;
	unsigned char mode = 0;
	unsigned int mask = 0;
	unsigned int tmp = 0;
	
	pr_info("cmd : 0x%x\n", cmd);
	pr_info("GPFSEL0 : 0x%x\n", ioread32(GPFSEL0));
	pr_info("GPFSEL1 : 0x%x\n", ioread32(GPFSEL1));
	pr_info("GPFSEL2 : 0x%x\n", ioread32(GPFSEL2));
	pr_info("GPCLR0 : 0x%x\n", ioread32(GPCLR0));
	pr_info("GPSET0 : 0x%x\n", ioread32(GPSET0));
	
	if((IOCTL_GPIO_IN == cmd) || (IOCTL_GPIO_OUT == cmd))
	{
		if(0 != copy_from_user(&gpioParam, (struct GPIO_PARAM *)arg, sizeof(struct GPIO_PARAM)))
		{
			pr_err("copy_from_user failed\n");
			return -EFAULT;
		}
		
		number = gpioParam.gpioNumber;
		value = gpioParam.gpioValue;
		mode = gpioParam.gpioMode;
		
		pr_info("number : 0x%x\n", number);
		pr_info("value : 0x%x\n", value);
		pr_info("mode : 0x%x\n", mode);
		
		if(number > 27)
		{
			pr_warn("cannot control gpio exceed GPIO27\n");
			return -EFAULT;
		}
	}
		
	switch(cmd)
	{
		case IOCTL_GPIO_IN:
		{
			if(IOCTL_GPIO_PULL_UP == mode)
			{
				if(number >= 0 && number <= 15)
				{
					tmp = ioread32(GPPULLCTL0);
					
					mask = 2U << (number * 2);
					mask = ~mask;
					tmp &= mask;
													
					mask = 1U << (number* 2);
					tmp |= mask;
					iowrite32(tmp, GPPULLCTL0);
				}
				else if(number >= 16 && number <= 31)
				{
					tmp = ioread32(GPPULLCTL1);
					
					mask = 2U << ((number - 16) * 2);
					mask = ~mask;
					tmp &= mask;
													
					mask = 1U << ((number - 16) * 2);
					tmp |= mask;
					iowrite32(tmp, GPPULLCTL1);
				}
				else
				{
					
				}
			}
			else if(IOCTL_GPIO_PULL_DOWN == mode)
			{
				if(number >= 0 && number <= 15)
				{
					tmp = ioread32(GPPULLCTL0);
					
					mask = 1U << (number * 2);
					mask = ~mask;
					tmp &= mask;
													
					mask = 2U << (number * 2);
					tmp |= mask;
					iowrite32(tmp, GPPULLCTL0);
				}
				else if(number >= 16 && number <= 31)
				{
					tmp = ioread32(GPPULLCTL1);
					
					mask = 1U << ((number - 16) * 2);
					mask = ~mask;
					tmp &= mask;
													
					mask = 2U << ((number - 16) * 2);
					tmp |= mask;
					iowrite32(tmp, GPPULLCTL1);
				}
				else
				{
					
				}
			}
			else
			{
				
			}
									
			if(number >= 0 && number <= 9)
			{
				tmp = ioread32(GPFSEL0);
				
				mask = 7U << (number * 3);
				mask = ~mask;
				tmp &= mask;

				iowrite32(tmp, GPFSEL0);
			}
			else if(number >= 10 && number <= 19)
			{
				tmp = ioread32(GPFSEL1);
				
				mask = 7U << ((number - 10) * 3);
				mask = ~mask;
				tmp &= mask;
				
				iowrite32(tmp, GPFSEL1);
			}
			else if(number >= 20 && number <= 29)
			{
				tmp = ioread32(GPFSEL2);
				
				mask = 7U << ((number - 20) * 3);
				mask = ~mask;
				tmp &= mask;
				
				iowrite32(tmp, GPFSEL2);
			}
			else
			{
				
			}
			
			value = (ioread32(GPLEV0) >> number) & 0x1;
			gpioParam.gpioValue = value;
			
			if(0 != copy_to_user((struct GPIO_PARAM *)arg, &gpioParam, sizeof(struct GPIO_PARAM)))
			{
				pr_err("copy_to_user failed\n");
				return -EFAULT;
			}
			
			break;
		}
		
		case IOCTL_GPIO_OUT:
		{
			if(number >= 0 && number <= 9)
			{		
				tmp = ioread32(GPFSEL0);
				
				mask = 6U << (number * 3);
				mask = ~mask;
				tmp &= mask;
								
				mask = 1 << (number * 3);
				tmp |= mask;
				
				iowrite32(tmp, GPFSEL0);
			}
			else if(number >= 10 && number <= 19)
			{			
				tmp = ioread32(GPFSEL1);
				
				mask = 6U << ((number - 10) * 3);
				mask = ~mask;
				tmp &= mask;
								
				mask = 1 << ((number - 10) * 3);
				tmp |= mask;
				
				iowrite32(tmp, GPFSEL1);
			}
			else if(number >= 20 && number <= 29)
			{
				tmp = ioread32(GPFSEL2);
				
				mask = 6U << ((number - 20) * 3);
				mask = ~mask;
				tmp &= mask;
				
				mask = 1 << ((number - 20) * 3);
				tmp |= mask;
				
				iowrite32(tmp, GPFSEL2);
			}
			else
			{
				
			}
			
			mask = (1U << number);
			
			if(0 == value)
			{
				iowrite32(mask, GPCLR0);
			}
			else if(1 == value)
			{
				iowrite32(mask, GPSET0);
			}
			else
			{
				pr_err("illegal gpio%u value : %u\n", number, value);
			}
			
			break;
		}
		
		case IOCTL_GPIO_CLR_ALL:
		{
			iowrite32(0x9249249, GPFSEL0);
			iowrite32(0x9249249, GPFSEL1);
			iowrite32(0x249249, GPFSEL2);
			
			iowrite32(0x0fffffff, GPCLR0);
			
			break;
		}
		
		case IOCTL_GPIO_SET_ALL:
		{
			iowrite32(0x9249249, GPFSEL0);
			iowrite32(0x9249249, GPFSEL1);
			iowrite32(0x249249, GPFSEL2);
			
			iowrite32(0x0fffffff, GPSET0);
			
			break;
		}
		
		case IOCTL_GPIO_READ_STATUS:
		{
			pr_info("GPFSEL0 : 0x%x\n", ioread32(GPFSEL0));
			pr_info("GPFSEL1 : 0x%x\n", ioread32(GPFSEL1));
			pr_info("GPFSEL2 : 0x%x\n", ioread32(GPFSEL2));		
			pr_info("GPSET0 : 0x%x\n", ioread32(GPSET0));
			pr_info("GPCLR0 : 0x%x\n", ioread32(GPCLR0));
			pr_info("GPLEV0 : 0x%x\n", ioread32(GPLEV0));
			
			break;
		}
			
		default:
			break;
	}
	
	pr_info("GPFSEL0 : 0x%x\n", ioread32(GPFSEL0));
	pr_info("GPFSEL1 : 0x%x\n", ioread32(GPFSEL1));
	pr_info("GPFSEL2 : 0x%x\n", ioread32(GPFSEL2));
	pr_info("GPCLR0 : 0x%x\n", ioread32(GPCLR0));
	pr_info("GPSET0 : 0x%x\n", ioread32(GPSET0));
	
	return 0;
}

static struct file_operations fops = 
{
	.owner		= THIS_MODULE,
	.open		= gpio_open,
	.release	= gpio_release,
	.read       = gpio_read,
	.write      = gpio_write,
	.unlocked_ioctl = gpio_unlocked_ioctl,
};

static int __init gpio_init(void)
{
	struct device_node *node;
    struct resource res;
	struct device *dev;
	
	int ret = 0;
	
	g_gpioDev = cdev_alloc();
	if(NULL == g_gpioDev)
	{
		pr_err("cdev_alloc failed\n");
		return -1;
	}
	
	//初始化cdev结构体，并关联file_operations
	cdev_init(g_gpioDev, &fops);
	g_gpioDev->owner = THIS_MODULE;
	
	ret = alloc_chrdev_region(&g_gpioNumber, 0, 1, "my_gpio");
	if(ret < 0)
	{
		pr_err("alloc_chrdev_region failed\n");
		return ret;
	}
	pr_info("successfully allocated device number Major: %d, Minor: %d\n",  MAJOR(g_gpioNumber), MINOR(g_gpioNumber));
	
	/* 关联cdev和设备号 */
	ret = cdev_add(g_gpioDev, g_gpioNumber, 1);
	if(ret < 0)
	{
		pr_err("cdev_add failed\n");
		unregister_chrdev_region(g_gpioNumber, 1);
		cdev_del(g_gpioDev);
        return ret;
	}
	
	/* 创建设备类 */
	g_gpioClass = class_create(THIS_MODULE, "my_gpio_class");
	if (IS_ERR(g_gpioClass)) 
	{
		pr_err("class_create failed\n");
        unregister_chrdev_region(g_gpioNumber, 1);
		cdev_del(g_gpioDev);
        return PTR_ERR(g_gpioClass);
    }
	
	dev = device_create(g_gpioClass, NULL, g_gpioNumber, NULL, "my_gpio");
	if(IS_ERR(dev))
	{
		pr_err("device_create failed\n");
        unregister_chrdev_region(g_gpioNumber, 1);
		cdev_del(g_gpioDev);
        return PTR_ERR(dev);
	}
	
	pr_info("my_gpio device registered succeed\n");
	
	/* 在设备树中查找名为 "gpio" 的节点 */
    node = of_find_node_by_name(NULL, "gpio");
    if (!node) 
	{
        pr_err("Node 'gpio' not found\n");
        return -ENODEV;
    }

	/* 获取节点的地址信息 */
    if (of_address_to_resource(node, 0, &res)) 
	{
        pr_err("Failed to get address from node\n");
        of_node_put(node);
        return -ENXIO;
    }

    pr_info("Address of node 'gpio' is 0x%llx\n", (unsigned long long)res.start);
	pr_info("Address of node 'gpio' end in 0x%llx\n", (unsigned long long)res.end);

    of_node_put(node);
	
	GPIO_BASE_ADDR = ioremap(res.start, res.end - res.start + 1);
	if(!GPIO_BASE_ADDR)
	{
		pr_err("ioremap GPIO_BASE_ADDR failed\n");
		return -1;
	}
	
	GPFSEL0 = GPIO_BASE_ADDR + GPIO_GPFSEL0_OFFSET;
	GPFSEL1 = GPIO_BASE_ADDR + GPIO_GPFSEL1_OFFSET;
	GPFSEL2 = GPIO_BASE_ADDR + GPIO_GPFSEL2_OFFSET;
	GPFSEL3 = GPIO_BASE_ADDR + GPIO_GPFSEL3_OFFSET;
	GPFSEL4 = GPIO_BASE_ADDR + GPIO_GPFSEL4_OFFSET;
	GPFSEL5 = GPIO_BASE_ADDR + GPIO_GPFSEL5_OFFSET;
	
	GPCLR0 = GPIO_BASE_ADDR + GPIO_GPCLR0_OFFSET;
	GPCLR1 = GPIO_BASE_ADDR + GPIO_GPCLR1_OFFSET;
	GPSET0 = GPIO_BASE_ADDR + GPIO_GPSET0_OFFSET;
	GPSET1 = GPIO_BASE_ADDR + GPIO_GPSET1_OFFSET;
	
	GPLEV0 = GPIO_BASE_ADDR + GPIO_GPLEV0_OFFSET;
	GPLEV1 = GPIO_BASE_ADDR + GPIO_GPLEV1_OFFSET;
	
	GPPULLCTL0 = GPIO_BASE_ADDR + GPIO_PUP_PDN_CNTRL_REG0_OFFSET;
	GPPULLCTL1 = GPIO_BASE_ADDR + GPIO_PUP_PDN_CNTRL_REG1_OFFSET;
	GPPULLCTL2 = GPIO_BASE_ADDR + GPIO_PUP_PDN_CNTRL_REG2_OFFSET;
	GPPULLCTL3 = GPIO_BASE_ADDR + GPIO_PUP_PDN_CNTRL_REG3_OFFSET;
	
	return 0;
}

static void __exit gpio_exit(void)
{
	iounmap(GPIO_BASE_ADDR);
	
	device_destroy(g_gpioClass, g_gpioNumber);
    class_destroy(g_gpioClass);
    cdev_del(g_gpioDev);
    unregister_chrdev_region(g_gpioNumber, 1);
    pr_info("my_gpio device unregistered\n");
}

module_init(gpio_init);
module_exit(gpio_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PengHao");