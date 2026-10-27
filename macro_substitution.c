#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Clean student style using basic parallel arrays for macro tracking
void *macrosubstitution(char *str)
{
    char *ptr = str;
    char *first = NULL, *last = NULL;
    char sub[] = "#define";

    // Arrays to store macro names and their replacement values
    char mac_names[50][50];
    char mac_vals[50][50];
    int count = 0;

    // STEP 1: Find and parse all macro definitions
    while ((ptr = strstr(ptr, sub)) != NULL)
    {
        first = ptr; // Start of the #define line

        // Move pointer past "#define " to find the macro name
        ptr = ptr + 8;

        // Extract the macro name (stops at space)
        int i = 0;
        while (*ptr != ' ' && *ptr != '\t' && *ptr != '\n' && *ptr != '\0')
        {
            mac_names[count][i++] = *ptr++;
        }
        mac_names[count][i] = '\0';

        // Skip trailing whitespace to find the macro value
        while (*ptr == ' ' || *ptr == '\t')
        {
            ptr++;
        }
        // Extract the macro value up to the end of the line
        int j = 0;
        while (*ptr != '\n' && *ptr != '\0')
        {
            mac_vals[count][j++] = *ptr++;
        }
        mac_vals[count][j] = '\0';

        // Find the newline boundary to remove this definition row
        char *n = strstr(ptr, "\n");
        if (n != NULL) {
            last = n + 1;
        } else {
            last = ptr;
        }

        // Delete the #define line in-place from the source block
        memmove(first, last, strlen(last) + 1);
        count++;
        ptr = first; // Reset scanning cursor
    }

    // STEP 2: Substitute registered macros throughout the remaining code block
    for (int k = 0; k < count; k++)
    {
        ptr = str;
        int m_len = strlen(mac_names[k]);
        int v_len = strlen(mac_vals[k]);

        while ((ptr = strstr(ptr, mac_names[k])) != NULL)
        {
            first = ptr;
            last = ptr + m_len;

            // Adjust code spacing to create exact room matching the macro value size
            memmove(first + v_len, last, strlen(last) + 1);

            // Drop macro value replacement text directly into the gap space
            memcpy(first, mac_vals[k], v_len);

            // Move tracking cursor forward to continue loop safely
            ptr = first + v_len;
                  }
    }

    return str;
}
