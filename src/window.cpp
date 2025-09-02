#include "window.hpp"
#include <iostream>
#include <chrono>
#include <thread>

void Window::terminate(Tile (&tile_list)[9], bool &running) {
	if(tile_list[0]._delete && tile_list[0].m_symbol != ' '
	&& tile_list[1]._delete && tile_list[1].m_symbol != ' '
	&& tile_list[2]._delete && tile_list[2].m_symbol != ' '
	&& tile_list[3]._delete && tile_list[3].m_symbol != ' '
	&& tile_list[4]._delete && tile_list[4].m_symbol != ' '
	&& tile_list[5]._delete && tile_list[5].m_symbol != ' '
	&& tile_list[6]._delete && tile_list[6].m_symbol != ' '
	&& tile_list[7]._delete && tile_list[7].m_symbol != ' '
	&& tile_list[8]._delete && tile_list[8].m_symbol != ' ') {
		std::cout << "Game Over! Tie" << std::endl;
		running = false;

	}
}

void Window::update_display(Tile (&tile_list)[9], Border (&border_list)[16]) {
	for(std::array<char, COL> &row : m_board) { row.fill('.'); }

	for(int i = 0; i < 9; i++) {
		m_board[tile_list[i].m_pos.m_row][tile_list[i].m_pos.m_col] = tile_list[i].m_symbol;
	}
	for(int i = 0; i < 16; i++) {
		m_board[border_list[i].m_pos.m_row][border_list[i].m_pos.m_col] = border_list[i].m_symbol;
	}
	
	std::cout << "\033[H" << std::flush;
	for(std::array<char, COL> &row : m_board) {
		for(char &col : row) {
			std::cout << col << " ";
		}
		std::cout << "\r\n";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds(200)); // 1000 / fps; 200ms = 5fps
}
