# 定义编译器
CC = gcc

# 定义编译选项
CFLAGS = -O2

# 定义目标文件
TARGET = main

# 默认目标
all: $(TARGET)

# 编译目标文件
$(TARGET): main.o
	$(CC) $(CFLAGS) -o $(TARGET) $^

# 编译源文件
%.o: %.c
	$(CC) $(CFLAGS) -c $^

# 清理生成的文件
clean:
	rm -f $(TARGET) *.o
