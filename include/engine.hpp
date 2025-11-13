#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <array>
#include <ncurses.h>

constexpr int ROW = 3;
constexpr int COL = 3;

struct Window {
	Window();
	std::array<char, ROW * COL> view;
	void draw_display() const;
};

class Engine {
public:
	Engine();
	~Engine() { endwin(); };
	void run();

private:
	struct Player {
		Player(char id) : id(id) {};
		const char id;
	};

	Window win;
	Player player1 { 'x' };
	Player player2 { 'o' };
	Player *temp { &player1 };
	bool process_input();
	bool exit_code();
	bool check_line(char id);
};

#endif
