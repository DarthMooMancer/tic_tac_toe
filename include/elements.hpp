#ifndef ELEMENTS_HPP
#define ELEMENTS_HPP

struct Point {
	Point(int row, int col) : m_row(row), m_col(col) {};
	int m_row;
	int m_col;
	void assign(int row, int col);
};

struct Tile {
	Tile(int row, int col) : m_pos(row, col), m_symbol(' '), _delete(false) {};
	Tile(int row, int col, char symbol) : m_pos(row, col), m_symbol(symbol), _delete(false) {};
	char m_symbol;
	Point m_pos;
	bool _delete;
};

struct Border {
	Border(int row, int col, char symbol) : m_pos(row, col), m_symbol(symbol) {};
	char m_symbol;
	Point m_pos;
};

struct Player {
	Player(char symbol, bool turn) : m_symbol(symbol), m_turn(turn), m_win(false) {};
	char m_symbol;
	bool m_turn;
	bool m_win;
	void check_line(Tile (&tile_list)[9]);
};

#endif
