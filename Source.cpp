//Huseyin Onur Onma 
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "strutils.h"
#include <stdlib.h>              
#include "randgen.h"

using namespace std;

//matrix print 
void Print(vector<vector<string>> &matrix)
{
	for (int j=0; j < matrix.size(); j++)
    {   
		for (int k=0; k < matrix[0].size(); k++)
        {   
			cout << setw(4) <<   matrix[j][k];
        }
        cout << endl;
	}
}
//board print for checking sample runs
void Printn(vector<vector<int>> &board)
{
	for (int j=0; j < board.size(); j++)
    {   
		for (int k=0; k < board[0].size(); k++)
        {   
			cout << setw(4) <<  board[j][k];
        }
        cout << endl;
	}
}
// printing a matrix which for end of opt2 with B and intgers
void Printmatrix3(vector<vector<string>> &matrix3)
{
	for (int j=0; j < matrix3.size(); j++)
    {   
		for (int k=0; k < matrix3[0].size(); k++)
        {   
			cout << setw(4) <<   matrix3[j][k];
        }
        cout << endl;
	}
}
// actual board
void define_board(vector<vector<int>> &board, int row, int col, int mine, vector<vector<string>>&matrix3){
	int end =0;
	while(end < mine){
		RandGen random;
		int i =  random.RandInt(0 ,row-1);
		int j = random.RandInt(0 ,col-1);
		if((board[i][j] != 'B') && (matrix3[i][j] != "B")){
			board[i][j] = 'B';
			matrix3[i][j] = "B";
			end++;
			int x = mine-1;
			while(x < mine){   
			//checking every area around bomb and adding one 
				if(i > 0 && j > 0){ 
					if(board[i-1][j-1] < 66){
						board[i-1][j-1] += 1;
					}
				}
				if(i > 0){ 
					if(board[i-1][j] < 66){
						board[i-1][j] += 1;
					}				
				}
				if(i > 0 && j < col-1){ 
					if(board[i-1][j+1] < 66){
						board[i-1][j+1] += 1;
					}
				}
				if(j > 0){ 
					if(board[i][j-1] < 66){
						board[i][j-1] += 1;
					}
				}
				if(j < col-1){ 
					if(board[i][j+1] < 66){
						board[i][j+1] += 1;
					}
				}
				if(i < row-1 && j > 0){ 
					if(board[i+1][j-1] < 66){
						board[i+1][j-1] += 1;
					}
				}
				if(i < row-1){ 
					if(board[i+1][j] < 66){
						board[i+1][j] += 1;
					}
				}
				if(i < row-1 && j < col-1){ 
					if(board[i+1][j+1] < 66){
						board[i+1][j+1] += 1;
					}
				}
				x++;
			}
		}	
	}
}



