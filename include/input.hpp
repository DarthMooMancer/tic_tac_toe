#ifndef INPUT_HPP
#define INPUT_HPP
#include "elements.hpp"

struct Input {
	int m_getch = 0;
	void get_input(bool &running, Tile (&tile_list)[9], Player &player_one, Player &player_two);
};

#endif // INPUT_HPP
