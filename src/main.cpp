#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <thread>
#include <chrono>
using namespace std;

// Function to display the ASCII art
void displayAsciiArt() {
cout << "    " << endl;
cout << " ████████ ██  ██████     ████████  █████   ██████     ████████  ██████  ███████ " << endl;
cout << "    ██    ██ ██             ██    ██   ██ ██             ██    ██    ██ ██      " << endl;
cout << "    ██    ██ ██             ██    ███████ ██             ██    ██    ██ █████   " << endl;
cout << "    ██    ██ ██             ██    ██   ██ ██             ██    ██    ██ ██      " << endl;
cout << "    ██    ██  ██████        ██    ██   ██  ██████        ██     ██████  ███████ " << endl;
cout << "  " << endl;
}


// Function Display Board
void displayBoard(char board[3][3]) {
	cout << "==================" << endl;
	cout << "| Current Board: |" << endl;
	cout << "==================" << endl;
	cout << "                  " << endl;
	cout << "                  " << endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] == 'X' || board[i][j] == 'O'){
				cout << " " << board[i][j] << " ";
			} else { 
				cout << "[" << board[i][j] << "]";
			}
			if (j < 2) cout << " | ";
		}
	cout << endl;
	if (i < 2) cout << "----+-----+----" << endl;
	}
	cout << "                  "  << endl;
	cout << " ..   ..      .."    << endl;
	cout << "  . . .     .    . " << endl;
	cout << " ..   ..      .."    << endl;
	cout << "                  "  << endl;
}

// Function Make a Move
bool makeMove(char board[3][3], int move, char player) {
	int row = (move - 1) / 3;
	int col = (move - 1) % 3;
	if (board[row][col] != 'X' && board[row][col] != 'O') {
		board[row][col] = player;
		return true;
	}
	return false;
}

// Function Check Winner
bool checkWinner(char board[3][3], char player) {
	// Check rows
	for (int i = 0; i < 3; i++) {
		if ((board[i][0] == player) && (board[i][1] == player && board[i][2] == player) || 
      		    (board[0][i] == player) && (board[1][i] == player && board[2][i] == player)) {
			return true;
		}
	}
	if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) || 
	    (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
		return true;
	}
	return false;
}

// Function is board full (draw)
bool isBoardFull(char board[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != 'X' && board[i][j] != 'O') {
       				return false;	
       			}
		}
	}
	return true;
}

// Function Get Valid Move
int getValidMove(char board[3][3]) {
	int move;
	while (true) {
		cout << "Enter your move (1-9): ";
		cin >> move;

		// Validade input as a number
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter a number." << endl;
			continue;
		}

		// Validate input in range
		if (move < 1 || move > 9) {
			cout << "Invalid move. Please enter number between 1 and 9." << endl;
			continue;
		}

		// Validate cell is not already taken
		int row = (move - 1) / 3;
		int col = (move - 1) % 3;
		if (board[row][col] == 'X' || board[row][col] == 'O') { 
			cout << "Invalid move. Cell already taken." << endl;
			continue;
		}

		return move;
	}
}


// AI Strategic Moves - Function to simulate AI thinking
bool canWin(char board[3][3], char player, int move) {
	int row = (move -1) / 3;
	int col = (move -1) % 3;
	char temp = board[row][col];
	board[row][col] = player;
	bool win = checkWinner(board, player);
	board[row][col] = temp;
	return win;
}



void simulateAIThinking() {
	cout << "AI is making a move";
	cout.flush();
	
	for (int i = 0; i < 3; i++) {
		this_thread::sleep_for(chrono::milliseconds(700));
		cout << "." ;
		cout.flush();
	}

	cout << endl;
}


