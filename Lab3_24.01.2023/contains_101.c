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

int contains_101(char str[], int len){
    int DFA[][2] = {{0, 1}, {2, 1}, {0, 3}, {3, 3}};
    int final_state[] = {3};
    int mod_f = sizeof(final_state) / sizeof(int);
    int curr_state = 0;
    for(int i = 0; i < len; i++)
        curr_state = DFA[curr_state][str[i] - '0'];
    return is_in(curr_state, final_state, mod_f);
}

int main(){
    int len = input("Enter the length of the string: ");
    char * str = input_str(len, "Enter the string: ");
    printf("%s contains 101: %s\n", str, contains_101(str, len) ? "YES" : "NO");
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> gcc -o contains_101.exe .\contains_101.c
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> .\contains_101.exe
Enter the length of the string: 5
Enter the string: 11010
11010 contains 101: YES
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> .\contains_101.exe
Enter the length of the string: 4
Enter the string: 0110
0110 contains 101: NO
*/