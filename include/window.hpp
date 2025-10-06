#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "globals.hpp"
#include "elements.hpp"

struct Window {
	Point* m_board[ROW][COL] = {};
	// void terminate(Tile (&tile_list)[9], bool &running);

	void clear_display();
	void update_display(Point** buffer);
	void draw_display(int fps);
};

#endif
