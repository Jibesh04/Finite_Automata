#include <stdio.h>
#include <stdlib.h>
void print_str(char* str){
    int i = 0;
    while(str[i]){
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
}
int main(){
    char A[] = "Namaskaram";
    print_str(A);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\print_a_string.exe .\print_a_string.c
PS D:\Junior\Study\Finite_Automata> .\print_a_string.exe
Namaskaram
*/