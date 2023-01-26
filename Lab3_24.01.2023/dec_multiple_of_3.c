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

int bin_to_dec(char* binary, int len){
    int decimal = 0, mult = 1;
    for(int i = len - 1; i >= 0 ; i--){
        decimal += mult * (binary[i] - '0');
        mult *= 2;
    }
    return decimal;
}

int div_by_3(char str[], int len){
    int DFA[][2] = {{0, 1}, {2, 0}, {1, 2}};
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
    printf("%s has decimal equivalent %d multiple of 3: %s\n", str, bin_to_dec(str, len), div_by_3(str, len) ? "YES" : "NO");
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> gcc -o dec_multiple_of_3.exe .\dec_multiple_of_3.c
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> .\dec_multiple_of_3.exe
Enter the length of the string: 5
Enter the string: 10101
10101 has decimal equivalent 21 multiple of 3: YES
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> .\dec_multiple_of_3.exe
Enter the length of the string: 4   
Enter the string: 1100
1100 has decimal equivalent 12 multiple of 3: YES
PS D:\Junior\Study\Finite_Automata\Lab3_24.01.2023> .\dec_multiple_of_3.exe
Enter the length of the string: 3
Enter the string: 101
101 has decimal equivalent 5 multiple of 3: NO
*/