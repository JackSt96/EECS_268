/*
 * File:   Position.h
 * Author: Jack
 * Purpose: the position methods for the program
 * Created on November 16, 2015, 12:01 PM
 */


#ifndef POSI
#define POSI

class Position{

	public:

/**	This constructs an ordered pair of integers
*	@pre - none
*	@post Position created with row and col values set.
*	@post - void
*/
	Position(int row, int col);

	Position();


/**
*	@pre - a valid position exists with initialize members
*	@return row value
*	@post - returns the value of m_row
*/
	int getRow() const;

/**
*	@pre - a valid position exists with initialize members
*	@return col value
*	@post - returns the value of m_col
*/
	int getCol() const;


/**
*	@pre - a valid position exists
*	@return void
*	@post - sets the m_row to val
*/
	void setRow(int val);

/**
*	@pre - a valid position exists
*	@return void
*	@post - sets m_col to val
*/
	void setCol(int val);





	private:

	int m_row;
	int m_col;

};

#endif
