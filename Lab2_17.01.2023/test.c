// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
#define MAX 5

char NFA[2][2][MAX] = {{"1", "1"}, {"", ""}};
int flag = 0;
int final_state = 1;

void check_acceptance(char * s, int cst, int i){
    int l = strlen(s);
    for(int id = 0; id < strlen(NFA[cst][s[i] - '0']) && i < l; id++)
        check_acceptance(s, NFA[cst][s[i] - '0'][id] - '0', i + 1);
    if(i == l && !flag && cst == final_state){
        printf("Accepted\n", s);
        flag = 1;
    }
}

int main() {
    char s[30];
    printf("Enter the string: ");
    scanf("%s", s);
    check_acceptance(s, 0, 0);
    if(!flag)
        printf("Rejected\n");
    return 0;
}