/**
 * N-Queens
 * Purpose: Recursion and backtracking exercise
 * 
 * @author Bryan Andrade
 * @version 0.1 03/25/2018
 *
 * On an N * N chess board, can you place N queens
 * on the board so that no queen is under attack?
 *
 * Usage: ./nqueens [N]
*/
#include <iostream>

void print_board(int *board, int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i * N + j] == 1) {
	std::cout << 1 << " ";
      } else {
	std::cout << 0 << " ";
      }
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void place(int x, int y, int *board, int N, int incr) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (x == i || y == j) {
        board[i * N + j] += incr;
      }
      else if ((x + y == i + j) || (x - y == i - j)) {
        board[i * N + j] += incr;
      }
    }
  }
}

// For each position on the board, check if the position is attacked by
// a queen. Values greater than 0 represent a square that either has a
// queen placed on it, or is currently under attack by one or more queens.
// When a square with value 0 is encountered, insert the queen on the square.
// The place() function will increment all positions on the board that
// are attacked by the newly placed queen, or decrement positions that
// are no longer under threat from a removed queen.
// If there are no remaining queens to place (q=0), then
// return true, otherwise backtrack by removing the queen.
// Checking if a position on the board is available is a constant time,
// O(1) operation.
// Inserting or removing a queen, in the worst case, is a linear,
// O(n) operation.
// Since there are many more position checks than insertions/deletions,
// this is a performant configuration.
bool nqueens(int *board, int N, int q) {
  if (q == 0) {
    return true;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i * N + j] > 0) {
        continue;
      }
      place(i, j, board, N, 1);
      if (nqueens(board, N, q - 1)) {
	return true;
      }
      // Backtrack
      place(i, j, board, N, -1);
    }
  }
  return false;
}

// Usage: ./nqueens [N]
int main(int argc, char *argv[]) {
  int N = std::stoi(argv[1]);
  int *board = new int[N * N] {};
  nqueens(board, N, N);
  print_board(board, N);
  delete [] board;
  return 0;
}

