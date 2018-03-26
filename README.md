## N-Queens

On an N * N chess board, can you place N queens on the board so that no queen is under attack?

```bash
macbook: andrade$ ./nqueens 1
1 

macbook: andrade$ ./nqueens 2
0 0 
0 0 

macbook: andrade$ ./nqueens 3
0 0 0 
0 0 0 
0 0 0 

macbook: andrade$ ./nqueens 4
0 1 0 0 
0 0 0 1 
1 0 0 0 
0 0 1 0 

macbook: andrade$ ./nqueens 8
1 0 0 0 0 0 0 0 
0 0 0 0 1 0 0 0 
0 0 0 0 0 0 0 1 
0 0 0 0 0 1 0 0 
0 0 1 0 0 0 0 0 
0 0 0 0 0 0 1 0 
0 1 0 0 0 0 0 0 
0 0 0 1 0 0 0 0 
```

When N=1, there is a trivial solution.
When N=2 or N=3, no solution exists.
When N>=4, there is a solution.

This backtracking algorithm produces *any* solution. The nqueens() function returns true upon encountering the first valid board.
A board with all zeros indicates that no valid placement of queens exists.

