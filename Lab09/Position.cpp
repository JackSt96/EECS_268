/*
 * File:   Position.cpp
 * Author: Jack
 * Purpose: the position methods for the program
 * Created on November 16, 2015, 12:01 PM
 */

#include "Position.h"

Position::Position(int row, int col){

	m_row = row;
	m_col = col;

}

Position::Position(){
	Position(0,0);
}

int Position::getRow() const{

	return m_row;

}

int Position::getCol() const{

	return m_col;

}

void Position::setRow(int val){
	m_row = val;
}

void Position::setCol(int val){
	m_col = val;
}
