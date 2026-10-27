#include <stdio.h>
#include <string.h>

// Function to remove single-line (//) and multi-line (/* */) comments
void *commentremove(char *str)
{
    char *ptr = NULL;
    ptr = str;

    char *first = NULL, *last = NULL;
    char sub1[] = "//";
    char sub2[] = "\n";
    int n;
    char s1[] = "/*";
    char s2[] = "*/";
    int in_string = 0;
    int in_char = 0;

    // ====================================================================
    // PART 1: Remove Single-Line Comments (//)
    // ====================================================================
    while ((ptr = strstr(ptr, sub1)) != NULL)
    {
        in_string = 0;
        in_char = 0;
        char *temp = str;

        // Scan from start up to the '//' match to verify if it's inside quotes
        while (temp < ptr)
        {
            if (*temp == '"' && (temp == str || *(temp - 1) != '\\'))
                in_string = !in_string;
            if (*temp == '\'' && (temp == str || *(temp - 1) != '\\'))
                in_char = !in_char;
            temp++;
        }

        // Quote Protection: If it's part of a string or character literal, skip it
        if (in_string || in_char)
        {
            ptr = ptr + 2;
            continue;
        }

        first = ptr; // Start position of the comment block

        // Locate the line ending (\n)
        while ((ptr = strstr(ptr, sub2)) != NULL)
        {
            last = ptr;
            break;
        }

        ptr = first;
        // Shift data forward to erase the comment string up to the newline character
        memmove(first, last, strlen(last) + 1);
    }

    // ====================================================================
    // PART 2: Remove Multi-Line Comments (/* ... */)
 // ====================================================================
    ptr = str;
    while ((ptr = strstr(ptr, s1)) != NULL)
    {
        in_string = 0;
        in_char = 0;
        char *temp = str;

        // Scan from start up to the '/*' match to verify if it's inside quotes
        while (temp < ptr)
        {
            if (*temp == '"' && (temp == str || *(temp - 1) != '\\'))
                in_string = !in_string;
            if (*temp == '\'' && (temp == str || *(temp - 1) != '\\'))
                in_char = !in_char;
            temp++;
        }

        // Quote Protection: If it's part of a string or character literal, skip it
        if (in_string || in_char)
        {
            ptr = ptr + 2;
            continue;
        }

        first = ptr; // Start position of the block comment

        // Find the matching end marker '*/'
        while ((ptr = strstr(ptr, s2)) != NULL)
        {
            last = ptr;
            break;
        }

        // Determine slice length 'n' based on the presence of a trailing newline character
        if (*(last + 2) == '\n')
        {
            n = 3 + last - first;
        }
        else
        {
            n = 2 + last - first;
        }

        ptr = first;
        // Erase the block comment segment by shifting the remaining string text backwards
        memmove(ptr, ptr + n, strlen(ptr + n) + 1);
    }

    return str;
}