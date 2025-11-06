#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

#include <memory>

class Window;

struct Player {
	Player(char symbol, int id) : m_symbol(symbol), m_id(id) {};
	char m_symbol;
	int m_id;
	bool on_line();
};

class Engine {
public:
	Engine();
	~Engine();
	void run();

private:
	std::unique_ptr<Window> win;
	struct GameState {
		Player player1;
		Player player2;
		Player *temp;
		GameState() : player1('x', 1), player2('o', 2), temp { &player1 } {};
	} state;
	void get_current_player();
	bool process_input();
	bool exit_code();
};

#endif
