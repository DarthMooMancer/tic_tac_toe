#include <engine.hpp>
#include <algorithm>
#include <array>
#include <chrono>
#include <ncurses.h>
#include <thread>

Window::Window() {
	view.fill(' ');
}

void Window::draw_display() const {
	clear();
	mvprintw(0, 0, " %c | %c | %c ", view[0], view[1], view[2]);
	mvprintw(1, 0, " - + - + - ");
	mvprintw(2, 0, " %c | %c | %c ", view[3], view[4], view[5]);
	mvprintw(3, 0, " - + - + - ");
	mvprintw(4, 0, " %c | %c | %c ", view[6], view[7], view[8]);
}

Engine::Engine() {
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr, true);
}

Engine::~Engine() { endwin(); }

void Engine::run() {
	while (process_input()) {
		bool game_over = check_game_over();
		if(!game_over) { status = "Current Player: " + std::string(1, temp) + "\n"; }
		win.draw_display();
		mvprintw(6, 0, status.c_str());
		refresh();
		if(game_over) { break; }
	}

	mvprintw(7, 0, "Press any key to quit.");
	nodelay(stdscr, false);
	getch();
}

bool Engine::check_game_over() {
	if(check_line(p1)) { return status = "Game Over! Player 1 wins!", true; }
	if(check_line(p2)) { return status = "Game Over! Player 2 wins!", true; }
	if(std::ranges::count(win.view, ' ') == 0) {
		return status = "Game Over! It's a tie!", true;
	}

	return false;
}

bool Engine::process_input() {
	int ch, index;
	bool hit = false;
	while((ch = getch()) != ERR) {
		hit = true;
		if(ch == 'q') { return false; }
		if(ch < '1' || ch > '9') continue;
		index = ch - '1';
		if(win.view[index] == ' ') {
			win.view[index] = temp;
			temp = (temp == p1) ? p2 : p1;
		}
	}
	if(!hit) { std::this_thread::sleep_for(std::chrono::milliseconds(150)); }
	return true;
}

bool Engine::check_line(char id) const {
	static constexpr std::array<std::array<int, 3>, 8> wins = {{
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},
		{0, 4, 8}, {2, 4, 6}
	}};
	for(const auto& i : wins) {
		if(win.view[i[0]] == id && win.view[i[1]] == id && win.view[i[2]] == id) {
			return true;
		}
	}
	return false;
}
