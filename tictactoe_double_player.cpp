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
void check(vector<vector<char>>& board, bool& one, bool& two) {
    unordered_map<char,int> m;
    for(vector<char>& row: board) {
        for(char& c: row) {
            m[c]++;
        }
        if(m['X']==3) {
            one=true;
            return;
        }
        else if(m['O']==3) {
            two=true;
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
            one=true;
            return;
        }
        else if(m['O']==3) {
            two=true;
            return;
        }
        m['X']=0;
        m['O']=0;
    }
    m[board[0][0]]++;
    m[board[1][1]]++;
    m[board[2][2]]++;
    if(m['X']==3) {
        one=true;
        return;
    }
    else if(m['O']==3) {
        two=true;
        return;
    }
    m['X']=0;
    m['O']=0;
    m[board[0][2]]++;
    m[board[1][1]]++;
    m[board[2][0]]++;
    if(m['X']==3) {
        one=true;
        return;
    }
    else if(m['O']==3) {
        two=true;
        return;
    }
    m['X']=0;
    m['O']=0;
}
int main() {
    vector<vector<char>> board={{'-','-','-'},{'-','-','-'},{'-','-','-'}};
    cout<<"This is how the board looks initially: "<<endl;
    display(board);
    int cell=0;
    bool one=false, two=false;
    while(true) {
        int row=0, col=0;
        while(true) {
            cout<<"Player 1's turn, enter a position to fill: ";
            cin>>row>>col;
            if(row>=0 && row<=2 && col>=0 && col<=2) {
                if(board[row][col]=='-') {
                    break;
                }
            }
        }
        board[row][col]='X';
        display(board);
        cell++;
        check(board,one,two);
        if(cell==9 || one || two) {
            break;
        }
        row=-1;
        col=-1;
        while(true) {
            cout<<"Player 2's turn, enter a position to fill: ";
            cin>>row>>col;
            if(row>=0 && row<=2 && col>=0 && col<=2) {
                if(board[row][col]=='-') {
                    break;
                }
            }
        }
        board[row][col]='O';
        display(board);
        cell++;
        check(board,one,two);
        if(cell==9 || one || two) {
            break;
        }
    }
    if(one) {
        cout<<"Player 1 WON"<<endl;
    }
    else if(two) {
        cout<<"Player 2 WON"<<endl;
    }
    else {
        cout<<"DRAW";
    }
    return 0;
}