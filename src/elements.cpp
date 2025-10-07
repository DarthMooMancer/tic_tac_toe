#include "elements.hpp"
#include "globals.hpp"

void cleanup(Point** buffer, int buffer_size) {
	for(int i = 0; i < buffer_size; i++) {
		delete buffer[i];
	}

}

void allocate_points(Point** buffer, char symbol) {
	int index = 0;
	for(int i = 0; i < ROW; i += 2) {
		for(int a = 0; a < ROW; a += 2) {
			buffer[index++] = new Point { i, a, symbol };
		}
	}
}

Player* get_current_player(Player* current_player, Player* player_one, Player* player_two) {
	if(current_player == nullptr) { current_player = player_one; }
	else if(current_player->m_id == 1) { current_player = player_two; }
	else if(current_player->m_id == 2) { current_player = player_one; }
	return current_player;
}

bool Player::on_line(Point** buffer) {
	for(int i = 0; i <= 6; i += 3) {
		if(buffer[i]->m_symbol == buffer[i+1]->m_symbol && buffer[i+1]->m_symbol == buffer[i+2]->m_symbol) {
			if(buffer[i]->m_symbol == m_symbol) {
				return true;
			}
		}
	}
	for(int i = 0; i < 3; i++) {
		if(buffer[i]->m_symbol == buffer[i+3]->m_symbol && buffer[i+3]->m_symbol == buffer[i+6]->m_symbol) {
			if(buffer[i]->m_symbol == m_symbol) {
				return true;
			}
		}
	}
	if(buffer[0]->m_symbol == buffer[4]->m_symbol && buffer[4]->m_symbol == buffer[8]->m_symbol) {
		if(buffer[0]->m_symbol == m_symbol) {
			return true;
		}
	}
	if(buffer[2]->m_symbol == buffer[4]->m_symbol && buffer[4]->m_symbol == buffer[6]->m_symbol) {
		if(buffer[2]->m_symbol == m_symbol) {
			return true;
		}
	}
	return false;
}
