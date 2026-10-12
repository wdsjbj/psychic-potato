CC = gcc
CFLAGS = -Wall -g

# 主程序：process_copy
OBJS = main.o check_pram.o block_cur.o process_create.o process_wait.o
TARGET = process_copy

# 子程序：copy
COPY_OBJ = copy.o
COPY_TARGET = copy

all: $(TARGET) $(COPY_TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(COPY_TARGET): $(COPY_OBJ)
	$(CC) $(CFLAGS) $(COPY_OBJ) -o $(COPY_TARGET)

# 生成各个.o目标文件
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET) $(COPY_TARGET)