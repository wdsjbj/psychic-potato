#include "process_copy.h"

int check_pram(int argc, const char* srcfile, int pronum)
{
	// 最少三个参数: 源文件 目标文件 [进程数]
    if (argc < 3)
    {
        printf("用法: ./process_copy 源文件 目标文件 [进程数]\n");
        return -1;
    }
    if (pronum <= 0)
    {
        printf("进程数必须大于0\n");
        return -1;
    }
    // 判断源文件是否存在
    int fd = open(srcfile, O_RDONLY);
    if (fd < 0)
    {
        perror("open srcfile failed");
        return -1;
    }
    close(fd);
    return 0;
}