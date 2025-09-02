#include "window.hpp"
#include <iostream>
#include <chrono>
#include <thread>

void Window::update_display(Tile (&tile_list)[9], Border (&border_list)[16]) {
	for(std::array<char, COL> &row : m_board) { row.fill('.'); }

	for(int i = 0; i < 9; i++) {
		m_board[tile_list[i].m_pos.m_row][tile_list[i].m_pos.m_col] = tile_list[i].m_symbol;
	}
	for(int i = 0; i < 16; i++) {
		m_board[border_list[i].m_pos.m_row][border_list[i].m_pos.m_col] = border_list[i].m_symbol;
	}
	
	// Refresh and draw screen
	std::cout << "\033[H" << std::flush;
	for(std::array<char, COL> &row : m_board) {
		for(char &col : row) {
			std::cout << col << " ";
		}
		std::cout << "\r\n";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 1000 / fps; 200ms = 5fps
}
