/* code for strncat: appends a limited number of char from one stirng to another


*/

#include <stdio.h>
#include <string.h>

int main()
{
    char str1[50] = "Hello";
    char str2[] = " World";
    char src[] = "Copy this string";
    char dest[50];
    char str3[] = "C,Programming,Language";
    char *token;

    // Using strncat
    printf("Before strncat: %s\n", str1);
    strncat(str1, str2, 6);
    printf("After strncat: %s\n", str1);

    // Using strncpy
    strncpy(dest, src, 10);
    dest[10] = '\0'; // Ensure null termination
    printf("Using strncpy: %s\n", dest);

    // Using strtok
    printf("Using strtok:\n");
    token = strtok(str3, ",");
    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    char *token;
    token = strtok(my_str, ' ');
    while(token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    return 0;
}
