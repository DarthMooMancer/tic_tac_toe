#include "window.hpp"
#include <iostream>
#include <chrono>
#include <thread>

// void Window::terminate(Tile (&tile_list)[9], bool &running) {
// 	if(tile_list[0]._delete && tile_list[0].m_symbol != ' '
// 	&& tile_list[1]._delete && tile_list[1].m_symbol != ' '
// 	&& tile_list[2]._delete && tile_list[2].m_symbol != ' '
// 	&& tile_list[3]._delete && tile_list[3].m_symbol != ' '
// 	&& tile_list[4]._delete && tile_list[4].m_symbol != ' '
// 	&& tile_list[5]._delete && tile_list[5].m_symbol != ' '
// 	&& tile_list[6]._delete && tile_list[6].m_symbol != ' '
// 	&& tile_list[7]._delete && tile_list[7].m_symbol != ' '
// 	&& tile_list[8]._delete && tile_list[8].m_symbol != ' ') {
// 		std::cout << "Game Over! Tie" << std::endl;
// 		running = false;
//
// 	}
// }

void Window::clear_display() {
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			m_board[i][j] = nullptr;
		}
	}
}

void Window::draw_display(int milliseconds) {
	std::cout << "\033[H" << std::flush; // Clear screen
	for(int i = 0; i < ROW; i++) {
		for(int j = 0; j < COL; j++) {
			if(m_board[i][j] == nullptr) {
				if(i % 2 == 0) { std::cout << "| "; }
				if(i % 2 != 0 && j % 2 == 0) { std::cout << "- "; }
				if(i % 2 != 0 && j % 2 != 0) { std::cout << "+ "; }
			}
			if(m_board[i][j] != nullptr) { std::cout << m_board[i][j]->m_symbol << " "; }
		}
		std::cout << "\r\n";
	}
	std::this_thread::sleep_for(std::chrono::milliseconds((int) (milliseconds))); // 1000 / fps; 200ms = 5fps
}

void Window::update_display(Point** buffer) {
	for(int i = 0; i < 9; i++) {
		if(buffer[i] != nullptr) {
			m_board[buffer[i]->m_row][buffer[i]->m_col] = buffer[i];
		}
	}
}
