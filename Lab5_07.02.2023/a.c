#include <stdio.h>
#include <string.h>
#define max 5
// ending with '1' and does not have substring '00'
char tt[3][2][max] = {{"2", "1"}, {"2", "1"}, {"", "1"}};

int l;
int flag = 0;
void rec(int cst, int i, char str[])
{
    int id = 0;
    for (; id < strlen(tt[cst][str[i] - 48]) && i < l; id++)
        rec(tt[cst][str[i] - 48][id] - 48, i + 1, str);

    if (i == l && cst == 1)
    {
        printf("Accepted\n");
        flag = 1;
    }
}

int main()
{
    char str[30];
    printf("Enter the string: ");
    scanf("%s", str);
    l = strlen(str);
    // Function calling
    rec(0, 0, str);
    if (flag == 0)
    {
        printf("Rejected\n");
    }
    return 0;
}
// Terminal

// Enter the string: 010101
// Accepted

// Enter the string: 01001
// Rejected