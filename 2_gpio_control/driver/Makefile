obj-m	+= gpio_control.o

KVERSION = $(shell uname -r)
KERN_DIR =  /lib/modules/$(KVERSION)/build 

all:
	make -C $(KERN_DIR) M=$(shell pwd) modules 

clean:
	make -C $(KERN_DIR) M=$(shell pwd) modules clean
