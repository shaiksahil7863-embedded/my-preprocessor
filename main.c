#include <string.h>

// Global variable from reference code
int cnt = 0;

// Forward declarations so the compiler knows these functions exist
void *commentremove(char *str);
void *headerinclusion(char *str);
void *macrosubstitution(char *str); // Added forward declaration for Level 3 macro pass

// 1. Simple function to load a file into a dynamic memory string buffer
void *readfromfile(char *file)
{
    char *ptr = NULL;
    FILE *src = NULL;
    src = fopen(file, "r");
    if (src == NULL)
    {
        printf("file not found :\n");
        exit(0);
    }
    fseek(src, 0, 2); // Move cursor to the end of the file
    long size = ftell(src) + 1;
    fseek(src, 0, 0); // Rewind cursor back to the beginning
    ptr = calloc(1, size);
    fread(ptr, size, 1, src);
    ptr[size - 1] = '\0';
    fclose(src);
    return ptr;
}

// 2. Simple function to save the processed text string back to the disk
void writetofile(char *ptr, char *file)
{
    FILE *fptr = NULL;
    int len = strlen(ptr);
    fptr = fopen(file, "w");
    fwrite(ptr, len, 1, fptr);
    fclose(fptr);
}
// 3. Main execution loop matching your reference code sequence exactly
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("give exe ,.c,.i files\n");
        exit(0);
    }

    // Reference logic to change the file extension from .c to .i
    char str[100];
    char ch[] = ".c";
    strcpy(str, argv[1]);

    char *p = NULL;
    p = str;
    while ((p = strstr(p, ch)) != NULL)
    {
        memcpy(p, ".i", 2);
    }

    // Modular processing pipeline execution sequence
    char *lines = NULL;
    lines = readfromfile(argv[1]);

    // Pass 1: Remove Comments
    lines = commentremove(lines);

    // Pass 2: Include Headers
    lines = headerinclusion(lines);

    // Pass 3: Substitute Macros (Added here)
    lines = macrosubstitution(lines);

    // Save the final processed string buffer to the newly generated .i filename
    writetofile(lines, str);

    printf("Success! Output generated at: %s\n", str);

     free(lines); // Clean up the allocated buffer space
    return 0;
}

                   