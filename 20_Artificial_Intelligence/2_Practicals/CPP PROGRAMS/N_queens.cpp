
#include <iostream>
#include <math.h>
#include<ctime>

#define N 4
using namespace std;

void configureRandomly(int board[][N],
					int* state)
{

	
	srand(time(0));

	
	for (int i = 0; i < N; i++) {

		
		state[i] = rand() % N;

		
		board[state[i]][i] = 1;
	}
}


void printBoard(int board[][N])
{

	for (int i = 0; i < N; i++) {
		cout << " ";
		for (int j = 0; j < N; j++) {
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}


void printState(int* state)
{

	for (int i = 0; i < N; i++) {
		cout << " " << state[i] << " ";
	}
	cout << endl;
}


bool compareStates(int* state1,
				int* state2)
{

	for (int i = 0; i < N; i++) {
		if (state1[i] != state2[i]) {
			return false;
		}
	}
	return true;
}


void fill(int board[][N], int value)
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			board[i][j] = value;
		}
	}
}


int calculateObjective(int board[][N],
					int* state)
{

	int attacking = 0;

	
	int row, col;

	for (int i = 0; i < N; i++) {

		
		row = state[i], col = i - 1;
		while (col >= 0
			&& board[row][col] != 1) {
			col--;
		}
		if (col >= 0
			&& board[row][col] == 1) {
			attacking++;
		}

		
		row = state[i], col = i + 1;
		while (col < N
			&& board[row][col] != 1) {
			col++;
		}
		if (col < N
			&& board[row][col] == 1) {
			attacking++;
		}

		
		row = state[i] - 1, col = i - 1;
		while (col >= 0 && row >= 0
			&& board[row][col] != 1) {
			col--;
			row--;
		}
		if (col >= 0 && row >= 0
			&& board[row][col] == 1) {
			attacking++;
		}

		
		row = state[i] + 1, col = i + 1;
		while (col < N && row < N
			&& board[row][col] != 1) {
			col++;
			row++;
		}
		if (col < N && row < N
			&& board[row][col] == 1) {
			attacking++;
		}

		
		row = state[i] + 1, col = i - 1;
		while (col >= 0 && row < N
			&& board[row][col] != 1) {
			col--;
			row++;
		}
		if (col >= 0 && row < N
			&& board[row][col] == 1) {
			attacking++;
		}

		
		row = state[i] - 1, col = i + 1;
		while (col < N && row >= 0
			&& board[row][col] != 1) {
			col++;
			row--;
		}
		if (col < N && row >= 0
			&& board[row][col] == 1) {
			attacking++;
		}
	}

	
	return (int)(attacking / 2);
}

void generateBoard(int board[][N],
				int* state)
{

	fill(board, 0);
	for (int i = 0; i < N; i++) {
		board[state[i]][i] = 1;
	}
}


void copyState(int* state1, int* state2)
{

	for (int i = 0; i < N; i++) {
		state1[i] = state2[i];
	}
}


void getNeighbour(int board[][N],
				int* state)
{
	

	int opBoard[N][N];
	int opState[N];

	copyState(opState,
			state);
	generateBoard(opBoard,
				opState);

	
	int opObjective
		= calculateObjective(opBoard,
							opState);

	

	int NeighbourBoard[N][N];
	int NeighbourState[N];

	copyState(NeighbourState,
			state);
	generateBoard(NeighbourBoard,
				NeighbourState);

	

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			

			if (j != state[i]) {

				
				NeighbourState[i] = j;
				NeighbourBoard[NeighbourState[i]][i]= 1;
				NeighbourBoard[state[i]][i]= 0;

				
				int temp
					= calculateObjective(
						NeighbourBoard,
						NeighbourState);

				

				if (temp <= opObjective) {
					opObjective = temp;
					copyState(opState,
							NeighbourState);
					generateBoard(opBoard,
								opState);
				}

				

				NeighbourBoard[NeighbourState[i]][i]
					= 0;
				NeighbourState[i] = state[i];
				NeighbourBoard[state[i]][i] = 1;
			}
		}
	}

	

	copyState(state, opState);
	fill(board, 0);
	generateBoard(board, state);
}

void hillClimbing(int board[][N],
				int* state)
{

	
	int neighbourBoard[N][N] = {};
	int neighbourState[N];

	copyState(neighbourState, state);
	generateBoard(neighbourBoard,
				neighbourState);

	do {

		
		copyState(state, neighbourState);
		generateBoard(board, state);

		

		getNeighbour(neighbourBoard,
					neighbourState);

		if (compareStates(state,
						neighbourState)) {

			

			printBoard(board);
			break;
		}
		else if (calculateObjective(board,
									state)
				== calculateObjective(
						neighbourBoard,
						neighbourState)) {

			

			
			neighbourState[rand() % N]
				= rand() % N;
			generateBoard(neighbourBoard,
						neighbourState);
		}

	} while (true);
}


int main()
{

	int state[N] = {};
	int board[N][N] = {};

	
	configureRandomly(board, state);

	
	hillClimbing(board, state);

    cout<<"PARTH PATEL\n19DCS098"<<endl;
	return 0;
}
