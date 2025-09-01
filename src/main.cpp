#include <iostream>
#include <thread>
#include "window.hpp"
#include "input.hpp"

int main() {
	Input input;
	Window window;
	bool running = true;
	std::thread input_thread(&Input::get_input, &input, std::ref(running));

	while (running) {
		std::cout << "Hello World" << std::endl;
	}

	input_thread.join();
	return 0;
}
