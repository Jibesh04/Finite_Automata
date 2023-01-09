#include <stdio.h>
#include <stdlib.h>
char* input_str(int len){
    int cache;
    scanf("%d", &cache);
    char* str = (char*)malloc(len * sizeof(char));
    for(int i = 0; i < len; i++)
        scanf("%c", &str[i]);
    return str;
}
void print_str(char* str, int len){
    for(int i = 0; i < len; i++)
        printf("%c", str[i]);
    printf("\n");
}
int main(){
    int len;
    printf("Enter the length of the string: ");
    scanf("%d", &len);
    printf("Enter the string u: ");
    char* str = input_str(len);
    printf("u: ");
    print_str(str, len);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\input_string.exe .\input_string.c
PS D:\Junior\Study\Finite_Automata> .\input_string.exe         Enter the length of the string: 5
Enter the string u: ababb
u: ababb
*/