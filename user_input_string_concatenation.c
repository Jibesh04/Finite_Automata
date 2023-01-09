#include <stdio.h>
#include <stdlib.h>
int len(char* str){
    int ans = 0;
    while(str[ans] && str[ans] != '\n')
        ans++;
    return ans;
}
char* concat(char *u, char *v){
    int len_uv = len(u) + len(v);
    char* uv = (char*)malloc(len_uv * sizeof(char));
    int i = 0;
    while(u[i] && u[i] != '\n'){
        uv[i] = u[i];
        i++;
    }
    int j = 0;
    while(v[j] && v[j] != '\n'){
        uv[i] = v[j];
        i++; j++;
    }
    return uv;
}
void print_str(char* str, int n){
    for(int i = 0; i < n; i++)
        printf("%c", str[i]);
    printf("\n");
}
char* input_str(int length){
    int cache;
    scanf("%d", &cache);
    char* str = (char*)malloc(length * sizeof(char));
    for(int i = 0; i < length; i++)
        scanf("%c", &str[i]);
    return str;
}
int main(){
    int len_u, len_v;
    printf("Enter length of u: ");
    scanf("%d", &len_u);
    printf("Enter length of v: ");
    scanf("%d", &len_v);
    printf("Enter the string u: ");
    char *u = input_str(len_u);
    printf("Enter the string v: ");
    char *v = input_str(len_v);
    char* uv = concat(u, v);
    printf("u: ");
    print_str(u, len_u);
    printf("v: ");
    print_str(v, len_v);
    printf("uv: ");
    print_str(uv, (len_u + len_v));
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\user_input_string_concatenation.exe .\user_input_string_concatenation.c
PS D:\Junior\Study\Finite_Automata> .\user_input_string_concatenation.exe
Enter length of u: 3
Enter length of v: 4
Enter the string u: abc
Enter the string v: babc 
u: abc
v: babc
uv: abcbabc
*/