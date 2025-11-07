#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <memory>

class Engine {
public:
	Engine();
	~Engine();
	void run();

private:
	std::unique_ptr<class Window> win;

	struct Player {
		Player(char id) : id(id) {};
		char id;
	};

	struct vec2 {
		vec2(int x, int y) : x(x), y(y) {}
		int x;
		int y;
	};

	struct GameState {
		Player player1;
		Player player2;
		Player *temp;
		GameState() : player1('x'), player2('o'), temp { &player1 } {};
	} state;
	void set_player();
	bool process_input();
	bool exit_code();
	bool check_line(char id);
};

#endif
