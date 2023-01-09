#include <stdio.h>
#include <stdlib.h>
int len(char* str){
    int ans = 0;
    while(str[ans])
        ans++;
    return ans;
}
char* concat(char *u, char *v){
    int len_uv = len(u) + len(v);
    char* uv = (char*)malloc(len_uv * sizeof(char));
    int i = 0;
    while(u[i]){
        uv[i] = u[i];
        i++;
    }
    int j = 0;
    while(v[j]){
        uv[i] = v[j];
        i++; j++;
    }
    return uv;
}
void print_str(char* str){
    int n = len(str);
    for(int i = 0; i < n; i++)
        printf("%c", str[i]);
    printf("\n");
}
int main(){
    char *u = "Hello", *v = " World";
    char* uv = concat(u, v);
    print_str(uv);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\concatenation_of_strings.exe .\concatenation_of_strings.c
PS D:\Junior\Study\Finite_Automata> .\concatenation_of_strings.exe
Hello World
*/