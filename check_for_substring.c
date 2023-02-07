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
int is_sub_str(char* str, int len_s, char* sub_str, int len_ss){
    int flag;
    for(int i = 0; i <= (len_s - len_ss); i++){
        flag = 1;
        for(int j = 0; j < len_ss; j++){
            if(str[i+j] != sub_str[j]){
                flag = 0;
                break;
            }
        }
        if(flag == 1)
            return 1;
    }
    return 0;
}
int main(){
    int len_s, len_ss;
    printf("Enter the length of string: ");
    scanf("%d", &len_s);
    printf("Enter the string: ");
    char* str = input_str(len_s);
    printf("Enter the length of sub-string: ");
    scanf("%d", &len_ss);
    while(len_ss > len_s){
        printf("Substring should have smaller length than the string\nRe-enter length of sub-string: ");
        scanf("%d", &len_ss);
    }
    printf("Enter the sub-string: ");
    char* sub_str = input_str(len_ss);
    printf("u: ");
    print_str(str, len_s);
    printf("v: ");
    print_str(sub_str, len_ss);
    printf("v is a substring of u : %s", is_sub_str(str, len_s, sub_str, len_ss) ? "Yes" : "No");
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\check_for_substring.exe .\check_for_substring.c
PS D:\Junior\Study\Finite_Automata> .\check_for_substring.exe
Enter the length of string: 5
Enter the string: abaab
Enter the length of sub-string: 7
Substring should have smaller length than the string
Re-enter length of sub-string: 3
Enter the sub-string: bab
u: abaab
v: bab
v is a substring of u : No
PS D:\Junior\Study\Finite_Automata> .\check_for_substring.exe
Enter the length of string: 6
Enter the string: aabbab
Enter the length of sub-string: 2 
Enter the sub-string: ab
u: aabbab
v: ab
v is a substring of u : Yes
*/
//
