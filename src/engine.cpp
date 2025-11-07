#include <algorithm>
#include <engine.hpp>
#include <chrono>
#include <iostream>
#include <ncurses.h>
#include <thread>
#include <ranges>

Window::Window() : view {
	{ { 0, 0 }, ' ' }, { { 2, 0 }, ' ' }, { { 4, 0 }, ' ' },
	{ { 0, 2 }, ' ' }, { { 2, 2 }, ' ' }, { { 4, 2 }, ' ' },
	{ { 0, 4 }, ' ' }, { { 2, 4 }, ' ' }, { { 4, 4 }, ' ' }
} {}

void Window::draw_display() {
	char c;
	std::cout << "\033[H" << std::flush; // Clear screen
	for(int i : std::ranges::views::iota(0, ROW)) {
		for(int j : std::ranges::views::iota(0, COL)) {
			if(i % 2 == 0 && j % 2 == 0) { c = view[{i, j}]; }
			else if(i % 2 == 0) { c =  '|'; }
			else if(j % 2 == 0) { c =  '-'; }
			else { c = '+'; }
			std::cout << c << " ";
		}
		std::cout << "\r\n";
	}
}

Engine::Engine() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
}

Engine::~Engine() {}

void Engine::run() {
	while (exit_code() && process_input()) {
		win.draw_display();
		std::cout << "Current Player: " << temp->id << "\n";
		std::this_thread::sleep_for(std::chrono::milliseconds((int) (150)));
	}
	endwin();
}

bool Engine::exit_code() {
	if(check_line(player1.id)) {
		std::cout << "Game Over! Player 1 wins!" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return false;
	} else if(check_line(player2.id)) {
		std::cout << "Game Over! Player 2 wins!" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return false;
	}
	int filled = std::ranges::count_if(win.view, [](const auto &pair) {
		return pair.second != ' ';
	});

	if(filled == 9) {
		std::cout << "Game Over! Its a tie!" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return false;
	}
	return true;
}

bool Engine::process_input() {
	int ch, index, x, y;
	while((ch = getch()) != ERR) {
		if(ch == 'q') { return false; }
		if(ch >= '1' && ch <= '9') {
			index = ch - '1';
			x = (index % 3) * 2, y = (index / 3) * 2;
			if(win.view[{y, x}] != ' ') continue;
			win.view[{y, x}] = temp->id;
			if(temp->id == 'x') { temp = &player2; }
			else if(temp->id == 'o') { temp = &player1; }
		}
	}
	return true;
}

bool Engine::check_line(char id) {
	for(int i : std::ranges::views::iota(0, COL)) {
		if(COL % 2 != 0) continue;
		if(win.view[{0, i}] == id && win.view[{2, i}] == id && win.view[{4, i}] == id) {
			return true;
		}
	}
	for(int i : std::ranges::views::iota(0, ROW)) {
		if(ROW % 2 != 0) continue;
		if(win.view[{i, 0}] == id && win.view[{i, 2}] == id && win.view[{i, 4}] == id) {
			return true;
		}
	}
	auto same_symbol = [&](vec2 a, vec2 b) {
		return win.view[{a.y, a.x}] == id &&
		win.view[{2, 2}] == id &&
		win.view[{b.y, b.x}] == id;
	};
	return same_symbol({ 0, 0 }, { 4, 4 }) || same_symbol({ 4, 0 }, { 0, 4 });
}