// Function for random AI opponent
void makeAIMove(char board[3][3]) {
	simulateAIThinking();

	// 1. Check if AI can win
	for (int move =1; move <= 9; move++) {
		if (board[(move-1)/3][(move-1)%3] != 'X' && board[(move-1)/3][(move-1)%3] != 'O') {
			if (canWin(board, 'O', move)) {
				makeMove(board, move, 'O');
				return;
			}
		}
	}
	// 2. Check if AI needs to block player
	for (int move = 1; move <= 9; move++) { 
		if (board[(move-1)/3][(move-1)%3] != 'X' && board[(move-1)/3][(move-1)%3] != 'O') {
			if (canWin(board, 'X', move)) {
				makeMove(board, move, 'O');
				return;
			}
		}
	}
	// 3. Take center if available
	if (board[1][1] != 'X' && board[1][1] != 'O') {
		makeMove(board, 5, 'O');
		return;
	}
	// 4. Take corner if avaliable
	int corners[] = {1, 3, 7, 9};
	for (int i=0; i < 4; i++) {
		if (board[(corners[i]-1)/3][(corners[i]-1)%3] != 'X' && board[(corners[i]-1)/3][(corners[i]-1)%3] != 'O') {
			makeMove(board, corners[i], 'O');
			return;
		}
	}
	// 5. Take side if available
	int sides[] = {2, 4, 6, 8};
	for (int i = 0; i < 4; i++) {
		if (board[(sides[i]-1)/3][(sides[i]-1)%3] != 'X' && board[(sides[i]-1)/3][(sides[i]-1)%3] != 'O') {
			makeMove(board, sides[i], 'O');
			return;
		}
	}
}

void clearScreen() {
	// Clear screen
	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#else 
		system("clear");
	#endif
}

void printWelcomeMessage() {
	cout << "   " << endl;
	cout << "======================" << endl;
	cout << "Welcome to TIC-TAC-TOE" << endl;
	cout << "======================" << endl;
}


void displayScore(int xWins, int oWins, int draws) {
	cout << "\nScore:" << endl;
	cout << "Player X wins: " << xWins << endl;
	cout << "Player O wins: " << oWins << endl;
	cout << "Draws: " << draws << endl;
}


char chooseStartingPlayer() {
	return (rand() % 2 == 0) ? 'X' : 'O';
}


void labelPlayer(char player, bool isHuman) {
	if (player == 'X') {
		cout << "Player X (" << (isHuman ? "you" : "AI") << "), ";
	} else if (player == 'O') {
		cout << "Player O (" << (isHuman ? "you" : "AI") << "), ";
	}
}



int main(){
	clearScreen();
	srand(static_cast<unsigned int>(time(0)));
	displayAsciiArt();

	char playAgain;
	bool playAgainstAI;
	int xWins = 0, oWins = 0, draws = 0;

	do {
		printWelcomeMessage();
		char board[3][3] = {{'1', '2', '3'},
				    {'4', '5', '6'},
				    {'7', '8', '9'}};
		char player = chooseStartingPlayer();
		cout << "Player " << player << " starts!" << endl;

		int move;
		bool gameOver = false;

		cout << "Do you want to play against AI? (Y/N): "; 
		char aiChoice;
		cin >> aiChoice;
		playAgainstAI = (aiChoice == 'Y' || aiChoice == 'y');

		while (!gameOver) {
			clearScreen();
			displayBoard(board);

			if (player == 'X' || !playAgainstAI) {
				labelPlayer(player, true);
				move = getValidMove(board);
				makeMove(board, move, player);
			} else if (playAgainstAI && player == 'O') {
				labelPlayer(player, false);
				cout << "AI is making a move..." << endl;
				makeAIMove(board);
			}


			if (checkWinner(board, player)) {
				clearScreen();
				displayBoard(board);
				cout << "Player " << player << " wins!" << endl;
				if (player == 'X') { 
					xWins++;
				} else {
					oWins++;
				}
				gameOver = true;
			} else if (isBoardFull(board)) {
				clearScreen();
				displayBoard(board);
				cout << "It's a draw!" << endl;
				draws++;
				gameOver = true;
			} else {
				// Switch player
				player = (player == 'X') ? 'O' : 'X';	
			}
		}

		displayScore(xWins, oWins, draws);
		cout << "   " << endl;
		cout << "** Wanna play again? (Y/N): ";
		cout << "   " << endl;
		cin >> playAgain;
	} while (playAgain == 'Y' || playAgain == 'y');
	cout << "Thanks for playing!" << endl;
	return 0;
}
