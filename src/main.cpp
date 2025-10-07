#include <iostream>
#include <thread>
#include "window.hpp"
#include "input.hpp"
#include "elements.hpp"

bool should_exit(Point** buffer, Player &one, Player &two, bool &running) {
	int i, index = 0;
	if(one.on_line(buffer)) {
		std::cout << "Game Over! Player 1 wins!" << std::endl;
		return true;
	} else if(two.on_line(buffer)) {
		std::cout << "Game Over! Player 2 wins!" << std::endl;
		return true;
	}
	for(i = 0; i < 9; i++) {
		if(buffer[i]->m_symbol != ' ' && !one.on_line(buffer) && !one.on_line(buffer)) {
			index++;
		}
	}
	if(index == 9) {
		std::cout << "Game Over! Its a tie!" << std::endl;
		return true;
	} else {
		index = 0;
	}
	return false;
}

int main() {
	Input input;
	Window window;
	Player player_one('x', true, 1);
	Player player_two('o', false, 2);
	Player* default_player = get_current_player(nullptr, &player_one, &player_two);
	bool running = true;
	int count = 0;
	Point* buffer[9] = {};
	allocate_points(buffer, ' ');

	std::thread input_thread([&] { input.get_input(running, buffer, default_player, &player_one, &player_two); } );

	while (running) {
		if(should_exit(buffer, player_one, player_two, running)) {
			running = false;
		}
		window.clear_display();
		window.update_display(buffer);
		window.draw_display(150);
		std::cout << "Current Player: " << default_player->m_symbol << std::endl;
	}
	cleanup(buffer, 9);
	input_thread.join();
	return 0;
}
