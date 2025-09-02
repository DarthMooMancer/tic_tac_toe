#include <iostream>
#include "elements.hpp"

Point::Point() {
	m_row = 0;
	m_col = 0;
}

void Point::assign(int row, int col) {
	m_row = row;
	m_col = col;
}

void Point::to_string() {
	std::cout << "(" << m_row << ", " << m_col << ")" << std::endl;
}

// Tile::Tile(int row, int col) {
// 	m_pos.assign(row, col);
// 	m_symbol = ' ';
// }
