/* Implement a PDA that accepts L = {0^n1^n : n >= 0} */
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct stack{
    unsigned top, capacity;
    char *stack_arr;
}stack;

stack * createStack(int n){
    stack *temp = (stack*)malloc(sizeof(stack));
    temp -> capacity = n;
    temp -> top = -1;
    temp -> stack_arr = (char*)malloc(n * sizeof(char));
    return temp;
}

int isEmpty(stack * st){
    return (st -> top == -1);
}

void push_to_stack(stack * st, char c){
    if(st -> top < st -> capacity)
        st -> stack_arr[++(st -> top)] = c;
    printf("PUSH CALLED\n");
}

char pop_from_stack(stack * st){
    if(!isEmpty(st))
        (st -> top)--;
    printf("POP CALLED\n");
    return (st -> stack_arr[(st -> top) + 1]);
}

char stack_top(stack * st){
    if(isEmpty(st))
        return '$';
    return st -> stack_arr[st -> top];
}

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

void perform_action(stack * st, char opcode){
    switch(opcode){
        case '0': // DO NOTHING
            break;
        case '1': // PUSH 0
            push_to_stack(st, '0');
            break;
        case '2': // POP
            pop_from_stack(st);
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

void check_acceptance(char * str, int size){
    char trans_table[4][3][2] = {{"23", "00", "31"}, {"23", "33", "31",}, {"33", "33", "33"}, {"33", "33", "33"}};
    char opcode[4][3][2] = {{"00", "11", "02"}, {"00", "00", "02"}, {"00", "00", "00"}, {"00", "00", "00"}};
    char curr_state = '0';
    char final_states[] = {'2'};
    int mod_f = sizeof(final_states)/sizeof(curr_state);
    stack * st = createStack(MAX);
    push_to_stack(st, '/');
    for(int i = 0; i <= size; i++){
        printf("OPCODE: %c\n", opcode[curr_state - '0'][str[i] - '/'][stack_top(st) - '/']);
        perform_action(st, opcode[curr_state - '0'][str[i] - '/'][stack_top(st) - '/']);
        printf("Q%c -> ", curr_state);
        curr_state = trans_table[curr_state - '0'][str[i] - '/'][stack_top(st) - '/'];
    }
    printf("Q%c\n", curr_state);
    if(is_in(curr_state, final_states, mod_f))
        printf("%s is ACCEPTED\n", str);
    else
        printf("%s is REJECTED\n", str);
}

int main(){
    int size;
    char * str;
    int t = input_size("Enter the number of test cases: ");
    while(t--){
        size = input_size("Enter the string length: ");
        if(size == 0)
            str = input_str(0, "");
        else
            str = input_str(size, "Enter the string: ");
        check_acceptance(str, size);
    }
    return 0;
}