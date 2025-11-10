#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <map>

constexpr int ROW = 5;
constexpr int COL = 5;

struct vec2 {
	int x, y;
	vec2(int x, int y) : x(x), y(y) {}
	auto operator <=> (const vec2&) const = default;
};

struct Window {
	Window();
	std::map<vec2, char> view;
	void draw_display();
};

class Engine {
public:
	Engine();
	~Engine();
	void run();

private:
	struct Player {
		Player(char id) : id(id) {};
		char id;
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
