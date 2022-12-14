#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char **ft_split(char *str)
{
    int i;
    char **str2 = (char **)malloc(1000);
    int k = 0;
    int b = 0;

    i = 0;

    while (str[i])
    {
        while (str[i] == ' ' || str[i] == '\t')
            i++;
        str2[b] = malloc(1000);
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
            str2[b][k++] = str[i++];
        str2[b][k] = '\0';
        b++;
        k = 0;
    }
    str2[b] = NULL;
    return str2;
}
/*
int main()
{
    char *a = "Amd Ryzen Intel Gtx Rtx";
    char **res = ft_split(a);
    int index = 0;

    while (res[index])
    {
        printf("%s\n", res[index]);
        index++;
    }
}
*/
