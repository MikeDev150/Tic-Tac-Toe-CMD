#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <cstdlib>
#include <ctime>
#include <time.h>

void drawBoard(std::vector<char> &board){
	std::cout << "-------\n";
	std::cout << "|" << board[0] << "|" << board[1] << "|" << board[2] << "|\n";
	std::cout << "-------\n";
	std::cout << "|" << board[3] << "|" << board[4] << "|" << board[5] << "|\n";
	std::cout << "-------\n";
	std::cout << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|\n";
	std::cout << "-------\n";
}

bool checkForGameover(std::vector<char> &board){
	char c = 'X';
	int x = 0;
	//Check if there are blank spots left
	for(int i = 0;i<9;i++){
		if (board[i] == ' '){
			x++;
		}
	}
	//If not GameOver
	if (x == 0){
		return true;
	}
	//Use loop to check for win for X and O by changing the variable c at the end
	for(int i = 0;i<2;i++){
		if ((board[0] == c && board[1] == c && board[2] == c) || (board[3] == c && board[4] == c && board[5] == c) || (board[6] == c && board[7] == c && board[8] == c) ||  
			(board[0] == c && board[3] == c && board[6] == c) || (board[1] == c && board[4] == c && board[7] == c) || (board[2] == c && board[5] == c && board[8] == c) ||
			(board[0] == c && board[4] == c && board[8] == c) || (board[2] == c && board[4] == c && board[6] == c)){
			return true;
		}
		c = 'O';
	}
	return false;
}

int main(){
	std::vector<char> board(9,' ');
	drawBoard(board);
	std::cout << "Let's Play Tic Tac Toe\n";
	//Loop while the game isn't over
	while(!checkForGameover(board)){
		//Player 1's turn
		std::cout << "Player 1 Pick a number 1-9\n";
		int playerChoice;
		std::cin >> playerChoice;
		//Make sure the choice is between 1-9
		while((playerChoice > 9 || playerChoice < 1)){
			std::cout << "Player 1 Please choose a number 1-9\n";
			std::cin >> playerChoice;
		}
		board[playerChoice-1] = 'X';
		drawBoard(board);
		if (checkForGameover(board)) break;

		//Player 2's turn
		std::cout << "Player 2 Pick a number 1-9\n";
		int player2Choice;
		std::cin >> player2Choice;
		//Make sure the choice is between 1-9
		while((player2Choice > 9 || player2Choice < 1)){
			std::cout << "Player 2 Please choose a number 1-9\n";
			std::cin >> player2Choice;
		}
		board[player2Choice-1] = 'O';
		drawBoard(board);
	}
	std::cout << "Game Over!\n";
	return 0;
}