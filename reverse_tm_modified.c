#include <stdlib.h>
#define N_STATE 7
#define N_SYM 4
char *process_str(char *str, int len){
    char *temp = (char *)malloc(sizeof(char) * (2 * len + 2));
    temp[0] = '/';
    for (int i = len + 1; i < 2 * len + 2; i++)
        temp[i] = '/';
    for (int i = 1; i < len + 1; i++)
        temp[i] = str[i - 1];
    return temp;
}
void display_tape(char *s, int tape_head, int len){
    printf("TAPE: ");
    for (int i = tape_head; i < len; i++)
        printf("|%c", s[i]);
    printf("|%c|\n", s[len]);
}
void run_tm(char *str, int len){
    char *s = process_str(str, len);
    len = 2 * len + 2;
    int tm[N_STATE][N_SYM][3] = {{{0, 0, 0}, {1, -1, 1}, {2, 1, 0}, {3, 1, 0}}, {{0, -1, 1}, {1, 1, 5}, {0, 1, 2}, {0, 1, 3}}, {{0, 1, 2}, {2, -1, 4}, {2, 1, 2}, {3, 1, 2}}, {{0, 1, 3}, {3, -1, 4}, {2, 1, 3}, {3, 1, 3}},{{0, -1, 1} ,{0 ,0 ,0} ,{2, -1, 4},{3, -1, 4}},{{1, 1, 5}, {0, 0, 0}, {2, 0, 6}, {3, 0, 6}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
    int tape_head = 1, cst = 0, halt_state = 6;
    char read_char;
    while (cst != halt_state){
        read_char = s[tape_head];
        printf("Q%d -> ", cst);
        s[tape_head] = tm[cst][read_char - '.'][0] + '.';
        tape_head += tm[cst][read_char - '.'][1];
        cst = tm[cst][read_char - '.'][2];
    }
    printf("Q%d\n", cst);
    display_tape(s, tape_head, len - 2);
}
int main(){
    int len = 4;
    char str[] = "1011";
    printf("Turing Machine is implemented to display wR for input w: %s\n", str);
    run_tm(str, len);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o reverse_tm_modified.exe .\reverse_tm_modified.c
.\reverse_tm_modified.c: In function 'display_tape':
.\reverse_tm_modified.c:14:5: warning: implicit declaration of function 'printf' [-Wimplicit-function-declaration]
     printf("TAPE: ");
     ^~~~~~
.\reverse_tm_modified.c:14:5: warning: incompatible implicit declaration of built-in function 'printf'
.\reverse_tm_modified.c:14:5: note: include '<stdio.h>' or provide a declaration of 'printf'  
.\reverse_tm_modified.c:2:1:
+#include <stdio.h>
 #define N_STATE 7
.\reverse_tm_modified.c:14:5:
     printf("TAPE: ");
     ^~~~~~
.\reverse_tm_modified.c: In function 'run_tm':
.\reverse_tm_modified.c:27:9: warning: incompatible implicit declaration of built-in function 'printf'
         printf("Q%d -> ", cst);
         ^~~~~~
.\reverse_tm_modified.c:27:9: note: include '<stdio.h>' or provide a declaration of 'printf'  
.\reverse_tm_modified.c:32:5: warning: incompatible implicit declaration of built-in function 'printf'
     printf("Q%d\n", cst);
     ^~~~~~
.\reverse_tm_modified.c:32:5: note: include '<stdio.h>' or provide a declaration of 'printf'  
.\reverse_tm_modified.c: In function 'main':
.\reverse_tm_modified.c:38:5: warning: incompatible implicit declaration of built-in function 'printf'
     printf("Turing Machine is implemented to display wR for input w: %s\n", str);
     ^~~~~~
.\reverse_tm_modified.c:38:5: note: include '<stdio.h>' or provide a declaration of 'printf'  
PS D:\Junior\Study\Finite_Automata> .\reverse_tm_modified.exe
Turing Machine is implemented to display wR for input w: 1011
Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q1 -> Q3 -> Q4 -> Q1 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q1 -> Q1 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q4 -> Q4 -> Q4 -> Q1 -> Q1 -> Q1 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q4 -> Q1 -> Q1 -> Q1 -> Q1 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6
TAPE: |1|1|0|1|
*/