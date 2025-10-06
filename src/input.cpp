#include <ncurses.h>
#include "input.hpp"

// void _switch_turn(int favor, Player &player_one, Player &player_two) {
// 	if(favor == 1) {
// 		player_one.m_turn = true;
// 		player_two.m_turn = false;
// 	} else if(favor == 2) {
// 		player_one.m_turn = false;
// 		player_two.m_turn = true;
// 	}
// }

// void Input::get_input(bool &running, Tile (&tile_list)[9], Player &player_one, Player &player_two) {
void Input::get_input(bool &running) {
	while(running) {
		initscr();
		cbreak();
		noecho();

		_getch = getch();

		endwin();
		if(_getch == 113) {
			running = false;
		}
	}
}
