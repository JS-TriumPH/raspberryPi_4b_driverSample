#ifndef __GPIO_CONTROL_
#define __GPIO_CONTROL_

#define IOCTL_GPIO_IN 0x10000
#define IOCTL_GPIO_OUT 0x10001
#define IOCTL_GPIO_CLR_ALL 0x10002
#define IOCTL_GPIO_SET_ALL 0x10003
#define IOCTL_GPIO_READ_STATUS 0x10004

#define IOCTL_GPIO_PULL_UP 1
#define IOCTL_GPIO_PULL_DOWN 0

struct GPIO_PARAM
{
	unsigned char gpioNumber;
	unsigned char gpioValue; 
	unsigned char gpioMode; 
};

#endif