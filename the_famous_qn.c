#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void print_str(char* str, int n){
    for(int i = 0; i < n; i++)
        printf("%c", str[i]);
    printf("\n");
}
void swap(char * str, int i, char * alph, int m){
    char c = str[i];
    for(int j = 0; j < m; j++){
        if(alph[j] == c){
            if(j < m - 1)
                str[i] = alph[j + 1];
            else if(j == m - 1)
                str[i] = alph[0];                
        }
    }
}
void print_ev(char * str, int n, int * swapper, char * alph, int m){
    for(int i = 0; i < n; i++)
        swapper[i]++;
    print_str(str, n);
    for(int i = 0; i < n; i++){
        if(swapper[i] == pow(m, i)){
            swap(str, n-i-1, alph, m);
            swapper[i] = 0;
        }
    }
}
int input(char stmt[]){
    printf("%s", stmt);
    int n;
    scanf("%d", &n);
    return n;
}
int * indicator(int n){
    int * swapper = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        swapper[i] = 0;
    return swapper;
}
char * input_alph(char stmt[], int n){
    printf("%s", stmt);
    char * alph = (char*)malloc(sizeof(char) * n);
    scanf("%s", alph);
    return alph;
}
int main(){
    int size = input("Enter the strength of alphabet: ");
    char* alph = input_alph("Enter the alphabet: ", size);
    int n = input("Enter the length: ");
    int* swapper = indicator(n);
    char * str = (char*)malloc(sizeof(char) * n);
    for(int i = 0; i < n; i++)
        str[i] = alph[0];
    int p = pow(size, n);
    printf("Accepted Strings...\n");
    while(p--)
        print_ev(str, n, swapper, alph, size);
    // print_str(alph, size);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\the_famous_qn.exe .\the_famous_qn.c
PS D:\Junior\Study\Finite_Automata> .\the_famous_qn.exe
Enter the strength of alphabet: 2
Enter the alphabet: ab
Enter the length: 3
Accepted Strings...
aaa
aab
aba
abb
baa
bab
bba
bbb
*/

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\the_famous_qn.exe .\the_famous_qn.c
PS D:\Junior\Study\Finite_Automata> .\the_famous_qn.exe
Enter the strength of alphabet: 3
Enter the alphabet: abc
Enter the length: 4
Accepted Strings...
aaaa
aaab
aaac
aaba
aabb
aabc
aaca
aacb
aacc
abaa
abab
abac
abba
abbb
abbc
abca
abcb
abcc
acaa
acab
acac
acba
acbb
acbc
acca
accb
accc
baaa
baab
baac
baba
babb
babc
baca
bacb
bacc
bbaa
bbab
bbac
bbba
bbbb
bbbc
bbca
bbcb
bbcc
bcaa
bcab
bcac
bcba
bcbb
bcbc
bcca
bccb
bccc
caaa
caab
caac
caba
cabb
cabc
caca
cacb
cacc
cbaa
cbab
cbac
cbba
cbbb
cbbc
cbca
cbcb
cbcc
ccaa
ccab
ccac
ccba
ccbb
ccbc
ccca
cccb
cccc
*/