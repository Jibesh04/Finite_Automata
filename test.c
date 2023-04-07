#include <stdio.h>
#include <string.h>

char tt[3][2][2] = {{"", "1"}, {"2", "12"}, {"", ""}};
int flag = 0;
void rec(char str[], int cst, int i)
{
    int id, l = strlen(str);
    if (i == l && cst == 2 && flag == 0)
    {
        printf("Accepted\n");
        flag = 1;
        return;
    }
    for (id = 0; id < strlen(tt[cst][str[i] - 'a']) && i < l; id++)
    {
        rec(str, tt[cst][str[i] - 'a'][id] - 48, i + 1);
    }
}

int main()
{
    char str[30];
    printf("Enter the binary string :");
    scanf("%s", str);
    rec(str, 0, 0);
    if (flag == 0)
    {
        printf("Rejected\n");
    }
    return 0;
}