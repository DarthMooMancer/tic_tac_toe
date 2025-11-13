#pragma once

#include <array>
#include <string>

class Engine {
public:
	Engine();
	~Engine();
	void run();

private:
	std::string status;
	std::array<char, 9> view;
	void draw_display() const;
	char p1 { 'x' };
	char p2 { 'o' };
	char temp { p1 };
	bool process_input();
	bool check_game_over();
	bool check_line(char id) const;
};
