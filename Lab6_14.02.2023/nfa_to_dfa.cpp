/* Code for NFA to DFA conversion */

// HEADER FILES
#include <iostream>
#include <iomanip>
#include <cstring>
#include <queue>
#include <set>

// NAMESPACE
using namespace std;

// TEMPLATE FUNCTIONS
template <class T>
bool is_in(T elem, T *arr, int size){
    // cout<<"Entered is in"<<endl;
    for(int i = 0; i < size; i++)
        if(elem == arr[i])
            return true;
    return false;
}

// CLASS DEFINITION
class FA{
        char dfa[100][2][10] = {-1};
        char dfa_states[100][10] = {-1};
        char *final_dfa;
        int mod_q_dfa;
        int mod_f_dfa;
        char ***nfa;
        char *final_nfa;
        int mod_q_nfa;
        int mod_f_nfa;
        bool is_in_final_nfa(char);
        void set_nfa_from_input();
        void print_nfa();
        void set_dfa_from_nfa();
        void print_dfa();
    public:
        FA(){}
        FA(int n){
            mod_q_nfa = n;
            nfa = new char**[n];
            for(int i = 0; i < n; i++){
                nfa[i] = new char*[2];
                for(int j = 0; j < 2; j++)
                    nfa[i][j] = new char[5];
            }
            set_nfa_from_input();
        }
        ~FA(){
            for(int i = 0; i < mod_q_nfa; i++){
                for(int j = 0; j < 2; j++)
                    delete nfa[i][j];
                delete nfa[i];
            }
            delete nfa;
        }
        void display();
};

void FA::set_nfa_from_input(){
    cout<<"Enter the NFA transitions: "<<endl;
    for(int i = 0; i < mod_q_nfa; i++){
        cout<<"STATE Q"<<i<<endl;
        for(int j = 0; j < 2; j++){
            cout<<"ON INPUT "<<j<<": ";
            cin>>nfa[i][j];
        }
    }
    cout<<endl<<"Enter number of final states: ";
    cin>>mod_f_nfa;
    // ERROR HANDLING FOR ZERO INPUT TO BE DEVELOPED
    final_nfa = new char[mod_f_nfa];
    cout<<"Enter the final states(space separated): ";
    for(int i = 0; i < mod_f_nfa; i++)
        cin>>final_nfa[i];
    cout<<endl<<"NFA INPUT COMPLETED"<<endl<<endl;
}

bool FA::is_in_final_nfa(char c){
    // cout<<c<<endl;
    for(int i = 0; i < mod_f_nfa; i++)
        if(c == final_nfa[i])
            return true;
    return false;
}

void FA::print_nfa(){
    cout<<"NFA Transition Table"<<endl;
    // PRINTING THE COLUMN HEADER
    for(int i = 0; i < 70; i++)
        cout<<"-";
    cout<<endl;
    cout<<setw(15)<<"STATE\\INPUT"<<setw(15)<<"0"<<setw(25)<<"1"<<endl;
    for(int i = 0; i < 70; i++)
        cout<<"-";
    cout<<endl;
    for(int i = 0; i < mod_q_nfa; i++){
        if(i == 0)
            cout<<setw(10)<<"->Q"<<i;
        else if(!is_in_final_nfa((char)(i + '0')))
            cout<<setw(10)<<"Q"<<i;
        else
            cout<<setw(10)<<"*Q"<<i;
        for(int j = 0; j < 2; j++){
            cout<<setw(10);
            for(int k = 0; k < strlen(nfa[i][j]); k++)
                cout<<"Q"<<nfa[i][j][k]<<" ";
            for(int l = 0; l < 5 - strlen(nfa[i][j]); l++)
                cout<<"   ";
        }
        cout<<endl;
    }
    for(int i = 0; i < 70; i++)
        cout<<"-";
    cout<<endl;
}

/*bool que_contains(char *str, queue<char*> q){
    queue<char*> temp = q;
    while(!temp.empty()){
        if(strcmp(str, temp.front()) == 0)
            return true;
        temp.pop();
    }
    return false;
}*/

void FA::set_dfa_from_nfa(){
    bool flag = true;
    char *cst = "0";
    queue<char*> q;
    q.push(cst);
    set<char*> states;
    states.insert(cst);
    int k = 0;
    while(!q.empty()){
        // cout<<"Entered While Loop"<<endl;
        cst = q.front();
        q.pop();
        for(int j = 0; j < 2; j++){
            // cout<<"Entered For Loop"<<endl;
            bool dead_flag = true;
            for(int l = 0; l < strlen(cst); l++){
                // int for_loop_cnt = 0;
                // cout<<"ITERATION COUNT: FOR "<<++for_loop_cnt<<endl;
                int x = 0, y = 0;
                char comp_state = cst[l];
                if(!is_in(comp_state, dfa_states[k], 10))
                    dfa_states[k][x++] = comp_state;
                // cout<<"No defect in is in"<<endl;
                if(nfa[comp_state - '0'][j][0] != '\0'){
                    // cout<<"Defect in strcpy"<<endl;
                    strcpy(dfa[k][j], nfa[comp_state - '0'][j]);
                    dead_flag = false;   
                }
            }
            // cout<<"EXIT FOR LOOP"<<endl;

            if(dead_flag)
                dfa_states[k][0] = 'D';
            /*if(!que_contains(dfa[k][j], q))*/
            if(states.find(dfa_states[k]) == states.end()){
                states.insert(dfa_states[k]);
                q.emplace(dfa_states[k]);
            }
            k++;
            // cout<<k++<<endl;
        }
    }
    mod_q_dfa = k;
    cout<<"NFA to DFA CONVERSION SUCCESSFUL"<<endl;
}

void FA::print_dfa(){
    for(int i = 0; i < mod_q_dfa; i++)
        cout<<dfa_states[i]<<endl;
}

void FA::display(){
    print_nfa();
    set_dfa_from_nfa();
    print_dfa();
}

int main(){
    FA F1(4);
    F1.display();
    return 0;
}