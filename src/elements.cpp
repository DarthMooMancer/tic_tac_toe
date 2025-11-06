#include <elements.hpp>
#include <iostream>
#include <window.hpp>
#include <memory>
#include <ncurses.h>
#include <thread>
#include <ranges>

Engine::Engine() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	win = std::make_unique<Window>();
}

Engine::~Engine() {
	endwin();
}

void Engine::run() {
	while (exit_code() && process_input()) {
		win->draw_display();
		std::cout << "Current Player: " << state.temp->m_symbol << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds((int) (150))); // 1000 / fps; 200ms = 5fps
	}
}

bool Engine::exit_code() {
	int index = 0;
	// if(state.player1.on_line()) {
	// 	std::cout << "Game Over! Player 1 wins!" << std::endl;
	// 	return false;
	// } else if(state.player2.on_line()) {
	// 	std::cout << "Game Over! Player 2 wins!" << std::endl;
	// 	return false;
	// }
	for(auto &row : win->view) {
		for(auto val : row) {
			if(val != ' ') index++;
		}
	}
	if(index == 9) {
		std::cout << "Game Over! Its a tie!" << std::endl;
		return false;
	} else index = 0;
	return true;
}

bool Engine::process_input() {
	int ch;
	while((ch = getch()) != ERR) {
		if(ch == 113) { return false; }
		if(ch == 49) {
			win->view[0][0] = state.temp->m_symbol;
			get_current_player();
		} if(ch == 50) {
			win->view[0][2] = state.temp->m_symbol;
			get_current_player();
		} if(ch == 51) {
			win->view[0][4] = state.temp->m_symbol;
			get_current_player();
		} if(ch == 52) {
			win->view[2][0] = state.temp->m_symbol;
			get_current_player();
		} if(ch == 53) {
			win->view[2][2] = state.temp->m_symbol;
			get_current_player();
		} if(ch == 54) {
			win->view[2][4] = state.temp->m_symbol;
			get_current_player();
		} if(ch == 55) {
			win->view[4][0] = state.temp->m_symbol;
			get_current_player();
		} if(ch == 56) {
			win->view[4][2] = state.temp->m_symbol;
			get_current_player();
		} if(ch == 57) {
			win->view[4][4] = state.temp->m_symbol;
			get_current_player();
		}
	}
	return true;
}

void Engine::get_current_player() {
	if(state.temp->m_symbol == 'x') { state.temp = &state.player2; }
	else if(state.temp->m_symbol == 'o') { state.temp = &state.player1; }
}

// bool Player::on_line(vec2** buffer) {
// 	for(int i = 0; i <= 6; i += 3) {
// 		if(buffer[i]->m_symbol == buffer[i+1]->m_symbol && buffer[i+1]->m_symbol == buffer[i+2]->m_symbol) {
// 			if(buffer[i]->m_symbol == m_symbol) {
// 				return true;
// 			}
// 		}
// 	}
// 	for(int i = 0; i < 3; i++) {
// 		if(buffer[i]->m_symbol == buffer[i+3]->m_symbol && buffer[i+3]->m_symbol == buffer[i+6]->m_symbol) {
// 			if(buffer[i]->m_symbol == m_symbol) {
// 				return true;
// 			}
// 		}
// 	}
// 	if(buffer[0]->m_symbol == buffer[4]->m_symbol && buffer[4]->m_symbol == buffer[8]->m_symbol) {
// 		if(buffer[0]->m_symbol == m_symbol) {
// 			return true;
// 		}
// 	}
// 	if(buffer[2]->m_symbol == buffer[4]->m_symbol && buffer[4]->m_symbol == buffer[6]->m_symbol) {
// 		if(buffer[2]->m_symbol == m_symbol) {
// 			return true;
// 		}
// 	}
// 	return false;
// }
