#include <iostream>
#include <queue>
#include <set>

using namespace std;

string nfa[100][10];
string dfa[100][10];

void nfa_to_dfa(string **nfa, int n, string **dfa){
    string cst = "0";
    queue<string*> q;
    q.emplace(nfa[0]);
    set<string> s;
    s.insert(cst);
    int j = 0;
    while(!q.empty()){
        string * nfa_row = q.front();
        q.pop();
        for(int i = 0; i < 2; i++){
            dfa[j][i] = "";
            for(int k = 0; k < nfa_row[i].length(); i++)
                dfa[j][i] += nfa_row[i].at(k);
            s.insert(dfa[j][i]);
        }
        j++;
    }
}

int main(){
    
}