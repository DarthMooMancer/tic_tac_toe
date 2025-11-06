#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <globals.hpp>
#include <array>

struct Window {
	Window();
	std::array<std::array<char, COL>, ROW> view;
	void clear_display();
	void draw_display();
};

#endif
