#include "process_copy.h"

int main(int argc, char** argv)
{
    int sfd;
    int dfd;
    int offset;
    int blocksize;
    int len;

    offset = atoi(argv[3]);
    blocksize = atoi(argv[4]);

    // 打开源文件 只读
    sfd = open(argv[1], O_RDONLY);
    if (sfd == -1)
    {
        perror("open srcfile failed");
        return -1;
    }
    // 打开目标文件，如果不存在就创建
    dfd = open(argv[2], O_WRONLY | O_CREAT, 0664);
    if (dfd == -1)
    {
        perror("open destfile failed");
        close(sfd);
        return -1;
    }

    // 文件指针跳转到对应分片偏移
    lseek(sfd, offset, SEEK_SET);
    lseek(dfd, offset, SEEK_SET);

    // 堆上分配缓冲区，避免栈溢出
    char* buffer = (char*)malloc(blocksize);
    if (buffer == NULL)
    {
        perror("malloc fail");
        close(sfd);
        close(dfd);
        return -1;
    }

    // 读取并写入
    len = read(sfd, buffer, blocksize);
    if (len > 0)
    {
        write(dfd, buffer, len);
    }

    free(buffer);
    close(sfd);
    close(dfd);
    return 0;
}