#include <window.hpp>
#include <ranges>
#include <iostream>

Window::Window() {
	for(auto &val : view) { val.fill('.'); }
	for(int i : std::ranges::views::iota(0, ROW)) {
		for(int j : std::ranges::views::iota(0, COL)) {
			if(i % 2 == 0 && j % 2 == 0) { view[i][j] = ' '; }
		}
	}
}

void Window::draw_display() {
	std::cout << "\033[H" << std::flush; // Clear screen
	for(int i : std::ranges::views::iota(0, ROW)) {
		for(int j : std::ranges::views::iota(0, COL)) {
			if(view[i][j] != '.') { std::cout << view[i][j] << " "; }
			if(view[i][j] == '.') {
				if(i % 2 == 0) { std::cout << "| "; }
				if(i % 2 != 0 && j % 2 == 0) { std::cout << "- "; }
				if(i % 2 != 0 && j % 2 != 0) { std::cout << "+ "; }
			}
		}
		std::cout << "\r\n";
	}
}
