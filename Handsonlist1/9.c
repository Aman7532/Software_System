// Aman Agarwal
// MT2024017

/* Question : Write a program to print the following information about a given file -
    1. Inode
    2. Number of hard links
    3. UID
    4. GID
    5. Size
    6. Block size
    7. Number of blocks
    8. Time of last access
    9. Time of last modification
    10. Time of last change
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
int main(int agrv, char *argc[])
{
    struct stat s;
    stat(argc[1], &s);
    printf("id of device=%ld\n", s.st_dev);
    printf("inode=%ld\n", s.st_ino);
    printf("file type and mode=%d\n", s.st_mode);
    printf("number of hardlink=%ld\n", s.st_nlink);
    printf("user id=%d\n", s.st_uid);
    printf("group id=%d\n", s.st_gid);
    printf("device id=%ld\n", s.st_rdev);
    printf("total size in bytes=%ld\n", s.st_size);
    printf("Block size of filesystem=%ld\n", s.st_blksize);
    printf("Number of block=%ld\n", s.st_blocks);
    printf("Last access time=%s", ctime(&(s.st_atimespec).tv_sec));
    printf("Last modified time=%s", ctime(&(s.st_mtimespec).tv_sec));
    printf("Last status change time=%s", ctime(&(s.st_ctimespec).tv_sec));
    return 0;
}

// OUTPUT
/*id of device=0
inode=0
file type and mode=0
number of hardlink=0
user id=31537824
group id=2
device id=1830481408
total size in bytes=4345698576
Block size of filesystem=46480588
Number of block=4345699608
Last access time=Thu Feb  9 15:06:48 2164
Last modified time=Thu Jan  1 05:30:00 1970
Last status change time=Thu Jan  1 05:30:00 1970

*/