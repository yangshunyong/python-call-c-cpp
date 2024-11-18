#include <ctype.h>

void to_uppercase(char *str)
{
    while (*str) {
        *str = toupper((unsigned char) *str);
        str++;
    }
}
