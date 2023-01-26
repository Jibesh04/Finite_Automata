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

int end_with_0(char str[], int len){
    int DFA[][2] = {{1, 0}, {1, 0}};
    int final_state[] = {1};
    int mod_f = sizeof(final_state) / sizeof(int);
    int curr_state = 0;
    for(int i = 0; i < len; i++)
        curr_state = DFA[curr_state][str[i] - '0'];
    return is_in(curr_state, final_state, mod_f);
}

int main(){
    int len = input("Enter the length of the string: ");
    char * str = input_str(len, "Enter the string: ");
    printf("%s ends with 0: %s\n", str, end_with_0(str, len) ? "YES" : "NO");
    return 0;
}

/* TERMINAL
PS H:\Gallery\Lab Works> gcc .\DFA.c
PS H:\Gallery\Lab Works> .\a.exe
Enter the length of the string: 5
Enter the string: 11110
11110 ends with 0: YES
PS H:\Gallery\Lab Works> .\a.exe
Enter the length of the string: 7
Enter the string: 0101001
0101001 ends with 0: NO
*/