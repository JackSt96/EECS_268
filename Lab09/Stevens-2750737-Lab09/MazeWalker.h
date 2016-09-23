/*
 * File:   MazeWalker.h
 * Author: Jack
 * Purpose: declare the maze walker methods such as move and storevalid moves
 * Created on November 16, 2015, 12:01 PM
 */

#ifndef MWALK
#define MWALK
#include "Position.h"
#include <stack>
#include <queue>
#include <iostream>

enum class Search
{
	DFS,
	BFS
};

class MazeWalker{

	public:

 /**	Constructor
*	@pre  - The mazePtr pointer is to a valid maze.
*	@post  - A maze walker if created with all needed flags set and the visited array contains
*		all false.
*	@return - void
*/
	MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice);

/**	Deconstructor - This is to clean up the arrays and such
*	@pre - a MazeWalker exists
*	@post - deletes heap-allocated members
*	@return - void
*/
	~MazeWalker();


/**	This actually does the work, this is a driver.
*	@pre - The maze is a valid maze.
*	@post - The maze is traversed until (either dfs or bfs) the end is reached or all moves are
*		 exhausted. The visited array printed during the traversal.
*	@return - void
*/
	bool walkMaze();
		/**
			*	@return A const pointer to the visited array. (A pointer that cannot change the array)
			*/
	const int* const* getVisited() const;

	/**
	*	@return number of rows in maze
	*/
	int getVisitedRows() const;

	/**
	*	@return number of cols in maze
	*/

	int getVisitedCols() const;

	/**
	*	@return A const pointer to the maze. (A pointer that cannot change the array)
	*/
	const char* const* getMaze() const;


	protected:

/**	This method stores all remaining moves associated with a given position
*	@pre - The current position is valid.
*	@post - Either the stack (dfs) or queue (bfs) is loaded with valid moves from the current
*		 position.
*	@return - void
*/
		void storeValidMoves();


/**	This method changes the current position and updates members appropriately.
*	@pre - The position is valid.
*	@post - The current position is set to p and the position is updated as marked.
*	@return - void
*/
		void move(Position&p);

/**
*	@pre - A valid maze exists
*	@post - checks the current character in m_maze.
*	@return - True if the current position has value 'E', false otherwise.
*/
		bool isGoalReached() const;



		Search m_searchType;
		const char* const* m_maze;//populated by the reader, holds path values
		int** m_visited;//keeps track of where you've been

		Position m_curPos;
		Position m_startPos;
		int m_rows;
		int m_cols;
		std::stack<Position> m_moveStack;
		std::queue<Position> m_moveQueue;

		int m_curStep;
};

#endif