int main()
{
	int j, k;
	int row, col, mine;
	cout << "Give the dimensions of the matrix: ";
	cin >> row >> col;
	cout << endl << "How many bombs: ";
	cin >> mine;
	//bomb check
	while ((mine >= (row*col)) || (mine < 1))
	{
		if(mine >= (row*col))
		{
			cout <<"The number of bombs can not be greater than the whole number of cells minus one. Please give the number of bombs again: ";
			cin >> mine;
		}
		else if(mine < 1)
		{
			cout <<"The number of bombs could not be less than one. Please give the number of bombs again: ";
			cin >> mine;
		}
	}
	//creating the matrix with x
	vector<vector<string>>matrix(row, vector<string>(col, "X"));
	cout << endl << endl;
	Print(matrix);
	// defining board with int nums
	vector<vector<int>>board(row, vector<int>(col));
	//defining matrix3 because icouldnt convert string to int i will convert board to this matrix
	vector<vector<string>>matrix3(row, vector<string>(col));

	define_board(board, row, col, mine, matrix3);
	//to check if it is working
	//Printn(board); i used this while checking samples
	//game
	bool x = true;
	string opt;
	int counter = 0;
	while(x = true){
		string opt1 = "1";
		string opt2 = "2";
		string opt3 = "3";
		cout << endl << "Press: ";
		cout<< endl << endl<< "1. If you want to find out the surrounding of a cell";
		cout << endl << endl <<"2. If you want to open the cell";
		cout << endl << endl << "3. If you want to exit." << endl << endl;
		cin >> opt;
		while((opt != opt1) && (opt != opt2) && opt != opt3){
			cout << "Your input is wrong. Please select one of the options: 1, 2 or 3." << endl;
			cin >> opt;
		}
//opt1 showing an area
		int inputrow, inputcol;
		if(opt == opt1){
			cout << endl << "Give the coordinates: " << endl;
			cin >> inputrow >> inputcol; 
			while((row < inputrow) || (col < inputcol)){
				cout << "It is out of range. Please give a valid coordinates: ";
				cin >> inputrow >> inputcol;
			}
			if(board[inputrow][inputcol]== 66){
				int num = 0;
				if((0 < inputrow) && (board[inputrow-1][inputcol] == 66)){
					num++;
				}
				if((0 < inputcol) && (board[inputrow][inputcol-1]==66)){
					num++;
				}
				if((0 < inputrow) && (0 < inputcol) && (board[inputrow-1][inputcol-1] == 66)){
					num++;
				}
				if((inputrow < row-1) && (board[inputrow+1][inputcol] == 66)){
					num++;
				}
				if((inputcol < col-1) && (board[inputrow][inputcol+1] == 66)){
					num++;
				}
				if((inputrow < row-1) && (0 < inputcol) && (board[inputrow+1][inputcol-1] == 66)){
					num++;
				}
				if((0 < inputrow) && (inputcol < col-1) && (board[inputrow-1][inputcol+1] == 66)){
					num++;
				}
				if((inputrow < row-1) && (inputcol < col-1) &&(board[inputrow+1][inputcol+1] == 66)){
					num++;
				}
				string num1str = tostring(num);
				matrix[inputrow][inputcol]  = num1str;
				cout << endl << " Displaying the surrounding of (" << inputrow<< "," << inputcol << "): " << endl;
				Print(matrix);
				cout << endl <<endl << "Around ("<<inputrow << "," << inputcol <<") you have " << num1str << " bomb(s)." << endl <<endl;
				matrix[inputrow][inputcol] = "X";
				x = true;
			}
			else{
				string numstr = tostring(board[inputrow][inputcol]);
				matrix[inputrow][inputcol] = numstr;
				cout << endl << " Displaying the surrounding of (" << inputrow<< "," << inputcol << "): " << endl;
				Print(matrix);
				cout << endl << endl<< "Around ("<<inputrow << "," << inputcol <<") you have " << numstr << " bomb(s)." << endl <<endl;
				matrix[inputrow][inputcol] = "X";
				x = true;
			}
		}
//opt2 openning area
		if(opt == opt2){
			cout << endl << "Give the coordinates: ";
			cin >> inputrow >> inputcol;
			while((row < inputrow) || (col < inputcol)){
				cout << "It is out of range. Please give a valid coordinates: ";
				cin >> inputrow >> inputcol;
			}
//coordinate with no bomb
			if(board[inputrow][inputcol] != 66){
				string numstr = tostring(board[inputrow][inputcol]);
				matrix[inputrow][inputcol] = numstr;
				cout << endl << endl << "Opening cell (" << inputrow << ","<< inputcol << "): " << endl << endl;
				Print(matrix);
				x = true;
				counter++;
				if(counter == ((row*col)-mine)){
					cout << endl << "Congratulations! All the non-mined cells opened successfully" << endl;
					cout << endl << "You won!" << endl;
					cout << endl << endl << ">>>>> Game Over! <<<<<" << endl << endl;
					break;
				}
			}
//coordinate with bomb is coded as 66 ='B'
			if(board[inputrow][inputcol] == 66){
				cout << "Unfortunately, you stepped on a mine" << endl;
				cout << endl << "Arrangement of mines:" << endl << endl;
				for(int i=0; i <row; i++){
					for(int j=0; j <col; j++){
						if(board[i][j] != 66){
							matrix3[i][j] = tostring(board[i][j]);					
						}
					}
				}
				Printmatrix3(matrix3);	
				cout << endl  << ">>>>> Game Over! <<<<<" << endl << endl;
				break;
			}

		}

		//opt 3 exiting
		if(opt == opt3){
			cout <<endl <<  "Program exiting ..." << endl;
			break;
		}
		
	}
	return 0;
}
