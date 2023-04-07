/* Program for DFA that recognizes the language
L = {set of all strings over {0, 1} that contains at least one instance of strictly 2 consequtive zeros} */
#include <stdio.h>
#include <string.h>

char is_in_fst(char ist, char * fst, int mod_f){
    for(int i = 0; i < mod_f; i++)
        if(fst[i] == ist)
            return '1';
    return '\0';
}

void print_tt(int N_STATE, char dfa[][2], char ist, char fst[], char dst, int mod_f){
    // ist -> q0 -> initial state
    // fst -> set of final states
    // dst -> dead state / self-loop
    printf("STATE\\INP%4c'0'%7c'1'%4c\n", '\0', '\0', '\0');
    for(int i = 0; i < N_STATE; i++){
        if(i == ist - '0')
            printf("%3c->q%d%4c", '\0', i, '\0');
        else if(i == dst - '0')
            printf("%4c_q%d%4c", '\0', i, '\0');
        else if(is_in_fst(i + '0', fst, mod_f))
            printf("%4c*q%d%4c", '\0', i, '\0');
        else
            printf("%5cq%d%4c", '\0', i, '\0');
        printf("%4cq%c%8cq%c%4c\n", '\0', dfa[i][0], '\0', dfa[i][1], '\0');
    }
}

void check_acceptance(int t){
    char ist = '0';
    int N_STATE = 6, mod_f = 3;
    char dfa[][2] = {{'1', '0'}, {'2', '0'}, {'5', '3'}, {'4', '3'}, {'2', '3'}, {'5', '5'}};
    char fst[] = {'2', '3', '4'};
    char dst = '5';
    print_tt(N_STATE, dfa, ist, fst, dst, mod_f);
    while(t--){
        char s[100];
        printf("Enter the string: ");
        scanf("%s", s);
        char cst = ist;
        for(int i = 0; i < strlen(s); i++){
            printf("q%c -> ", cst);
            cst = dfa[cst - '0'][s[i] - '0'];
        }
        printf("q%c\n", cst);
        if(is_in_fst(cst, fst, mod_f))
            printf("%s is Accepted\n", s);
        else
            printf("%s is Rejected\n", s);
    }
}

int main(){
    unsigned short int t;
    printf("Enter number of testcases: ");
    scanf("%hu", &t);
    check_acceptance(t);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> .\two_zeros.exe
Enter number of testcases: 3
STATE\INP   '0'      '1'   
  ->q0      q1       q0   
    q1      q2       q0   
   *q2      q5       q3   
   *q3      q4       q3   
   *q4      q2       q3   
   _q5      q5       q5   
Enter the string: 00
q0 -> q1 -> q2
00 is Accepted
Enter the string: 010010001
q0 -> q1 -> q0 -> q1 -> q2 -> q3 -> q4 -> q2 -> q5 -> q5
010010001 is Rejected
Enter the string: 101001
q0 -> q0 -> q1 -> q0 -> q1 -> q2 -> q3
101001 is Accepted
*/