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
void print_prefixes(char* str, int len){
    for(int i = 0; i < len - 1; i++){
        for(int k = i; k < len; k++){
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
    printf("Possible prefixes are: \n");
    print_prefixes(str, len);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> .\print_all_prefixes.exe
Enter the length of the string: 5
Enter the string: ababa
u: ababa
Possible prefixes are: 

a
ab
aba
abab

b
ba
bab

a
ab

b
*/