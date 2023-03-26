/* Implement a PDA that accepts L = {0^n1^n : n >= 0} */
#include <iostream>
#include <cstdlib>
#include <stack>

#define N_ST 5
#define N_SYM 3
#define N_ST_SYM 2

using namespace std;

int input_size(char * stmt){
    printf("%s", stmt);
    int n;
    scanf("%d", &n);
    return n;
}

char * input_str(int size, char* stmt){
    printf("%s", stmt);
    if(!size)
        return "/";
    char * str = (char*)malloc((size + 1) * sizeof(char));
    scanf("%s", str);
    str[size] = '/';
    return str;
}

void perform_action(stack<char> &st, char opcode){
    switch(opcode){
        case '0': // DO NOTHING
            break;
        case '1': // PUSH 0
            st.push('0');
            break;
        case '2': // POP
            st.pop();
            break;
        // case 3: // HALT AND REJECT
        //     halt_flag = 1;
        //     printf("String Rejected\n");
        //     break;
        // case 4: // HALT AND ACCEPT
        //     halt_flag = 1;
        //     printf("String Accepted\n");
        //     break;
    }
}

int is_in(char cst, char * fst, int mod){
    for(int i = 0; i < mod; i++)
        if(cst == fst[i])
            return 1;
    return 0;
}

void print_pda(char tt[N_ST][N_SYM][N_ST_SYM], char opc[N_ST][N_SYM][N_ST_SYM], char *fst, int mod_f){
    char *line = "----------------------------------------------------------------------\n";
    printf("\n\tCS: Current State\n\tIP: Input Character\n\tST: Stack Top\n\tNS: Next State\n\tOC: Operation Code\n");
    printf("STATES\n\t-> represents start state\n\t * represents final state\n\t - represents dead state\n");
    printf("OPCODES\n\t0 represents no change\n\t1 represents PUSH(0)\n\t2 represents POP()\n");
    printf("%24c____PDA TRANSITION TABLE____\n");
    printf("%s", line);
    printf("%4cIP%2c", '\0', '\0');
    for(int i = 0; i < N_SYM; i++)
        printf("%16c'%c'", '\0', i + '/');
    printf("\n%2cCS\\ST%1c", '\0', '\0');
    for(int i = 0; i < N_SYM; i++)
        for(int j = 0; j < N_ST_SYM; j++)
            printf("%8c'%c'", '\0', j + '/');
    printf("\n%9c", '\0');
    for(int i = 0; i < N_SYM; i++)
        for(int j = 0; j < N_ST_SYM; j++)
            printf("%6cNS%2cOC", '\0', '\0');
    printf("\n");
    printf("%s", line);
    for(int i = 0; i < N_ST; i++){
        if(i == 0)
            printf("%2c->Q%d%4c", '\0', i, '\0');
        else if(i == N_ST - 1)
            printf("%3c-Q%d%4c", '\0', i, '\0');
        else if(is_in(i + '0', fst, mod_f))
            printf("%3c*Q%d%4c", '\0', i, '\0');
        else
            printf("%4cQ%d%4c", '\0', i, '\0');
        for(int j = 0; j < N_SYM; j++)
            for(int k = 0; k < N_ST_SYM; k++)
                printf("%6cQ%c%3c%c", '\0', (char)tt[i][j][k], '\0', (char)opc[i][j][k]);
        printf("\n");
    }
    printf("%s", line);
}

void print_stack(stack<char> st){
    int n = st.size();
    printf("STACK: ");
    for(int i = 0; i < n; i++, st.pop())
        printf("%c ", st.top());
    printf("\n");
}

void print_str(char * str, int size){
    for(int i = 0; i < size; i++)
        printf("%c", str[i]);
}

