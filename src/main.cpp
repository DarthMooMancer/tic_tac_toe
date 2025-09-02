#include <iostream>
#include <thread>
#include "window.hpp"
#include "input.hpp"
#include "elements.hpp"
#include "globals.hpp"

int main() {
	Input input;
	Window window;
	Player player_one('x', true);
	Player player_two('o', false);
	bool running = true;

	Tile tile_list[9] = {
		Tile(0, 0), Tile(0, 2), Tile(0, 4),
		Tile(2, 0), Tile(2, 2), Tile(2, 4),
		Tile(4, 0), Tile(4, 2), Tile(4, 4)
	};
	Border border_list[16] = {
		Border(0, 1, '|'), Border(0, 3, '|'),
		Border(1, 0, '-'), Border(1, 1, '+'), Border(1, 2, '-'), Border(1, 3, '+'), Border(1, 4, '-'), 
		Border(2, 1, '|'), Border(2, 3, '|'),
		Border(3, 0, '-'), Border(3, 1, '+'), Border(3, 2, '-'), Border(3, 3, '+'), Border(3, 4, '-'), 
		Border(4, 1, '|'), Border(4, 3, '|'),
	};

	std::thread input_thread(&Input::get_input, &input, std::ref(running), std::ref(tile_list), std::ref(player_one), std::ref(player_two));
	while (running) {
		window.update_display(tile_list, border_list);
	}

	input_thread.join();
	return 0;
}
