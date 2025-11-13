#include <cctype>
#include <engine.hpp>
#include <chrono>
#include <iostream>
#include <thread>

Window::Window() {
	view.fill(' ');
}

void Window::draw_display() const {
	std::cout << "\033[H"
		<< view[0] << " | " << view[1] << " | " << view[2]
		<< "\r\n- + - + -\r\n"
		<< view[3] << " | " << view[4] << " | " << view[5]
		<< "\r\n- + - + -\r\n"
		<< view[6] << " | " << view[7] << " | " << view[8]
		<< "\r\n"
	<< std::flush;
}

Engine::Engine() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
}

void Engine::run() {
	while (process_input()) {
		bool game_over = exit_code();
		if(!game_over) { status = "Current Player: " + std::string(1, temp->id) + "\n"; }
		win.draw_display();
		std::cout << status;
		if(game_over) { break; }
		std::this_thread::sleep_for(std::chrono::milliseconds(150));
	}
}

bool Engine::exit_code() {
	if(check_line(player1.id)) { status = "Game Over! Player 1 wins!"; return true; }
	if(check_line(player2.id)) { status = "Game Over! Player 2 wins!"; return true; }
	if(std::count(win.view.begin(), win.view.end(), ' ') == 0) {
		status = "Game Over! It's a tie!";
		return true;
	}

	return false;
}

bool Engine::process_input() {
	int ch, index;
	while((ch = getch()) != ERR) {
		if(ch == 'q') { return false; }
		if(ch >= '1' && ch <= '9') {
			index = ch - '1';
			if(win.view[index] == ' ') { win.view[index] = temp->id; }
			temp = (temp == &player1) ? &player2 : &player1;
		}
	}
	return true;
}

bool Engine::check_line(char id) const {
	static constexpr int wins[8][3] = {
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},
		{0, 4, 8}, {2, 4, 6}
	};
	for(const auto& i : wins) {
		if(win.view[i[0]] == id && win.view[i[1]] == id && win.view[i[2]] == id) {
			return true;
		}
	}
	return false;
}