void check_acceptance(){
    int size;
    char * str;
    printf("\nLanguage, L = {0^n1^2n | n >= 1}\n");
    char trans_table[N_ST][N_SYM][N_ST_SYM] = {{{'4', '4'}, {'0', '0'}, {'4', '1'}}, {{'4', '4'}, {'4', '4'}, {'4', '2'},}, {{'3', '4'}, {'4', '4'}, {'4', '1'}}, {{'4', '4'}, {'4', '4'}, {'4', '4'}}, {{'4', '4'}, {'4', '4'}, {'4', '4'}}};
    char opcode[N_ST][N_SYM][N_ST_SYM] = {{{'0', '0'}, {'1', '1'}, {'0', '0'}}, {{'0', '0'}, {'0', '0'}, {'0', '2'}}, {{'0', '0'}, {'0', '0'}, {'0', '0'}}, {{'0', '0'}, {'0', '0'}, {'0', '0'}}, {{'0', '0'}, {'0', '0'}, {'0', '0'}}};
    char curr_state = '0', curr_top;
    char final_states[] = {'3'};
    int mod_f = sizeof(final_states)/sizeof(curr_state);
    print_pda(trans_table, opcode, final_states, mod_f);
    
    int t = input_size("Enter the number of test cases: ");
    while(t--){
        size = input_size("Enter the string length: ");
        if(size == 0)
            str = input_str(0, "");
        else
            str = input_str(size, "Enter the string: ");
        stack<char> st;
        st.push('/');
        curr_state = '0';
        for(int i = 0; i <= size; i++){

            /*printf("Input: %c\t", str[i]);
            printf("Stack Top: %c\n", st.top()); */

            curr_top = st.top();
            printf("Q%c -> ", curr_state);
            // printf("Q%c -(%c, %c|", curr_state, str[i], curr_top);
            // printf("%c(Q%c, %c, %c) = ", 235, curr_state, str[i], curr_top);
            perform_action(st, opcode[curr_state - '0'][str[i] - '/'][st.top() - '/']);

            /*printf("CURR STATE: Q%c -> ", curr_state);
            printf("\tOPCODE: %c", opcode[curr_state - '0'][str[i] - '/'][st.top() - '/']);
            printf("\tNEXT STATE: Q%c\n", trans_table[curr_state - '0'][str[i] - '/'][st.top() - '/']);
            */
            // print_stack(st);
            curr_state = trans_table[curr_state - '0'][str[i] - '/'][curr_top - '/'];
            // printf("(Q%c, %c)\n", curr_state, st.top());
            // printf("%c)-> ", st.top());
        }
        printf("Q%c\n", curr_state);
        if(is_in(curr_state, final_states, mod_f)){
            print_str(str, size);
            printf(" is ACCEPTED\n", str);
        }
        else{
            print_str(str, size);
            printf(" is REJECTED\n", str);
        }
        free(str);
        while(!st.empty())
            st.pop();
    }
}

int main(){
    check_acceptance();
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> g++ -o .\0^n_1^2n.exe .\0^n_1^2n.cpp
.\0^n_1^2n.cpp: In function 'char* input_str(int, char*)':
.\0^n_1^2n.cpp:22:16: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
         return "/";
                ^~~
.\0^n_1^2n.cpp: In function 'void print_pda(char (*)[3][2], char (*)[3][2], char*, int)':
.\0^n_1^2n.cpp:58:18: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     char *line = "----------------------------------------------------------------------\n";
                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
.\0^n_1^2n.cpp: In function 'void check_acceptance()':
.\0^n_1^2n.cpp:118:58: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
     int t = input_size("Enter the number of test cases: ");
                                                          ^
.\0^n_1^2n.cpp:120:54: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
         size = input_size("Enter the string length: ");
                                                      ^
.\0^n_1^2n.cpp:122:34: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
             str = input_str(0, "");
                                  ^
.\0^n_1^2n.cpp:124:55: warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
             str = input_str(size, "Enter the string: ");
                                                       ^
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> .\0^n_1^2n.exe

Language, L = {0^n1^2n | n >= 1}

        CS: Current State
        IP: Input Character
        ST: Stack Top
        NS: Next State
        OC: Operation Code
STATES
        -> represents start state
         * represents final state
         - represents dead state
OPCODES
        0 represents no change
        1 represents PUSH(0)
        2 represents POP()
                        ____PDA TRANSITION TABLE____
----------------------------------------------------------------------
   IP                '/'               '0'               '1'
 CS\ST       '/'       '0'       '/'       '0'       '/'       '0'
             NS OC     NS OC     NS OC     NS OC     NS OC     NS OC
----------------------------------------------------------------------
 ->Q0        Q4  0     Q4  0     Q0  1     Q0  1     Q4  0     Q1  0
   Q1        Q4  0     Q4  0     Q4  0     Q4  0     Q4  0     Q2  2
   Q2        Q3  0     Q4  0     Q4  0     Q4  0     Q4  0     Q1  0
  *Q3        Q4  0     Q4  0     Q4  0     Q4  0     Q4  0     Q4  0
  -Q4        Q4  0     Q4  0     Q4  0     Q4  0     Q4  0     Q4  0
----------------------------------------------------------------------
Enter the number of test cases: 4
Enter the string length: 0
Q0 -> Q4
 is REJECTED
Enter the string length: 3
Enter the string: 011
Q0 -> Q0 -> Q1 -> Q2 -> Q3
011 is ACCEPTED
Enter the string length: 6
Enter the string: 001111
Q0 -> Q0 -> Q0 -> Q1 -> Q2 -> Q1 -> Q2 -> Q3
001111 is ACCEPTED
Enter the string length: 6
Enter the string: 000111
Q0 -> Q0 -> Q0 -> Q0 -> Q1 -> Q2 -> Q1 -> Q4
000111 is REJECTED
*/