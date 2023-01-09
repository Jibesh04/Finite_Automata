#include <stdio.h>
#include <stdlib.h>
int len(char* str){
    int ans = 0;
    while(str[ans])
        ans++;
    return ans;
}
int main(){
    int n = len("Hello World");
    printf("%d\n", n);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\length_of_a_string.exe .\length_of_a_string.c
PS D:\Junior\Study\Finite_Automata> .\length_of_a_string.exe
11
*/