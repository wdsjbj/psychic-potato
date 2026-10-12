#include "process_copy.h"

int block_cur(const char* srcfile, int pronum)
{
    int fsize;
    int fd = open(srcfile, O_RDONLY);
    if (fd < 0)
    {
        perror("block_cur open failed");
        return -1;
    }
    fsize = lseek(fd, 0, SEEK_END);
    close(fd);
    //¹Ø±ÕÎÄ¼þÃèÊö·û

    if (fsize % pronum == 0)
    {
        return fsize / pronum;
    }
    else
    {
        return fsize / pronum + 1;
    }
}