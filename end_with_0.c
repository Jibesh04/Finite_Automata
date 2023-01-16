#include <stdio.h>
#include <stdlib.h>
int len(char* str){
    int ans = 0;
    while(str[ans] && str[ans] != '\n')
        ans++;
    return ans;
}
int input(char stmt[]){
    int num;
    printf("%s", stmt);
    scanf("%d", &num);
    return num;
}
char* input_str(int len, char stmt[]){
    printf("%s", stmt);
    char * str = (char *)malloc(sizeof(char) * len);
    scanf("%s", str);
    return str;
}
void print_str(char* str){
    int n = len(str);
    for(int i = 0; i < n; i++)
        printf("%c", str[i]);
    printf("\n");
}
// int* set_states(int n, int final[]){
//     int states[n];
//     for(int i = 0; i < n; i++)
//         states[i] = 0;
//     n = sizeof(final)/sizeof(int);
//     for(int i = 0; i < n; i++)
//         states[final[i] - 1] = 1;
//     return states;
// }
int is_in(int n, int * arr){
    int m = sizeof(arr)/sizeof(n);
    for(int i = 0; i < m; i++)
        if(arr[i] == n)
            return 1;
    return 0;
}
int end_with_0(char * str){
    int n = len(str);
    int final[] = {1};
    // int * states = set_states(2, final);
    int state = 0;
    for(int i = 0; i < n; i++){
        if(state == 0){
            if(str[i] == '0')
                state = 1;
        }
        else if(state == 1){
            if(str[i] == '1')
                state = 0;
        }
    }
    return is_in(state, final);
}
int main(){
    int len = input("Enter the length: ");
    char *str = input_str(len, "Enter the string: ");
    // print_str(str);
    printf("End with 0: %s", (end_with_0(str)) ? "YES" : "NO");
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\end_with_0.exe .\end_with_0.c
PS D:\Junior\Study\Finite_Automata> .\end_with_0.exe  Enter the length: 3
Enter the string: 000
End with 0: YES
PS D:\Junior\Study\Finite_Automata> .\end_with_0.exe
Enter the length: 5
Enter the string: 01010
End with 0: YES
PS D:\Junior\Study\Finite_Automata> .\end_with_0.exe
Enter the length: 4
Enter the string: 1011
End with 0: NO
PS D:\Junior\Study\Finite_Automata> .\end_with_0.exe
Enter the length: 2
Enter the string: 01
End with 0: NO
*/