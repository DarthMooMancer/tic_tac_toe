#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <memory>
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
	std::unique_ptr<Window> win;

	struct Player {
		Player(char id) : id(id) {};
		char id;
	};

	const std::array<vec2, 9> map;

	struct GameState {
		Player player1;
		Player player2;
		Player *temp;
		GameState() : player1('x'), player2('o'), temp { &player1 } {};
	} state;
	bool process_input();
	bool exit_code();
	bool check_line(char id);
};

#endif
