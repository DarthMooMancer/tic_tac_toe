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
		std::cout << "Current Player: " << state.temp->id << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds((int) (150))); // 1000 / fps; 200ms = 5fps
	}
}

bool Engine::exit_code() {
	int index = 0;
	if(check_line(state.player1.id)) {
		std::cout << "Game Over! Player 1 wins!" << std::endl;
		return false;
	} else if(check_line(state.player2.id)) {
		std::cout << "Game Over! Player 2 wins!" << std::endl;
		return false;
	}
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
			win->view[0][0] = state.temp->id;
			get_current_player();
		} if(ch == 50) {
			win->view[0][2] = state.temp->id;
			get_current_player();
		} if(ch == 51) {
			win->view[0][4] = state.temp->id;
			get_current_player();
		} if(ch == 52) {
			win->view[2][0] = state.temp->id;
			get_current_player();
		} if(ch == 53) {
			win->view[2][2] = state.temp->id;
			get_current_player();
		} if(ch == 54) {
			win->view[2][4] = state.temp->id;
			get_current_player();
		} if(ch == 55) {
			win->view[4][0] = state.temp->id;
			get_current_player();
		} if(ch == 56) {
			win->view[4][2] = state.temp->id;
			get_current_player();
		} if(ch == 57) {
			win->view[4][4] = state.temp->id;
			get_current_player();
		}
	}
	return true;
}

void Engine::get_current_player() {
	if(state.temp->id == 'x') { state.temp = &state.player2; }
	else if(state.temp->id == 'o') { state.temp = &state.player1; }
}

bool Engine::check_line(char id) {
	for(int i : std::ranges::views::iota(0, COL)) {
		if(win->view[0][i] == id && win->view[2][i] == id && win->view[4][i] == id) {
			return true;
		}
	}
	for(int i : std::ranges::views::iota(0, ROW)) {
		if(win->view[i][0] == id && win->view[i][2] == id && win->view[i][4] == id) {
			return true;
		}
	}
	auto same_symbol = [&](vec2 a, vec2 b) {
		return win->view[a.y][a.x] == id &&
		win->view[2][2] == id &&
		win->view[b.y][b.x] == id;
	};
	return same_symbol({ 0, 0 }, { 4, 4 }) || same_symbol({ 4, 0 }, { 0, 4 });
}
