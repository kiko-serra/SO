#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char *argv[])
{
    struct stat info;
    
    if (argc < 2){
        fprintf(stderr, "usage: %s file\n", argv[0]);
        return EXIT_FAILURE;
    }
    int size = 0;
    int blocks = 0;
    for (int i = 1; i < argc; i++){
        if (stat(argv[i], &info) == -1){
            fprintf(stderr, "fsize: Can’t stat %s\n", argv[1]);
            return EXIT_FAILURE;
        }
        struct tm *tm;
        char buf[200];
        /* convert time_t to broken-down time representation */
        tm = localtime(&info.st_mtime);
        /* format time days.month.year hour:minute:seconds */
        strftime(buf, sizeof(buf), "%d.%m.%Y %H:%M:%S", tm);
        printf("%s size: %d bytes, disk_blocks: %d, last modified: %s, user:%d\n", 
        argv[i], (int)info.st_size, (int)info.st_blocks, buf, (int)info.st_uid);
        
        size += (int)info.st_size;
        blocks += (int)info.st_blocks;
    }
    
    printf("Total size: %d bytes, Total disk_blocks: %d\n", size, blocks);
    return EXIT_SUCCESS;
}