#include <bits/stdc++.h>
using namespace std;
void display(vector<vector<char>> &board)
{
    cout << endl;
    for (vector<char> &row : board)
    {
        for (char &c : row)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}
void check(vector<vector<char>> &board, bool &flag)
{
    unordered_map<char, int> m;
    for (vector<char> &row : board)
    {
        for (char &c : row)
        {
            m[c]++;
        }
        if (m['X'] == 3)
        {
            cout << "Player 1 WON" << endl;
            flag = true;
            return;
        }
        else if (m['O'] == 3)
        {
            cout << "Player 2 WON" << endl;
            flag = true;
            return;
        }
        m['X'] = 0;
        m['O'] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        for (vector<char> &row : board)
        {
            m[row[i]]++;
        }
        if (m['X'] == 3)
        {
            cout << "Player 1 WON" << endl;
            flag = true;
            return;
        }
        else if (m['O'] == 3)
        {
            cout << "Player 2 WON" << endl;
            flag = true;
            return;
        }
        m['X'] = 0;
        m['O'] = 0;
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                m[board[i][j]]++;
            }
        }
    }
    if (m['X'] == 3)
    {
        cout << "Player 1 WON" << endl;
        flag = true;
        return;
    }
    else if (m['O'] == 3)
    {
        cout << "Player 2 WON" << endl;
        flag = true;
        return;
    }
    m['X'] = 0;
    m['O'] = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i + j == 2)
            {
                m[board[i][j]]++;
            }
        }
    }
    if (m['X'] == 3)
    {
        cout << "Player 1 WON" << endl;
        flag = true;
        return;
    }
    else if (m['O'] == 3)
    {
        cout << "Player 2 WON" << endl;
        flag = true;
        return;
    }
}
int main()
{
    vector<vector<char>> board = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    cout << "This is the board initially: ";
    display(board);
    int cell = 0;
    bool flag = false;
    while (true)
    {
        int row = 0, col = 0;
        cout << "Player 1's turn, enter a position to fill: ";
        cin >> row >> col;
        board[row][col] = 'X';
        cell++;
        display(board);
        check(board, flag);
        if (flag)
        {
            break;
        }
        if (cell == 9)
        {
            break;
        }
        cout << "Player 2's turn, enter a position to fill: ";
        cin >> row >> col;
        board[row][col] = 'O';
        cell++;
        display(board);
        check(board, flag);
        if (flag)
        {
            break;
        }
        if (cell == 9)
        {
            break;
        }
    }
    if (flag == false)
    {
        cout << "DRAW" << endl;
    }
    return 0;
}