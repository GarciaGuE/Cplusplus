#include <iostream>
#include <vector>
#include <locale>
#include <string>
#include <ncurses.h>

using namespace std;

//Check if the position is valid
bool checkPosition(vector<vector<int>>& board, int row, int col, int queens){
    
    //Check row
    for(int i=0; i<col; i++)
        if(board[row][i])
            return false;

    //Check upper diagonal
    for(int i=row, j=col; i>=0 && j >= 0; i--, j--)
        if(board[i][j])
            return false;

    //Check lower diagonal
    for(int i = row, j = col; i<queens && j >= 0; i++, j--)
        if(board[i][j])
            return false;

    return true;
}

//Solve the problem using backtracking
bool solveNQueens(vector<vector<int>>& board, int col, int queens){
    //All queens are placed
    if(col>=queens)
        return true;
    

    for (int i=0; i<queens; i++){
        if(checkPosition(board, i, col, queens)){
            // Place this queen in board[i][col]
            board[i][col] = 1;

            if(solveNQueens(board, col+1, queens))
                return true;

            // Go back and try another position
            board[i][col] = 0;
        }
    }

    return false;  // No se pudo encontrar una solución en esta col
}

//Show the board in the terminal using ncurses 
void showBoard(vector<vector<int>>& board, int queens){
    initscr();
    start_color();

    //Color pairs
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLUE, COLOR_WHITE);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);

    int nqueen=1;
    for(int i=0; i<queens; i++) {
        for(int j=0; j<queens; j++){
            //Color the board
            if((i+j)%2==0)
                attron(COLOR_PAIR(1)); 
            else
                attron(COLOR_PAIR(3));

            mvprintw(i, 2*j, "  ");  //Queens

            if(board[i][j]){
                string queen="Q"+to_string(nqueen);
                if((i+j)%2==0){
                    attron(COLOR_PAIR(1)); //If the queen is in a white square, use cyan
                    attron(COLOR_PAIR(2));
                }
                else{
                    attron(COLOR_PAIR(3)); //If the queen is in a black square, use black
                    attron(COLOR_PAIR(4));
                }
                mvprintw(i, 2 * j, "%s", queen.c_str());  //Print the queen
                nqueen++;
            }
        }
    }

    refresh();
    getch();
    endwin();
}

int main(){
    int queens;
    cout<<"Number of Queens: ";
    cin>>queens;
    vector<vector<int>> board(queens, vector<int>(queens, 0));

    if(solveNQueens(board, 0, queens)){
        showBoard(board, queens);
    }
    else
        cout<<"Any solution was found"<<endl;

    return 0;
}
