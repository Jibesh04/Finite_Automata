#include <iostream>
#include <stack>
using namespace std;

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    stack<char> stk;
    bool flag = true;
    char cst = '0';
    // cout<<s.size()<<endl;
    for(int i = 0; i < s.size(); i++){
        if(cst == '0'){
            if(s[i] == '0')
                stk.push('0');
            else if(s[i] == '1')
                cst = '1';
        }
        else if(cst == '1'){
            if(s[i] == '1'){
                if(stk.empty()){
                    flag = false;
                    break;
                }
                stk.pop();
                cst = '2';
            }
            else{
                flag = false;
                break;
            }
        }
        else if(cst == '2'){
            if(s[i] == '1')
                cst = '1';
            else{
                flag = false;
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
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> g++ .\pda_simple_2.cpp
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> .\a.exe
Enter the string: 001111
Accepted
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> .\a.exe
Enter the string: 0011
Rejected
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> .\a.exe
Enter the string: 011
Accepted
PS D:\Junior\Study\Finite_Automata\Lab8_21.03.2023> .\a.exe
Enter the string: 011001111
Rejected
*/