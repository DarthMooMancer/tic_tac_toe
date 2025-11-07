#include <chrono>
#include <engine.hpp>
#include <iostream>
#include <memory>
#include <ncurses.h>
#include <thread>
#include <ranges>

Window::Window() {
	for(auto &val : view) { val.fill('.'); }
	for(int i : std::ranges::views::iota(0, ROW)) {
		for(int j : std::ranges::views::iota(0, COL)) {
			if(i % 2 == 0 && j % 2 == 0) { view[i][j] = ' '; }
		}
	}
}

void Window::draw_display() {
	std::cout << "\033[H" << std::flush; // Clear screen
	for(int i : std::ranges::views::iota(0, ROW)) {
		for(int j : std::ranges::views::iota(0, COL)) {
			if(i % 2 == 0 && j % 2 == 0) { std::cout << view[i][j] << " "; }
			else if(i % 2 == 0) { std::cout << "| "; }
			else if(i % 2 != 0 && j % 2 == 0) { std::cout << "- "; }
			else if(i % 2 != 0 && j % 2 != 0) { std::cout << "+ "; }
		}
		std::cout << "\r\n";
	}
}

Engine::Engine() : 
	map {
		vec2 { 0, 0 }, vec2 { 2, 0 }, vec2 { 4, 0 },
		vec2 { 0, 2 }, vec2 { 2, 2 }, vec2 { 4, 2 },
		vec2 { 0, 4 }, vec2 { 2, 4 }, vec2 { 4, 4 }
	} {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
	win = std::make_unique<Window>();
}

Engine::~Engine() {}

void Engine::run() {
	while (exit_code() && process_input()) {
		win->draw_display();
		std::cout << "Current Player: " << state.temp->id << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds((int) (150)));
	}
	endwin();
}

bool Engine::exit_code() {
	int index = 0;
	if(check_line(state.player1.id)) {
		std::cout << "Game Over! Player 1 wins!" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return false;
	} else if(check_line(state.player2.id)) {
		std::cout << "Game Over! Player 2 wins!" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return false;
	}
	for(auto &row : win->view) {
		for(auto val : row) {
			if(val != ' ') index++;
		}
	}
	if(index == 9) {
		std::cout << "Game Over! Its a tie!" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return false;
	} else index = 0;
	return true;
}

bool Engine::process_input() {
	int ch, index;
	while((ch = getch()) != ERR) {
		if(ch == 'q') { return false; }
		if(ch >= '1' && ch <= '9') {
			index = ch - '1';
			if(win->view[map[index].y][map[index].x] == ' ') {
				win->view[map[index].y][map[index].x] = state.temp->id;
				if(state.temp->id == 'x') { state.temp = &state.player2; }
				else if(state.temp->id == 'o') { state.temp = &state.player1; }
			}
		}
	}
	return true;
}

bool Engine::check_line(char id) {
	for(int i : std::ranges::views::iota(0, COL)) {
		if(COL % 2 != 0) continue;
		if(win->view[0][i] == id && win->view[2][i] == id && win->view[4][i] == id) {
			return true;
		}
	}
	for(int i : std::ranges::views::iota(0, ROW)) {
		if(ROW % 2 != 0) continue;
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
