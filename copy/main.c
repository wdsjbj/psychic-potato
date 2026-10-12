#include "process_copy.h"

int main(int argc, char** argv)
{
    int pronum;
    int blocksize;

    // 不传第三个参数就默认是3个进程
    if (argv[3] == NULL)
    {
        pronum = 3;
    }
    else
    {
        pronum = atoi(argv[3]);
    }

    // 参数校验
    if (check_pram(argc, argv[1], pronum) != 0)
    {
        printf("参数错误\n");
        return -1;
    }

    // 计算分片大小
    blocksize = block_cur(argv[1], pronum);
    printf("每块分片大小：%d\n", blocksize);

    // 创建子进程
    process_create(argv[1], argv[2], pronum, blocksize);
    // 等待所有子进程结束
    process_wait();

    return 0;
}