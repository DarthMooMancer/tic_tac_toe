#include "elements.hpp"

void Player::check_line(Tile (&tile_list)[9]) {
	for(int i = 0; i <= 6; i += 3) {
		if(tile_list[i].m_symbol == tile_list[i+1].m_symbol && tile_list[i+1].m_symbol == tile_list[i+2].m_symbol) {
			if(tile_list[i].m_symbol == m_symbol) {
				m_win = true;
			}
		}
	}
	if(tile_list[0].m_symbol == tile_list[4].m_symbol && tile_list[4].m_symbol == tile_list[8].m_symbol) {
		if(tile_list[0].m_symbol == m_symbol) {
			m_win = true;
		}
	}
	if(tile_list[2].m_symbol == tile_list[4].m_symbol && tile_list[4].m_symbol == tile_list[6].m_symbol) {
		if(tile_list[2].m_symbol == m_symbol) {
			m_win = true;
		}
	}
}
