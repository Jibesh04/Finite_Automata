#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    stack<char> stk;
    int flag = 1, cst = 0;
    for(int i = 0; i < s.size(); i++){
        if(cst == 0){
            if(s[i] == '0')
                stk.push('0');
            if(s[i] == '1'){
                if(!stk.empty()){
                    stk.pop();
                    cst = 1;
                }
                else{
                    flag = 0;
                    break;
                }
            }
        }
        else if(cst == 1){
            if(s[i] == '1'){
                if(!stk.empty()){
                    stk.pop();
                    cst = 1;
                }
                else{
                    flag = 0;
                    break;
                }
            }
            else{
                flag = 0;
                break;
            }
        }
    }
    if(stk.empty() && flag)
        cout<<"Accepted"<<endl;
    else
        cout<<"Rejected"<<endl;
    return 0;
}

/* TERMINAL
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> g++ .\pda_simple_1.cpp
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> .\a.exe
Enter the string: 010011
Rejected
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> .\a.exe
Enter the string: 0011
Accepted
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> .\a.exe
Enter the string: 00011
Rejected
*/