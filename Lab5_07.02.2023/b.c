#include <stdio.h>
#include <string.h>
#define max 5

char tt[4][2][max] = {{"01", "02"}, {"3", ""}, {"", "3"}, {"3", "3"}};

int l;
int flag = 0;
void rec(int cst, int i, char str[])
{
    int id = 0;
    for (; id < strlen(tt[cst][str[i] - '0']) && i < l; id++)
        rec(tt[cst][str[i] - '0'][id] - '0', i + 1, str);

    if (i == l && cst == 3)
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

// Enter the string: 0101001
// Accepted

// Enter the string: 010
// Rejected