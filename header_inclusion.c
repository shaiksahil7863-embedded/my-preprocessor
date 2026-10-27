#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *headerinclusion(char *str)
{
    char *ptr = NULL;
    ptr = str;

    char *first = NULL, *last = NULL;
    char sub[] = "#include";

    // Find every #include in the string
    while ((ptr = strstr(ptr, sub)) != NULL)
    {
        first = ptr; // Mark start of the line

        // Find opening and closing quotes
        char *p1 = strstr(ptr, "\"");
        if (p1 == NULL) {
            ptr = ptr + 8;
            continue;
        }
        char *p2 = strstr(p1 + 1, "\"");
        if (p2 == NULL) {
            ptr = ptr + 8;
            continue;
        }

        // Get the filename
        char f[100];
        int len = p2 - (p1 + 1);
        strncpy(f, p1 + 1, len);
        f[len] = '\0';

        // Find the newline character
        char *n = strstr(p2, "\n");
        if (n != NULL) {
            last = n + 1;
        } else {
            last = p2 + 1;
        }

        // Open the file and find its size
        FILE *fp = fopen(f, "r");
        if (fp == NULL)
        {
            printf("Warning: file not found : %s\n", f);
            ptr = last;
            continue;
        }

        fseek(fp, 0, 2);
        long sz = ftell(fp);
        fseek(fp, 0, 0);

        // Allocate buffer and read file contents
        char *buf = malloc(sz + 1);
        fread(buf, 1, sz, fp);
        buf[sz] = '\0';
        fclose(fp);

        // Shift string and copy the header text in-place
        memmove(first + sz, last, strlen(last) + 1);
        memcpy(first, buf, sz);
        free(buf);

        // Move pointer forward to continue loop safely
        ptr = first + sz;
    }

    return str;
}
               