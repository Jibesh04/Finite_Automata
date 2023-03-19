#include <stdio.h>
#include <string.h>

#define N_SYM 2
#define N_STATE 8
char dfa[N_STATE][N_SYM] = {{'5', '1'}, {'2', '6'}, {'2', '0'}, {'6', '2'}, {'5', '7'}, {'6', '2'}, {'4', '6'}, {'2', '6'}};
int final_state[N_STATE] = {0, 0, 1, 0, 0, 0, 0, 0};

int visited[N_STATE] = {0};
int active[N_STATE] = {1};
int n_st_min = 0;

// int cnt = 0;

// PRINT DFA
void print_dfa(){
    char horizontal_line[] = "-------------------------------";
    printf("%s\n%4cSTATES\\IP", horizontal_line, '\0');
    for(int i = 0; i < N_SYM; i++)
        printf("\t%d", i);
    printf("\n%s\n", horizontal_line);
    for(int i = 0; i < N_STATE; i++){
        if(i == 0) // Initial State
            printf("%6c->Q%d", '\0', i);
        else if(final_state[i]) // Final States
            printf("%7c*Q%d", '\0', i);
        else // Otherwise
            printf("%8cQ%d", '\0', i);
        for(int j = 0; j < N_SYM; j++)
            printf("\tQ%c", dfa[i][j]);
        printf("\n");
    }
    printf("%s\n", horizontal_line);
}

// STEP - 1
// TERMINATE STATES THAT CANNOT BE REACHED FROM START STATE, INITIAL CALL SHOULD BE WITH 0
void check_reachability(char curr_state){
    // printf("Called %d time%c\nThis time for %c\n", ++cnt, (cnt == 0) ? '\0' : 's', curr_state);
    visited[curr_state - '0'] = 1;
    for(int i = 0; i < N_STATE; i++){
        if(!visited[i])
            continue;
        for(int i = 0; i < N_SYM; i++)
            if(!visited[dfa[curr_state - '0'][i] - '0']){
                visited[dfa[curr_state - '0'][i] - '0'] = 1;
                check_reachability(dfa[curr_state - '0'][i]);
            }
    }
}
void terminate_non_reachables(){
    check_reachability('0');
    for(int i = 0; i < N_STATE; i++)
        if(!visited[i]){
            active[i] = 0;
            printf("Q%d terminated\n", i);
        }
        else
            active[i] = 1;
}

// STEP - 2
// REMOVE NON_FINAL STATES WITH COMMON TRANSITIONS
void replace(char x, char y){
    for(int i = 0; i < N_STATE; i++)
        for(int j = 0; j < N_SYM; j++)
            if(dfa[i][j] == x){
                dfa[i][j] = y;
                // printf("Replaced %c with %c\n", x, y);
            }
    printf("Removed Q%c and Replaced it with Q%c\n", x, y);
}

void remove_common(){
    for(int i = 0; i < N_STATE; i++){
        if(final_state[i] || !active[i])
            continue;
        for(int j = i + 1; j < N_STATE; j++){
            if(final_state[j] || i == j || !active[j])
                continue;
            // printf("Comparing Q%c with Q%c\n", i + '0', j + '0');
            int flag = 1;
            // printf("Reached here..\n");
            for(int k = 0; k < N_SYM; k++)
                if(dfa[i][k] != dfa[j][k])
                    flag = 0;
            if(flag){
                active[j] = 0;
                replace(j + '0', i + '0');
                remove_common();
            }
        }
    }
}

// STEP - 3
// CALCULATE NUMBER OF STATES IN MINIMIZED DFA
void calc_n_state_min(){
    for(int i = 0; i < N_STATE; i++)
        if(active[i])
            n_st_min++;
    printf("Number of states in minimized DFA: %d\n", n_st_min);
}

// STEP - 4
// PRINT THE MINIMIZED DFA
void print_min_dfa(){
    char horizontal_line[] = "-------------------------------";
    printf("%s\n%4cSTATES\\IP", horizontal_line, '\0');
    for(int i = 0; i < N_SYM; i++)
        printf("\t%d", i);
    printf("\n%s\n", horizontal_line);
    for(int i = 0; i < N_STATE; i++){
        if(!active[i])
            continue;
        if(i == 0) // Initial State
            printf("%6c->Q%d", '\0', i);
        else if(final_state[i]) // Final States
            printf("%7c*Q%d", '\0', i);
        else // Otherwise
            printf("%8cQ%d", '\0', i);
        for(int j = 0; j < N_SYM; j++)
            printf("\tQ%c", dfa[i][j]);
        printf("\n");
    }
    printf("%s\n", horizontal_line);
}

// INTEGRATE
void minimize_dfa(){
    printf("GIVEN DFA IS GIVEN BY:\n");
    print_dfa();
    printf("STEP - 1: TERMINATION OF UNREACHABLE STATES\n");
    terminate_non_reachables();
    printf("STEP - 2: REMOVAL OF NON-FINAL STATES WITH COMMON TRANSITION\n");
    remove_common();
    printf("STEP - 3: CALCULATION OF NUMBER OF STATES IN MINIMIZED DFA\n");
    calc_n_state_min();
    printf("STEP - 4: DISPLAYING THE MINIMIZED DFA\n");
    print_min_dfa();
}

// THE MAIN FUNCTION
int main(){
    printf("\n");
    minimize_dfa();
    printf("\n");
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o dfa_minimization_ex2.exe .\dfa_minimization_ex2.c
PS D:\Junior\Study\Finite_Automata> .\dfa_minimization_ex2.exe

GIVEN DFA IS GIVEN BY:
-------------------------------
   STATES\IP    0       1
-------------------------------
     ->Q0       Q5      Q1
       Q1       Q2      Q6
      *Q2       Q2      Q0
       Q3       Q6      Q2
       Q4       Q5      Q7
       Q5       Q6      Q2
       Q6       Q4      Q6
       Q7       Q2      Q6
-------------------------------
STEP - 1: TERMINATION OF UNREACHABLE STATES
Q3 terminated
STEP - 2: REMOVAL OF NON-FINAL STATES WITH COMMON TRANSITION
Removed Q7 and Replaced it with Q1
Removed Q4 and Replaced it with Q0
STEP - 3: CALCULATION OF NUMBER OF STATES IN MINIMIZED DFA
Number of states in minimized DFA: 5
STEP - 4: DISPLAYING THE MINIMIZED DFA
-------------------------------
   STATES\IP    0       1
-------------------------------
     ->Q0       Q5      Q1
       Q1       Q2      Q6
      *Q2       Q2      Q0
       Q5       Q6      Q2
       Q6       Q0      Q6
-------------------------------

 */