/* Write a program to design a DFA for the language
(i) L = {w : n_a(w) = 1, w belongs to (a, b)*} 
(ii) L = {w : n_a(w) > 1, w belongs to (a, b)*}
(iii) L = {w : n_a(w) >= 1 and n_b(w) = 2, w belongs to (a, b)*}
(iv) L = {w_1abw_2 : w_1, w_2 belong to (a, b)*}
*/
#include <stdio.h>
#include <stdlib.h>

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
int is_in(int st, int arr[], int len){
	for(int i = 0; i < len; i++)
		if(arr[i] == st)
			return 1;
	return 0;
}

// DFA 1 that accepts bit(i)
int n_a_equals_to_1(char* str, int len){
	int trans_1[][2] = {{1, 0}, {2, 1}, {2, 2}};
	int curr_state = 0;
	int final_state[] = {1};
	int mod_f = sizeof(final_state)/sizeof(curr_state); 
	for(int i = 0; i < len; i++){
		printf("Q%d -> ", curr_state);
		curr_state = trans_1[curr_state][str[i] - 'a'];
	}
	printf("Q%d\n", curr_state);
	return is_in(curr_state, final_state, mod_f);
}

// DFA 2 that accepts bit(ii)
int multiple_a(char* str, int len){
	int trans_2[][2] = {{1, 0}, {2, 1}, {2, 2}};
	int curr_state = 0;
	int final_state[] = {2};
	int mod_f = sizeof(final_state)/sizeof(curr_state); 
	for(int i = 0; i < len; i++){
		printf("Q%d -> ", curr_state);
		curr_state = trans_2[curr_state][str[i] - 'a'];
	}
	printf("Q%d\n", curr_state);
	return is_in(curr_state, final_state, mod_f);
}

// DFA 3 that accepts bit(iii)
int al_1_a_ex_2_b(char* str, int len){
	int trans_3[][2] = {{3, 1}, {4, 2}, {5, 6}, {3, 4}, {4, 5}, {5, 6}, {6, 6}};
	int curr_state = 0;
	int final_state[] = {5};
	int mod_f = sizeof(final_state)/sizeof(curr_state); 
	for(int i = 0; i < len; i++){
		printf("Q%d -> ", curr_state);
		curr_state = trans_3[curr_state][str[i] - 'a'];
	}
	printf("Q%d\n", curr_state);
	return is_in(curr_state, final_state, mod_f);
}

// DFA 4 that accepts bit(iv)
int contains_ab(char* str, int len){
	int trans_4[][2] = {{1, 0}, {1, 2}, {2, 2}};
	int curr_state = 0;
	int final_state[] = {2};
	int mod_f = sizeof(final_state)/sizeof(curr_state); 
	for(int i = 0; i < len; i++){
		printf("Q%d -> ", curr_state);
		curr_state = trans_4[curr_state][str[i] - 'a'];
	}
	printf("Q%d\n", curr_state);
	return is_in(curr_state, final_state, mod_f);
}

// The main function
int main(){
	int len = input("\nEnter the length of the string: ");
	char* str = input_str(len, "Enter the string: ");
	int option;
	printf("\nList of DFA...\n1. Number of 'a' equals to 1\n2. Number of 'a' is greater than 1\n3. The string contains at least one 'a' and exactly two 'b'\n4. 'ab' is a substring of the string\n5. Reinput the string\nPress any other digit (6 - 9) to exit\n");
	while(1){
		printf("\nChoose the DFA: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("\nString should contain exactly one 'a'\n");
				printf("%s is %s\n", str, n_a_equals_to_1(str, len) ? "Accepted" : "Rejected");
				break; 
			case 2:
				printf("\nString should contain multiple 'a'\n");
				printf("%s is %s\n", str, multiple_a(str, len) ? "Accepted" : "Rejected");
				break;
			case 3:
				printf("\nString should contain atleast one 'a' and exactly two 'b'\n");
				printf("%s is %s\n", str, al_1_a_ex_2_b(str, len) ? "Accepted" : "Rejected");
				break;
			case 4:
				printf("\nString should have 'ab' as a substring\n");
				printf("%s is %s\n", str, contains_ab(str, len) ? "Accepted" : "Rejected");
				break;
			case 5:
				main();
			case 6 ... 9:
				exit(0);
			default:
				printf("Invalid Input\n");
		}	
	}	
	return 0;
}

