#include "process_copy.h"

int process_create(const char* srcfile, const char* destfile, int pronum, int blocksize)
{
    char offset_str[50];
    char blocksize_str[50];
    pid_t pid;
    int i;

    for (i = 0; i < pronum; i++)
    {
        pid = fork();
        if (pid < 0)
        {
            perror("fork error");
            return -1;
        }
        if (pid > 0)
        {
            //父进程继续循环创建子进程
            continue;
        }
        else if (pid == 0)
        {
            //子进程拼接参数调用copy程序
            int offset = i * blocksize;
            sprintf(offset_str, "%d", offset);
            sprintf(blocksize_str, "%d", blocksize);
            printf("child %d exec copy , offset %d, blocksize %d\n", getpid(), offset, blocksize);

            execl("./copy", "copy", srcfile, destfile, offset_str, blocksize_str, NULL);
            // execl失败才会走到这里
            perror("execl failed");
            exit(EXIT_FAILURE);
        }
    }
    return 0;
}