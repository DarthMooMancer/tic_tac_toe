#pragma once

#include <array>
#include <string>

struct Window {
	Window();
	std::array<char, 9> view;
	void draw_display() const;
};

class Engine {
public:
	Engine();
	~Engine();
	void run();

private:
	std::string status;
	Window win;
	char p1 { 'x' };
	char p2 { 'o' };
	char temp { p1 };
	bool process_input();
	bool check_game_over();
	bool check_line(char id) const;
};
