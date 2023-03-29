#include <stdio.h>
#include <stdlib.h>

#define N_STATE 4
#define N_SYM 3

char * process_str(char * str, int len){
	char * temp = (char*) malloc(sizeof(char) * (len + 2));
	temp[0] = '/';
	temp[len + 1] = '/';
	for(int i = 1; i < len + 1; i++)
		temp[i] = str[i - 1];
	return temp;
}

void display_tape(char * s, int tape_head, int len){
	printf("TAPE: ");
	for(int i = tape_head; i < len; i++)
		printf("|%c", s[i]);
	printf("|%c|\n", s[len]);
}

void run_tm(char * str, int len){
	char *s = process_str(str, len);
	len += 2;
	int tm[N_STATE][N_SYM][3] = {{{0, -1, 1}, {1, 1, 0}, {2, 1, 0}}, {{0, 1, 3}, {1, -1, 1}, {2, -1, 2}}, {{0, 1, 3}, {2, -1, 2}, {1, -1, 2}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
	int tape_head = 1, cst = 0, halt_state = 3;
	char read_char;
	while(cst != halt_state){
		read_char = s[tape_head];
		s[tape_head] = tm[cst][read_char - '/'][0] + '/';
		tape_head += tm[cst][read_char - '/'][1];
		printf("Q%d -> ", cst);
		cst = tm[cst][read_char - '/'][2];
	}
	printf("Q%d\n", cst);
	display_tape(s, tape_head, len - 2);
}

int main(){
	int len = 10;
	char str[] = "1011010000";
	// int len = 4;
	// char str[] = "0000";
	printf("Turing Machine is implemented to find 2's Complement\n");
	run_tm(str, len);
	return 0;
}

/* TERMINAL
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ gcc TM1.c 
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ ./a.out 
TAPE: |0|1|0|0|1|1|0|0|0|0|

cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ gcc TM1.c 
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ ./a.out 
Turing Machine is implemented to find 2's Complement
Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q1 -> Q1 -> Q1 -> Q1 -> Q1 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3
TAPE: |0|1|0|0|1|1|0|0|0|0|

cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ gcc TM1.c 
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ ./a.out 
Turing Machine is implemented to find 2's Complement
Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q1 -> Q1 -> Q1 -> Q1 -> Q1 -> Q3
TAPE: |0|0|0|0|
*/
