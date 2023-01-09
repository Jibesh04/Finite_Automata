#include <stdio.h>
#include <stdlib.h>
int len(char* str){
    int ans = 0;
    while(str[ans])
        ans++;
    return ans;
}
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
void print_suffixes(char* str, int len){
    for(int i = 1; i < len; i++){
        for(int k = len; k >= i; k--){
            for(int j = i; j < k; j++)
                printf("%c", str[j]);
            printf("\n");
        }
    }
}
int main(){
    int len;
    printf("Enter the length of the string: ");
    scanf("%d", &len);
    printf("Enter the string: ");
    char* str = input_str(len);
    printf("u: ");
    print_str(str, len);
    printf("Possible suffixes are: \n");
    print_suffixes(str, len);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\print_all_suffixes.exe .\print_all_suffixes.c
PS D:\Junior\Study\Finite_Automata> .\print_all_suffixes.exe
Enter the length of the string: 5
Enter the string: abcde
u: abcde
Possible suffixes are: 
bcde
bcd
bc
b

cde
cd
c

de
d

e

*/