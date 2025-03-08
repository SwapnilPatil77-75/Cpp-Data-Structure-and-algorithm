#include<iostream>
#include<vector>
using namespace std;


bool isSafe(vector<vector<char>> board, int row, int col){
    int n = board.size();

    // Check vertically if a Queen is alredy placed or not 
    for(int i = 0; i<col; i++){
        if(board[row][i] == 'Q'){
            return false;
        }
    }

    // check Verticaly 

    for(int i = 0;i<row; i++){
        if(board[i][col] == 'Q'){
            return false;
        }
    }

    // Check left Dignoally 
    for(int i = row , j = col ; i>=0 && j>=0; i--, j--){
        if(board[i][j] == 'Q'){
            return false;
        }
    }

    // Check Dignoally 
    for(int i = row-1 , j = col+1; i>=0 && j<n; i--, j++){
        if(board[i][j]== 'Q'){
            return false;
        }
    }

    return true;
}


void PrintBoard(vector<vector<char>> board){
    for(int i = 0; i< board.size(); i++){
        for(int j = 0; j<board.size(); j++){
            cout<<board[i][j] <<" ";
        }
        cout<<"\n";
    }

    cout<<"-----------------"<<endl;
}

int nQueens(vector<vector<char>>board,int row){


int n = board.size();
if(row == n){
    PrintBoard(board);
    return 1;
}
    for(int i = 0; i<n; i++){
        if(isSafe(board, row, i)){
            board[row][i] = 'Q';
            nQueens(board, row+1);
            board[row][i]= '.';
        }
    }
}

int main(){
    vector<vector<char>> board;

    int n = 4;
    for(int i = 0;i<n;i++){
        vector<char> newRow;
        for(int j = 0; j<n;j++){
            newRow.push_back('.');
        }
        board.push_back(newRow);
    }

//PrintBoard(board);
nQueens(board, 0);
}
