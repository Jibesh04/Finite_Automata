#include <stdio.h>
#include <stdlib.h>

#define N_STATE 10
#define N_SYM 4

char * process_str(char * str, int len){
	char * temp = (char*) malloc(sizeof(char) * (2*len + 2));
	temp[0] = '/';
	for(int i = len + 1; i < 2*len + 2; i++)
		temp[i] = '/';
	for(int i = 1; i < len + 1; i++)
		temp[i] = str[i - 1];
	// printf("Allocation Successful\n");
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
	len = 2*len + 2;
	int tm[N_STATE][N_SYM][3] = {{{0, 0, 0}, {1, -1, 1}, {2, 1, 0}, {3, 1, 0}}, {{0, 0, 0}, {0, 0, 0}, {0, 1, 2}, {0, 1, 5}}, {{0, 1, 2}, {2, -1, 3}, {2, 1, 2}, {3, 1, 2}}, {{0, -1, 4}, {0, 0, 0}, {2, -1, 3}, {3, -1, 3}}, {{0, -1, 4}, {1, 1, 8}, {0, 1, 2}, {0, 1, 5}}, {{0, 1, 5}, {3, -1, 6}, {2, 1, 5}, {3, 1, 5}}, {{0, -1, 7}, {0, 0, 0}, {2, -1, 6}, {3, -1, 6}}, {{0, -1, 7}, {1, 1, 8}, {0, 1, 2}, {0, 1, 5}}, {{0, 1, 8}, {0, 0, 0}, {2, 0, 9}, {3, 0, 9}}, {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}};
	int tape_head = 1, cst = 0, halt_state = 9;
	// printf("Allocation Successful\n");
	char read_char;
	while(cst != halt_state){
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
	int len = 5;
	char str[] = "10110";
	// int len = 10;
	// char str[] = "1011010000";
	// int len = 5;
	// char str[] = "01001";
	printf("Turing Machine is implemented to display wR for input w: %s\n", str);
	run_tm(str, len);
	return 0;
}

/* TERMINAL
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ gcc TM1.c 
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ ./a.out 
Turing Machine is implemented to display wR for input w: 10110
Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q1 -> Q2 -> Q3 -> Q4 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q7 -> Q7 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q4 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q9
TAPE: |0|1|1|0|1|

cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ gcc TM1.c 
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ ./a.out 
Turing Machine is implemented to display wR for input w: 1011010000
Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q1 -> Q2 -> Q3 -> Q4 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q4 -> Q4 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q4 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q9
TAPE: |0|0|0|0|1|0|1|1|0|1|

cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ gcc TM1.c 
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/CompII$ ./a.out 
Turing Machine is implemented to display wR for input w: 1011010000
Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q0 -> Q1 -> Q2 -> Q3 -> Q4 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q4 -> Q4 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q4 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q2 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q3 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q4 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q5 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q6 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q7 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q8 -> Q9
TAPE: |0|0|0|0|1|0|1|1|0|1|
*/
