#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <array>

constexpr int ROW = 5;
constexpr int COL = 5;

struct Window {
	Window();
	std::array<std::array<char, COL>, ROW> view;
	void draw_display();
};

struct vec2 {
	vec2(int x, int y) : x(x), y(y) {}
	int x;
	int y;
};

class Engine {
public:
	Engine();
	~Engine();
	void run();

private:
	Window win;

	struct Player {
		Player(char id) : id(id) {};
		char id;
	};

	Player player1 { 'x' };
	Player player2 { 'o' };
	Player *temp { &player1 };
	bool process_input();
	bool exit_code();
	bool check_line(char id);
};

#endif
