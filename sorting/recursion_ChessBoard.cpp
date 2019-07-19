#include<iostream>
#include<iomanip>
using namespace std;
const int D = 8;

//this function is made to check whether the next box lies in condition for visiting irrespective of is it already visited or not

bool canPlaceKnight(int board[D][D], int n, int r, int col){

			return 
				r >= 0 && r < n &&//to check if rows columns are positive integers
				col >= 0 && col < n &&
				board[r][col] == 0;
				

} 

bool solveKnightMove(int board[D][D], int n, int move_no, int curRow, int curCol){
	if (move_no == n * n){
		return true;
	}
    //all rows combination where we can put our knight from current postion
    int rowDir[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    //all posible column combination where we can put our knight from current position
    int colDir[] = {1, 2, 2, 1, -1, -2, -2, -1};
    for (int curDir = 0 ; curDir < 8 ; curDir++){
        int nextRow = curRow + rowDir[curDir];
        int nextCol = curCol + colDir[curDir];

        if(canPlaceKnight(board, n, nextRow, nextCol) == true){
        		//knight can be placed and put move number
        		board[nextRow][nextCol] = move_no + 1;
        		//we performed first move and we ask recursion to perform rest of possible moves on itself
        		// We gotta declare isSuccessfull variable to know if knight was placed sucessfully or not
        		bool isSucessfull = solveKnightMove(board, n, move_no + 1, nextRow, nextCol);

        		if(isSucessfull == true) return true;
        		board[nextRow][nextCol] = 0; //erase the knight cz it can't be placed

         }

    }
    	//if no moves possible
       return false;
}

void printBoard(int board[D][D], int n){

		for(int i = 0; i < n; i++){
				for (int j = 0; j < n; j++) {
							cout<< setw(5) << board[i][j];
				} 

				cout<<endl;
		}
}
int main(){
		int board[D][D] = {0};
		board[0][0] = 1;
		int n;cin>>n;

		bool test = solveKnightMove(board, n, 1, 0, 0);

		if (test){
			printBoard(board, n);
		}else{
				cout<<"Can't visit all cells";
		}
	return 0;
}