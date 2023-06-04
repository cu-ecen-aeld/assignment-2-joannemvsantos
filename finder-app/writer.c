#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <libgen.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    openlog(NULL, LOG_PID, LOG_USER);

    if (argc != 3) {
        syslog(LOG_ERR, "Usage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        exit(1);
    }

    const char *writefile = argv[1];
    const char *writestr = argv[2];
    char dir[256];

    syslog(LOG_DEBUG, "Writing %s to %s\n", writestr, writefile);

    char *dirName = dirname(strdup(writefile));
    strncpy(dir, dirName, sizeof(dir));

    syslog(LOG_INFO, "Directory: %s\n", dir);

    struct stat st;
    if (stat(dir, &st) == -1) {
        syslog(LOG_INFO, "Directory does not exist. Creating...\n");
        if (mkdir(dir, 0777) == 0) {
            syslog(LOG_INFO, "Directory created successfully.\n");
        } else {
            syslog(LOG_ERR, "Failed to create directory.\n");
            closelog();
            exit(1);
        }
    } else {
        syslog(LOG_INFO, "Directory exists.\n");
    }

    FILE *file = fopen(writefile, "w");
    if (file != NULL) {
        syslog(LOG_INFO, "File created successfully.\n");
        fprintf(file, "%s\n", writestr);
        syslog(LOG_INFO, "Data written to file successfully.\n");
        fclose(file);
    } else {
        syslog(LOG_ERR, "Failed to create file.\n");
        closelog();
        exit(1);
    }

    closelog();
    exit(0);
}