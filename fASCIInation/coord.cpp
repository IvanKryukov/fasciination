#include "coord.h"

void coord::set(int usr_x, int usr_y) {
	x = usr_x;
	y = usr_y;
}

void coord::set_x(int usr_x) {
	x = usr_x;
}

void coord::set_y(int usr_y) {
	y = usr_y;
}

const void coord::get(int& out_x, int& out_y) {
	out_x = x;
	out_y = y;
}

const int  coord::get_x(void) {
	return x;
}

const int  coord::get_y(void) {
	return y;
}

void coord::add(int add_x, int add_y) {
	x += add_x;
	y += add_y;
}

void coord::add_x(int add_x) {
	x += add_x;
}

void coord::add_y(int add_y) {
	y += add_y;
}