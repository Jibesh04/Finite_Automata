#include <stdio.h>
#include <stdlib.h>

char * input_str(int len, char * stmt){
    printf("%s", stmt);
    char* string = (char*)malloc(sizeof(char) * len);
    scanf("%s", string);
    return string;
}

int input(char * stmt){
    printf("%s", stmt);
    int n;
    scanf("%d", &n);
    return n;
}

int is_in(int n, int arr[], int size){
    for(int i = 0; i < size; i++)
        if(n == arr[i])
            return 1;
    return 0;
}

int even_0_even_1(char str[], int len){
    int DFA[][2] = {{1, 3}, {0, 2}, {3, 1}, {2, 0}};
    int final_state[] = {0};
    int mod_f = sizeof(final_state) / sizeof(int);
    int curr_state = 0;
    for(int i = 0; i < len; i++)
        curr_state = DFA[curr_state][str[i] - '0'];
    return is_in(curr_state, final_state, mod_f);
}

int main(){
    int len = input("Enter the length of the string: ");
    char * str = input_str(len, "Enter the string: ");
    printf("%s contains even 0's and even 1's: %s\n", str, even_0_even_1(str, len) ? "YES" : "NO");
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> gcc -o even_0_even_1.exe .\even_0_even_1.c
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> .\even_0_even_1.exe
Enter the length of the string: 5
Enter the string: 01011
01011 contains even 0's and even 1's: NO
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> .\even_0_even_1.exe
Enter the length of the string: 4   
Enter the string: 1010
1010 contains even 0's and even 1's: YES
*/