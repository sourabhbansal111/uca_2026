#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LOG_FILE "audit.log"
#define BUFFER_SIZE 4096

void write_number(int number)
{
    char digits[20];
    int length = 0;

    if (number == 0)
    {
        write(STDOUT_FILENO, "0", 1);
        return;
    }

    while (number > 0)
    {
        digits[length++] = (number % 10) + '0';
        number /= 10;
    }

    for (int i = length - 1; i >= 0; i--)
        write(STDOUT_FILENO, &digits[i], 1);
}

int add_log(const char *message)
{
    int fd = open(LOG_FILE, O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1)
    {
        const char error[] = "Error opening log file\n";
        write(STDERR_FILENO, error, sizeof(error) - 1);
        return 1;
    }

    write(fd, message, strlen(message));
    write(fd, "\n", 1);

    close(fd);

    return 0;
}

int view_log(void)
{
    int fd = open(LOG_FILE, O_RDONLY);

    if (fd == -1)
    {
        const char error[] = "Error opening log file\n";
        write(STDERR_FILENO, error, sizeof(error) - 1);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytes_read;

    int line_number = 1;
    int start_of_line = 1;

    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        for (ssize_t i = 0; i < bytes_read; i++)
        {
            if (start_of_line)
            {
                write_number(line_number);
                write(STDOUT_FILENO, ": ", 2);

                start_of_line = 0;
            }

            write(STDOUT_FILENO, &buffer[i], 1);

            if (buffer[i] == '\n')
            {
                line_number++;
                start_of_line = 1;
            }
        }
    }

    close(fd);

    return 0;
}

int main(int argc, char *argv[])
{
    if (argc == 3 && strcmp(argv[1], "--add") == 0)
        return add_log(argv[2]);

    if (argc == 2 && strcmp(argv[1], "--view") == 0)
        return view_log();

    const char usage[] =
        "Usage:\n"
        "./auditlog --add \"message\"\n"
        "./auditlog --view\n";

    write(STDERR_FILENO, usage, sizeof(usage) - 1);

    return 1;
}