/* TERMINAL
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/Comp_II/DFA$ gcc -o E4P1.exe ./E4P1.c
cse2102040024@vssutcse-ProLiant-ML350-Gen9:~/Comp_II/DFA$ ./E4P1.exe

Enter the length of the string: 3
Enter the string: abb

List of DFA...
1. Number of 'a' equals to 1
2. Number of 'a' is greater than 1
3. The string contains at least one 'a' and exactly two 'b'
4. 'ab' is a substring of the string
5. Reinput the string
Press any other digit (6 - 9) to exit

Choose the DFA: 3

String should contain atleast one 'a' and exactly two 'b'
Q0 -> Q3 -> Q4 -> Q5
abb is Accepted

Choose the DFA: 1

String should contain exactly one 'a'
Q0 -> Q1 -> Q1 -> Q1
abb is Accepted

Choose the DFA: 2

String should contain multiple 'a'
Q0 -> Q1 -> Q1 -> Q1
abb is Rejected

Choose the DFA: 4

String should have 'ab' as a substring
Q0 -> Q1 -> Q2 -> Q2
abb is Accepted

Choose the DFA: 5

Enter the length of the string: 3
Enter the string: bbb

List of DFA...
1. Number of 'a' equals to 1
2. Number of 'a' is greater than 1
3. The string contains at least one 'a' and exactly two 'b'
4. 'ab' is a substring of the string
5. Reinput the string
Press any other digit (6 - 9) to exit

Choose the DFA: 1

String should contain exactly one 'a'
Q0 -> Q0 -> Q0 -> Q0
bbb is Rejected

Choose the DFA: 2

String should contain multiple 'a'
Q0 -> Q0 -> Q0 -> Q0
bbb is Rejected

Choose the DFA: 3

String should contain atleast one 'a' and exactly two 'b'
Q0 -> Q1 -> Q2 -> Q6
bbb is Rejected

Choose the DFA: 4

String should have 'ab' as a substring
Q0 -> Q0 -> Q0 -> Q0
bbb is Rejected

Choose the DFA: 5

Enter the length of the string: 2
Enter the string: ba

List of DFA...
1. Number of 'a' equals to 1
2. Number of 'a' is greater than 1
3. The string contains at least one 'a' and exactly two 'b'
4. 'ab' is a substring of the string
5. Reinput the string
Press any other digit (6 - 9) to exit

Choose the DFA: 1

String should contain exactly one 'a'
Q0 -> Q0 -> Q1
ba is Accepted

Choose the DFA: 2

String should contain multiple 'a'
Q0 -> Q0 -> Q1
ba is Rejected

Choose the DFA: 3

String should contain atleast one 'a' and exactly two 'b'
Q0 -> Q1 -> Q4
ba is Rejected

Choose the DFA: 4

String should have 'ab' as a substring
Q0 -> Q0 -> Q1
ba is Rejected

Choose the DFA: 6
*/


/* TERMINAL
PS D:\Junior\Study\Lab_Server\Comp_II\DFA> gcc -o E4P1.exe .\E4P1.c
PS D:\Junior\Study\Lab_Server\Comp_II\DFA> .\E4P1.exe

Enter the length of the string: 2
Enter the string: aa

List of DFA...
1. Number of 'a' equals to 1
2. Number of 'a' is greater than 1
3. The string contains at least one 'a' and exactly two 'b'
4. 'ab' is a substring of the string
5. Reinput the string
Press any other digit (6 - 9) to exit

Choose the DFA: 3

String should contain atleast one 'a' and exactly two 'b'
Q0 -> Q3 -> Q3
aa is Rejected

Choose the DFA: 1

String should contain exactly one 'a'
Q0 -> Q1 -> Q2
aa is Rejected

Choose the DFA: 2

String should contain multiple 'a'
Q0 -> Q1 -> Q2
aa is Accepted

Choose the DFA: 4

String should have 'ab' as a substring
Q0 -> Q1 -> Q1
aa is Rejected

Choose the DFA: 8
*/