#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))

int main()
{
    char source[100] = "\0", from[100] = "\0", to[100] = "\0", res[100] = "\0";
    int i;

    gets(source);
    gets(from);
    gets(to);

    char* pos;

    while (strstr(source, from) != NULL)
    {
        pos = strstr(source, from);
        
        for (i = 0; i < pos - source; i++)
            res[i] = source[i];

        for (int i = 0; i < strlen(to); i++)
            res[pos - source + i] = to[i];

        for (int i = pos - source; i < strlen(source); i++)
            res[i + strlen(to)] = source[i + strlen(from)];

        for (i = 0; i < max(strlen(source), strlen(res)); i++)
            source[i] = res[i];
    }

    printf("%s", source);

    return 0;
}