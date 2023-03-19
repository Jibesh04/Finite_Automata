#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define N_SYM 2
#define N_STATE 3
//char nfa[N_STATE][N_SYM][5]={{"0","1"},{"12","1"},{"2","12"}};
//char nfa[N_STATE][N_SYM][5]={{"03","01"},{"","2"},{"2","2"},{"4",""},{"4","4"}};
//char nfa[N_STATE][N_SYM][5]={{"01","0"},{"2","1"},{"3","3"},{"","2"}};
//char nfa[N_STATE][N_SYM][5]={{"12",""},{"","0"},{"","3"},{"0",""}};
char nfa[N_STATE][N_SYM][5]={{"0", "01"}, {"2", "2"}, {"", ""}};
char f_states[] = {'2'};
int index_list[100];

char dfa[10][N_SYM+1][5];
int dfa_imp[100][N_SYM] = {-1};
int final_states[100];
int y = 0;
//dfa[0][0]={"0","01","1"};
int cRow=1, cClm=0;

int is_in_char(char c){
	int n = sizeof(f_states);
	for(int i = 0; i < n; i++)
		if(c == f_states[i])
			return 1;
	return 0;
}

int is_in_int(int num, int *arr, int size){
	for(int i = 0; i < size; i++)
		if(num == arr[i])
			return 1;
	return 0;
}

void sort(char *str)
{
	int len=strlen(str);
	int i,j;

	for(i=0;i<len;i++)
		for(j=0;j<len;j++)
			if(str[i]<str[j])
				str[i]=(str[i]+str[j])-(str[j]=str[i]);
}

int addNewState(char *str)
{
	int i;
	for(i=0;i<cRow;i++)
		if(!strcmp(dfa[i][0],str))
			return 0;
	strcpy(dfa[cRow][0],str);
	cRow++;
	return 1;
}
void addString(char *str1, char *str2)
{
	int i,j;
	for(i=0;i<strlen(str2);i++)
	{
		for(j=0;j<strlen(str1);j++)
			if(str2[i]==str1[j])break;
		if(j==strlen(str1))
		{
			str1[j]=str2[i];
			str1[j+1]='\0';
		}
	}
	sort(str1);
}
void nfa_dfa()
{
	int i,j,s=0;
	dfa[0][0][0]='0';
	dfa[0][0][1]='\0';
	char str[10]="";

	do{
		for(i=1;i<=N_SYM;i++)
		{
			for(j=0,str[0]='\0';j<strlen(dfa[s][0]);j++)
			{
				addString(str,nfa[dfa[s][0][j]-48][i-1]);
			}
			strcpy(dfa[s][i],str);
			addNewState(str);
		}
	}while(s++<cRow);
}
void implement_dfa(){
	int x = 0, z = 0;
	for(int k = 0; k < cRow - 1; k++){
		int idx = 0;
		for(int l = 0; l < strlen(dfa[k][0]); l++){
			idx += pow((dfa[k][0][l] - '0'), 2);
			// printf("%d is indexed\n", idx);
			if(is_in_char(dfa[k][0][l]))
				final_states[y++] = idx;
		}
		index_list[z++] = idx;
		for(int x = 0; x < N_SYM; x++){
			dfa_imp[idx][x] = 0;
			for(int l = 0; l < strlen(dfa[k][x + 1]); l++)
				dfa_imp[idx][x] += pow((dfa[k][x + 1][l] - '0'), 2);
			// printf("IDX: %d\tINP: %d\tVAL: %d\n", idx, x, dfa_imp[idx][x]);
		}
	}
}
void print_imp_dfa(){
	printf("|-------------------------------|\n");
	printf("|    ST\\IP\t0\t1\t|\n");
	printf("|-------------------------------|\n");
	for(int i = 0; i < 100; i++)
		if(is_in_int(i, index_list, 100))
			printf("|      Q%d\t%d\t%d\t|\n", i, dfa_imp[i][0], dfa_imp[i][1]);
	printf("|-------------------------------|\n");
}
void check_str(char *str){
	printf("\nString checked: %s\n", str);
	int cst = 0;
	for(int i = 0; i < strlen(str); i++){
		printf("Q%d -> ", cst);
		cst = dfa_imp[cst][str[i] - '0'];
	}
	printf("Q%d\n", cst);
	if(is_in_int(cst, final_states, y))
		printf("Accepted\n");
	else
		printf("Rejected\n");
}
void main()
{
	int i=0,j=0;
	nfa_dfa();
	implement_dfa();
	printf("STATES");
	for(i=0;i<N_SYM;i++)
		printf("\t  %d",i);
	printf("\n===========================\n\n");
	for(i=0;i<cRow;i++,printf("\n\n"))
		for(j=0;j<=N_SYM;j++)
			printf("(%s)\t",dfa[i][j]);
	print_imp_dfa();
	char *str;
	int len, t = 3;
	while(t--){
		printf("\nEnter the length of the string: ");
		scanf("%d", &len);
		str = (char*) malloc(sizeof(char)* len);
		printf("Enter the string: ");
		scanf("%s", str);
		check_str(str);
	}
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata\Lab7_14.03.2023> gcc -o nfa_to_dfa_with_acceptance.exe .\nfa_to_dfa_with_acceptance.c
PS D:\Junior\Study\Finite_Automata\Lab7_14.03.2023> .\nfa_to_dfa_with_acceptance.exe
STATES    0       1
===========================

(0)     (0)     (01)

(01)    (02)    (012)

(02)    (0)     (01)

(012)   (02)    (012)

()      ()      ()

|-------------------------------|
|    ST\IP      0       1       |
|-------------------------------|
|      Q0       0       1       |
|      Q1       4       5       |
|      Q4       0       1       |
|      Q5       4       5       |
|-------------------------------|

Enter the length of the string: 3
Enter the string: 101

String checked: 101
Q0 -> Q1 -> Q4 -> Q1
Rejected

Enter the length of the string: 4
Enter the string: 1010

String checked: 1010
Q0 -> Q1 -> Q4 -> Q1 -> Q4
Accepted

Enter the length of the string: 2
Enter the string: 11

String checked: 11
Q0 -> Q1 -> Q5
Accepted
*/