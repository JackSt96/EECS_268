/*
 * File:   MazeWalker.cpp
 * Author: Jack
 * Purpose: maze driver, uses maze walker methods
 * Created on November 16, 2015, 12:01 PM
 */

#include "MazeWalker.h"

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice){

	m_visited = new int*[rows];
	m_curStep = 0;
	for(int i = 0; i<rows; i++){
		m_visited[i] = new int[cols];
		for(int j = 0; j<cols; j++){
			m_visited[i][j] = m_curStep;
		}
	}
	m_curStep++;
	m_visited[startRow][startCol] = m_curStep;
	m_curStep++;
	m_curPos.setRow(startRow);
	m_curPos.setCol(startCol);
	m_startPos.setRow(startRow);
	m_startPos.setCol(startCol);
	m_searchType = searchChoice;
	m_rows = rows;
	m_cols = cols;
	m_maze = mazePtr;

}

MazeWalker::~MazeWalker(){

	for(int i = 0; i< m_rows; i++){
		delete [] m_visited[i];
	}
	delete [] m_visited;
	while(!m_moveQueue.empty()){
		m_moveQueue.pop();
	}
	while(!m_moveStack.empty()){
		m_moveStack.pop();
	}

}

bool MazeWalker::walkMaze(){

	bool notDone = true;
	bool success = false;

	while(notDone){
		storeValidMoves();
		if(isGoalReached()){
			notDone = false;
			success = true;
		}
		else{
			if(m_searchType == Search::DFS){
				if(m_moveStack.empty()){
					notDone = false;
				}
				else{
					move(m_moveStack.top());
				}
			}
			else{

				if(m_moveQueue.empty()){
					notDone = false;
				}
				else{
					move(m_moveQueue.front());
				}

			}
		}

	}

	if(success){
		return true;
	}
	else{
		return false;
	}


}//runs the algo

void MazeWalker::storeValidMoves(){

	//check right
	if((m_curPos.getCol()+1)<m_cols){//if within bounds
		 //if not visited
		if(!(m_visited[m_curPos.getRow()][m_curPos.getCol()+1] > 0)){

			if(m_maze[m_curPos.getRow()][(m_curPos.getCol()+1)]=='P' ||
				m_maze[m_curPos.getRow()][m_curPos.getCol()+1]=='E'){

				if(m_searchType == Search::DFS){
					Position temp(m_curPos.getRow(), m_curPos.getCol()+1);
					m_moveStack.push(temp);
				}
				else{
					Position temp(m_curPos.getRow(), m_curPos.getCol()+1);
					m_moveQueue.push(temp);
				}
			}
		}
	}


	//check down

	if((m_curPos.getRow()+1)<m_rows){//if within bounds
		 //if not visited
		if(!(m_visited[m_curPos.getRow()+1][m_curPos.getCol()]> 0) ){
			if(m_maze[m_curPos.getRow()+1][m_curPos.getCol()]=='P' ||
				m_maze[m_curPos.getRow()+1][m_curPos.getCol()]=='E'){
				if(m_searchType == Search::DFS){
					Position temp(m_curPos.getRow()+1, m_curPos.getCol());
					m_moveStack.push(temp);
				}
				else{
					Position temp(m_curPos.getRow()+1, m_curPos.getCol());
					m_moveQueue.push(temp);
				}
			}
		}
	}

	//check left

	if((m_curPos.getCol()-1)>=0){//if within bounds
		 //if not visited
		if(!(m_visited[m_curPos.getRow()][m_curPos.getCol()-1]>0)){
			if(m_maze[m_curPos.getRow()][m_curPos.getCol()-1]=='P' ||
				m_maze[m_curPos.getRow()][m_curPos.getCol()-1]=='E'){
				if(m_searchType == Search::DFS){
					Position temp(m_curPos.getRow(), m_curPos.getCol()-1);
					m_moveStack.push(temp);
				}
				else{
					Position temp(m_curPos.getRow(), m_curPos.getCol()-1);
					m_moveQueue.push(temp);
				}
			}
		}

	}


	//check up
	if((m_curPos.getRow()-1)>=0){//if within bounds
		 //if not visited
		if(!(m_visited[m_curPos.getRow()-1][m_curPos.getCol()] > 0)){
			if(m_maze[m_curPos.getRow()-1][m_curPos.getCol()]=='P' ||
				m_maze[m_curPos.getRow()-1][m_curPos.getCol()]=='E'){
				if(m_searchType == Search::DFS){
					Position temp(m_curPos.getRow()-1, m_curPos.getCol());
					m_moveStack.push(temp);
				}
				else{
					Position temp(m_curPos.getRow()-1, m_curPos.getCol());
					m_moveQueue.push(temp);
				}
			}
		}

	}

}//check all adjacents and load up the ADT

void MazeWalker::move(Position& p){//change position, update visited, pop move
//	printMaze(m_visited, m_rows, m_cols);
	m_curPos.setRow(p.getRow());
	m_curPos.setCol(p.getCol());
	m_visited[m_curPos.getRow()][m_curPos.getCol()] = m_curStep;
	m_curStep++;

	if(m_searchType == Search::DFS){
		m_moveStack.pop();
	}
	else{
		m_moveQueue.pop();
	}

}

const int* const* MazeWalker::getVisited() const{
	return m_visited;
}

int MazeWalker::getVisitedRows() const{
	return m_rows;
}

/**
*	@return number of cols in maze
*/

int MazeWalker::getVisitedCols() const{
	return m_cols;
}


bool MazeWalker::isGoalReached() const{//check after validating array bounds

	if(m_maze[m_curPos.getRow()][m_curPos.getCol()]=='E'){
		return true;
	}
	return false;

}
