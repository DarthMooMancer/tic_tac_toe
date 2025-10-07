#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

struct Point;
struct Player;
void cleanup(Point** buffer, int buffer_size);
void allocate_points(Point** buffer, char symbol);
Player* get_current_player(Player* current_player, Player* player_one, Player* player_two);

struct Point {
	Point(int row, int col, char symbol) : m_row(row), m_col(col), m_symbol(symbol) {};
	int m_row;
	int m_col;
	char m_symbol;
};

struct Player {
	Player(char symbol, bool turn, int id) : m_symbol(symbol), m_id(id) {};
	char m_symbol;
	int m_id;
	bool on_line(Point** buffer);
};

#endif
