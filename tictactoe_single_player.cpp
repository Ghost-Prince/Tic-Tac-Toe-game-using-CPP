#include<bits/stdc++.h>
using namespace std;
void display(vector<vector<char>>& board) {
    for(vector<char>& row: board) {
        for(char& c: row) {
            cout<<c<<" ";
        }
        cout<<endl;
    }
}
void check(vector<vector<char>>& board, bool& human, bool& computer) {
    unordered_map<char,int> m;
    for(vector<char>& row: board) {
        for(char& c: row) {
            m[c]++;
        }
        if(m['X']==3) {
            human=true;
            return;
        }
        else if(m['O']==3) {
            computer=true;
            return;
        }
        m['X']=0;
        m['O']=0;
    }
    for(int i=0; i<3; i++) {
        for(vector<char>& row: board) {
            m[row[i]]++;
        }
        if(m['X']==3) {
            human=true;
            return;
        }
        else if(m['O']==3) {
            computer=true;
            return;
        }
        m['X']=0;
        m['O']=0;
    }
    m[board[0][0]]++;
    m[board[1][1]]++;
    m[board[2][2]]++;
    if(m['X']==3) {
        human=true;
        return;
    }
    else if(m['O']==3) {
        computer=true;
        return;
    }
    m['X']=0;
    m['O']=0;
    m[board[0][2]]++;
    m[board[1][1]]++;
    m[board[2][0]]++;
    if(m['X']==3) {
        human=true;
        return;
    }
    else if(m['O']==3) {
        computer=true;
        return;
    }
    m['X']=0;
    m['O']=0;
}
int main() {
    vector<vector<char>> board={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    cout<<"Initially the board is like this: "<<endl;
    display(board);
    int cell=0;
    bool human=false, computer=false;
    srand(time(NULL));
    while(true) {
        int row=-1,col=-1;
        while(true) {
            cout<<"Enter position to fill: ";
            cin>>row>>col;
            if(row>=0 && row<=2 && col>=0 && col<=2) {
                if(board[row][col]=='-') {
                    break;
                }
            }
        }
        board[row][col]='X';
        cell++;
        check(board,human,computer);
        if(cell==9 || human || computer) {
            display(board);
            break;
        }
        while(board[row][col] != '-') {
            row=rand()%3;
            col=rand()%3;
        }
        board[row][col]='O';
        cell++;
        display(board);
        check(board,human,computer);
        if(cell==9 || human || computer) {
            break;
        }
    }
    if(human) {
        cout<<"Human WON"<<endl;
    }
    else if(computer) {
        cout<<"Computer WON"<<endl;
    }
    else {
        cout<<"DRAW"<<endl;
    }
    return 0;
}