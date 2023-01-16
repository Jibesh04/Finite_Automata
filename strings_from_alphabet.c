#include <stdio.h>
#include <stdlib.h>
void strings_of_length_3(char *alph, int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                printf("%c %c %c\n", alph[i], alph[j], alph[k]);
}
void strings_of_length_2(char *alph, int n){
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            printf("%c %c\n", alph[i], alph[j]);
}
int input(char stmt[]){
    printf("%s", stmt);
    int n;
    scanf("%d", &n);
    return n;
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
    printf("Strings of Length 2: \n");
    strings_of_length_2(alph, size);
    printf("Strings of Length 3: \n");
    strings_of_length_3(alph, size);
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata> gcc -o .\strings_from_alphabet.exe .\strings_from_alphabet.c
PS D:\Junior\Study\Finite_Automata> .\strings_from_alphabet.exe
Enter the strength of alphabet: 4
Enter the alphabet: abcd
Strings of Length 2: 
a a
a b
a c
a d
b a
b b
b c
b d
c a
c b
c c
c d
d a
d b
d c
d d
Strings of Length 3:
a a a
a a b
a a c
a a d
a b a
a b b
a b c
a b d
a c a
a c b
a c c
a c d
a d a
a d b
a d c
a d d
b a a
b a b
b a c
b a d
b b a
b b b
b b c
b b d
b c a
b c b
b c c
b c d
b d a
b d b
b d c
b d d
c a a
c a b
c a c
c a d
c b a
c b b
c b c
c b d
c c a
c c b
c c c
c c d
c d a
c d b
c d c
c d d
d a a
d a b
d a c
d a d
d b a
d b b
d b c
d b d
d c a
d c b
d c c
d c d
d d a
d d b
d d c
d d d
*/