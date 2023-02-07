#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to input a number
int input(char* stmt){
	int n;
	printf("%s", stmt);
	scanf("%d", &n);
	return n;
}

// Function to input the string
char* input_str(int len, char* stmt){
	if(!len)
		return '\0';
	char * str = (char*) malloc(sizeof(char)*len);
	printf("%s", stmt);
	scanf("%s", str);
	return str;
}

// Function to check if current state is one of the final states
int is_in(int st, int* arr){
	int len = sizeof(arr)/sizeof(int);
	for(int i = 0; i < len; i++)
		if(arr[i] == st)
			return 1;
	return 0;
}

// Recursive Function
void helper(char * str, int len, char table[][2][1], int idx, int curr, int * final_states){
	if(idx > len - 1){
		return;
	}
	printf("Q%d --%c--> ", curr, str[idx]);
	for(int i = 0; i < strlen(table[curr][str[idx] - 'a']); i++){
		//printf("Current State: %d\tstr[%d] = %c\ti = %d\n", curr, idx, str[idx], i);
		if(i)
			printf("___\n\n");
		curr = (table[curr][str[idx] - 'a'][i] - '0');
		printf("Q%d\n", curr);
		if(idx == len - 1){
			// printf("Reached String End\n");
			if(is_in(curr, final_states))
				printf("\nAccepted\n");
		}
		helper(str, len, table, idx + 1, curr, final_states);
	}
	printf("\n");
}

// Function to implement the NFA
void solve(char * str, int len){
	char table[][2][1] = {{"1", "3"}, {"", "2"}, {"", ""}, {"2", ""}};
	int final_states[] = {2};
	helper(str, len, table, 0, 0, final_states);
}

// The main function
int main(){
	int len = input("Enter the length of the string: ");
	char * str = input_str(len, "Enter the string: ");
	solve(str, len);
	return 0;
}

/* TERMINAL
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/Comp_II/NFA$ gcc -o E5P1.exe E5P1.c
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/Comp_II/NFA$ ./E5P1.exe
Enter the length of the string: 2
Enter the string: ab
Q0 --a--> Q1
Q1 --b--> Q2

Accepted


cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/Comp_II/NFA$ ./E5P1.exe
Enter the length of the string: 3
Enter the string: bab
Q0 --b--> Q3
Q3 --a--> Q2
Q2 --b-->


*/
