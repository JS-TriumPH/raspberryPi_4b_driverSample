#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "gpio_control.h"

int fd = 0;
struct GPIO_PARAM gpioParam;
int i = 0;

void led_show()
{
	while(1)
	{
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(1000000);
		
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(1000000);
		
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(1000000);
		
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(1000000);
		
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(250000);
		
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(250000);
		
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(250000);
		
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(250000);
		
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 0;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(250000);
		
		gpioParam.gpioNumber = 2;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 3;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 4;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		gpioParam.gpioNumber = 14;
		gpioParam.gpioValue = 1;
		
		if(ioctl(fd, IOCTL_GPIO_OUT, &gpioParam) < 0)
		{
			perror("failed to execute ioctl");
			return;
		}
		
		usleep(250000);
	}
}

void main(int argc, char *argv[])
{
	fd = open("/dev/my_gpio", O_RDWR | O_SYNC);
	if(fd < 0)
	{
		perror("failed to open /dev/my_gpio");
		return;
	}
	
	memset(&gpioParam, 0, sizeof(struct GPIO_PARAM));
		
	if(ioctl(fd, IOCTL_GPIO_CLR_ALL, 0) < 0)
	{
		perror("failed to execute ioctl");
		return;
	}
			
	led_show();
	
	close(fd);
	
	return;
}