// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.

class Solution {
public:
    bool isSafe(vector<vector<char>>& board,int row,int col,char ch,int size)
    {
        for(int k=0;k<size;k++)
        {
            if(board[row][k]==ch||board[k][col]==ch)
                return false;
        }
        int rs=row-row%3;
        int cs=col-col%3;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i+rs][j+cs]==ch)
                    return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board,int size)
    {
        int i,j;
        bool flag=false;
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                if(board[i][j]=='.')
                {
                    flag=true;
                    break;
                }
            }
            if(flag==true)
                break;
        }
        if(i==size&&j==size)
            return true;
        for(int num=1;num<=size;num++)
        {
            char ch='0'+num;
            if(isSafe(board,i,j,ch,size))
            {
                board[i][j]=ch;
                if(solve(board,size))
                    return true;
                board[i][j]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int size=board.size();
        solve(board,size);
        return;
    }
};
