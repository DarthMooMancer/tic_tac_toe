#include "input.hpp"
#include <ncurses.h>

void _switch_turn(int favor, Player &player_one, Player &player_two) {
	if(favor == 1) {
		player_one.m_turn = true;
		player_two.m_turn = false;
	} else if(favor == 2) {
		player_one.m_turn = false;
		player_two.m_turn = true;
	}
}

void Input::get_input(bool &running, Tile (&tile_list)[9], Player &player_one, Player &player_two) {
	while(running) {
		initscr();
		cbreak();
		noecho();

		m_getch = getch();

		endwin();
		if(m_getch == 113) {
			running = false;
		} if(player_one.m_turn) {
			if(!tile_list[m_getch - 48]._delete) {
				tile_list[m_getch - 48].m_symbol = player_one.m_symbol;
				m_getch = 48;
				_switch_turn(2, player_one, player_two);
				tile_list[m_getch - 48]._delete = true;
			}
		} else if(player_two.m_turn) {
			if(!tile_list[m_getch - 48]._delete) {
				tile_list[m_getch - 48].m_symbol = player_two.m_symbol;
				m_getch = 48;
				_switch_turn(1, player_one, player_two);
				tile_list[m_getch - 48]._delete = true;
			}
		}
	}
}
