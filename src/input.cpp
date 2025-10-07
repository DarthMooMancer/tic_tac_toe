#include <ncurses.h>
#include "input.hpp"
#include "elements.hpp"

void Input::get_input(bool &running, Point** buffer, Player *&current_player, Player *player_one, Player *player_two) {
	while(running) {
		initscr();
		cbreak();
		noecho();
		_getch = getch();
		endwin();
		if(_getch >= 49 && _getch <= 57) {
			if(_getch == 49 && buffer[0]->m_symbol == ' ') {
				buffer[0]->m_symbol = current_player->m_symbol;
				current_player = get_current_player(current_player, player_one, player_two);
			}
			else if(_getch == 50 && buffer[1]->m_symbol == ' ') {
				buffer[1]->m_symbol = current_player->m_symbol;
				current_player = get_current_player(current_player, player_one, player_two);
			}
			else if(_getch == 51 && buffer[2]->m_symbol == ' ') {
				buffer[2]->m_symbol = current_player->m_symbol;
				current_player = get_current_player(current_player, player_one, player_two);
			}
			else if(_getch == 52 && buffer[3]->m_symbol == ' ') {
				buffer[3]->m_symbol = current_player->m_symbol;
				current_player = get_current_player(current_player, player_one, player_two);
			}
			else if(_getch == 53 && buffer[4]->m_symbol == ' ') {
				buffer[4]->m_symbol = current_player->m_symbol;
				current_player = get_current_player(current_player, player_one, player_two);
			}
			else if(_getch == 54 && buffer[5]->m_symbol == ' ') {
				buffer[5]->m_symbol = current_player->m_symbol;
				current_player = get_current_player(current_player, player_one, player_two);
			}
			else if(_getch == 55 && buffer[6]->m_symbol == ' ') {
				buffer[6]->m_symbol = current_player->m_symbol;
				current_player = get_current_player(current_player, player_one, player_two);
			}
			else if(_getch == 56 && buffer[7]->m_symbol == ' ') {
				buffer[7]->m_symbol = current_player->m_symbol;
				current_player = get_current_player(current_player, player_one, player_two);
			}
			else if(_getch == 57 && buffer[8]->m_symbol == ' ') {
				buffer[8]->m_symbol = current_player->m_symbol;
				current_player = get_current_player(current_player, player_one, player_two);
			}
		}
		if(_getch == 113) {
			running = false;
		}
	}
}
