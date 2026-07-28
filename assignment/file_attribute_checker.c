#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

const char *getFileType(mode_t mode) {
    if (S_ISREG(mode))
        return "Regular File";

    if (S_ISDIR(mode))
        return "Directory";

    if (S_ISLNK(mode))
        return "Symbolic Link";

    if (S_ISCHR(mode))
        return "Character Device";

    if (S_ISBLK(mode))
        return "Block Device";

    if (S_ISFIFO(mode))
        return "FIFO";

    if (S_ISSOCK(mode))
        return "Socket";

    return "Unknown";
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    struct stat info;

    if (stat(argv[1], &info) == -1) {
        perror("stat");
        return 1;
    }

    char accessTime[100];
    char modificationTime[100];
    char changeTime[100];

    struct tm *tm_info;

    tm_info = localtime(&info.st_atime);
    strftime(accessTime, sizeof(accessTime),
             "%a %b %d %H:%M:%S %Y", tm_info);

    tm_info = localtime(&info.st_mtime);
    strftime(modificationTime, sizeof(modificationTime),
             "%a %b %d %H:%M:%S %Y", tm_info);

    tm_info = localtime(&info.st_ctime);
    strftime(changeTime, sizeof(changeTime),
             "%a %b %d %H:%M:%S %Y", tm_info);

    printf("=== File Attributes for: %s ===\n", argv[1]);

    printf("File Type:            %s\n",
           getFileType(info.st_mode));

    printf("Permissions:          %04o\n",
           info.st_mode & 0777);

    printf("File Size:            %lld bytes\n",
           (long long)info.st_size);

    printf("Hard Links Count:     %lu\n",
           (unsigned long)info.st_nlink);

    printf("Owner (UID):          %u\n",
           (unsigned int)info.st_uid);

    printf("Group (GID):          %u\n",
           (unsigned int)info.st_gid);

    printf("Last Access Time:     %s\n", accessTime);

    printf("Last Modification:    %s\n", modificationTime);

    printf("Status Change Time:   %s\n", changeTime);

    return 0;
}