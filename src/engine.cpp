#include <engine.hpp>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <format>
#include <iostream>
#include <thread>

Window::Window() {
	view.fill(' ');
}

void Window::draw_display() const {
	std::cout << "\033[H" << std::format(
		"{} | {} | {}\r\n- + - + -\r\n{} | {} | {}\r\n- + - + -\r\n{} | {} | {}\r\n",
		view.at(0), view.at(1), view.at(2),
		view.at(3), view.at(4), view.at(5), 
		view.at(6), view.at(7), view.at(8)
	) << std::flush;
}

Engine::Engine() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
}

void Engine::run() {
	while (exit_code() && process_input()) {
		win.draw_display();
		std::cout << "Current Player: " << temp->id << "\r\n";
		std::this_thread::sleep_for(std::chrono::milliseconds((int) (150)));
	}
}

bool Engine::exit_code() {
	if(check_line(player1.id)) {
		std::cout << "Game Over! Player 1 wins!\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return false;
	} else if(check_line(player2.id)) {
		std::cout << "Game Over! Player 2 wins!\n";
		std::this_thread::sleep_for(std::chrono::seconds(2));
		return false;
	}

	int filled = std::ranges::count_if(win.view, [](const auto &sym) { return sym != ' '; });

	if(filled == ROW * COL) {
		std::cout << "Game Over! Its a tie!\n";
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
			if(win.view.at(index) != ' ') continue;
			win.view.at(index) = temp->id;
			if(temp->id == 'x') { temp = &player2; }
			else if(temp->id == 'o') { temp = &player1; }
		}
	}
	return true;
}

bool Engine::check_line(char id) {
	for(int i = 0; i < COL; i++) {
		if(win.view.at(i) == id && win.view.at(i + 3) == id && win.view.at(i + 6) == id) {
			return true;
		}
	}
	for(int i = 0; i < ROW * COL; i += ROW) {
		if(win.view.at(i) == id && win.view.at(i + 1) == id && win.view.at(i + 2) == id) {
			return true;
		}
	}
	auto same_symbol = [&](int first, int last) {
		return win.view.at(first) == id &&
		win.view.at(4) == id &&
		win.view.at(last) == id;
	};
	return same_symbol(0, 8) || same_symbol(2, 6);
}
