#include <stdio.h>
#include <string.h>

#define N_SYM 2
#define N_STATE 5
char dfa[N_STATE][N_SYM] = {{'1', '2'}, {'0', '3'}, {'1', '2'}, {'2', '0'}, {'1', '2'}};
int final_state[N_STATE] = {0, 0, 0, 1, 0};

int visited[N_STATE] = {0};
int active[N_STATE] = {1};
int n_st_min = 0;

int cnt = 0;
// STEP - 1
// TERMINATE STATES THAT CANNOT BE REACHED FROM START STATE, INITIAL CALL SHOULD BE WITH 0
void check_reachability(char curr_state){
    printf("Called %d time%c\nThis time for %c\n", ++cnt, (cnt == 0) ? '\0' : 's', curr_state);
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

void replace(char x, char y){
    for(int i = 0; i < N_STATE; i++)
        for(int j = 0; j < N_SYM; j++)
            if(dfa[i][j] == x)
                dfa[i][j] = y;
}

// STEP - 2
// REMOVE NON_FINAL STATES WITH COMMON TRANSITIONS
void remove_common(){
    for(int i = 0; i < N_STATE; i++){
        if(final_state[i] || !visited[i])
            continue;
        for(int j = i + 1; j < N_STATE; j++){
            /*
            if(final_state[i] || !visited[j])
                continue;
            */
            int flag = 1;
            for(int k = 0; k < N_SYM; k++)
                if(dfa[i][k] != dfa[j][k])
                    flag = 0;
            if(flag){
                active[j] = 0;
                replace(j - '0', i - '0');
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
}

// STEP - 4
// PRINT THE MINIMIZED DFA
void print_min_dfa(){
    printf("Number of states in minimized DFA: %d\n", n_st_min);
    printf("STATES\\IP");
    for(int i = 0; i < N_SYM; i++)
        printf("\t%d", i);
    printf("\n");
    for(int i = 0; i < N_STATE; i++){
        if(!active[i])
            continue;
        printf("\tQ%d\t", i);
        for(int j = 0; j < N_SYM; j++)
            printf("%c\t", dfa[i][j]);
        printf("\n");
    }
}

// INTEGRATE
void minimize_dfa(){
    check_reachability('0');
    remove_common();
    calc_n_state_min();
    print_min_dfa();
}

// THE MAIN FUNCTION
int main(){
    minimize_dfa();
    return 0;
}