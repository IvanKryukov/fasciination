#include "bodyobj.h"

bodyobj::bodyobj() {
	crd = coord();
	drct_look = coord(0, -1);
	drct_move = coord();
	skin = 0;
}

bodyobj::bodyobj(coord usr_crd, coord usr_drct_look, char usr_skin) {
	crd.set_x(usr_crd.get_x());
	crd.set_y(usr_crd.get_y());

	drct_look.set_x(usr_drct_look.get_x());
	drct_look.set_y(usr_drct_look.get_y());

	drct_move.set_x(0);
	drct_move.set_y(0);

	skin = usr_skin;
}

void bodyobj::set_skin(const char usr_skin) {
	skin = usr_skin;
}

const char bodyobj::get_skin(void) {
	return skin;
}

bool bodyobj::is_move(void)
{
	return ( (0 == drct_move.get_y()) && (0 == drct_move.get_x())) ? false : true;
}

const coord bodyobj::get_coord(void) {
	return crd;
}

const int bodyobj::get_coord_x(void) {
	return crd.get_x();
}

const int bodyobj::get_coord_y(void) {
	return crd.get_y();
}

void bodyobj::set_drct_look_x(const int usr_look_x) {
	int tmp_look = 0;
	
	if (usr_look_x != 0)
		tmp_look = (usr_look_x > 0) ? 1 : -1;

	drct_look.set_x(tmp_look);
	drct_look.set_y(0);
}

void bodyobj::set_drct_look_y(const int usr_look_y) {
	int tmp_look = 0;

	if (usr_look_y != 0)
		tmp_look = (usr_look_y > 0) ? 1 : -1;

	drct_look.set_y(tmp_look);
	drct_look.set_x(0);
}

const coord bodyobj::get_drct_look(void) {
	return drct_look;
}

const int bodyobj::get_drct_look_x(void) {
	return drct_look.get_x();
}

const int bodyobj::get_drct_look_y(void) {
	return drct_look.get_y();
}

void bodyobj::set_drct_move_x(const int usr_drct_move_x) {
	drct_move.set_x(usr_drct_move_x);
}

void bodyobj::set_drct_move_y(const int usr_drct_move_y) {
	drct_move.set_y(usr_drct_move_y);
}

const coord bodyobj::get_drct_move(void) {
	return drct_move;
}

const int bodyobj::get_drct_move_x(void) {
	return drct_move.get_x();
}

const int bodyobj::get_drct_move_y(void) {
	return drct_move.get_y();
}

bool bodyobj::update_coord(void)
{
	int ret = 0;

	if (0 == drct_look.get_x())
		skin = 'X';
	else
		skin = (drct_look.get_x() > 0) ? '>' : '<';

	if (0 != drct_look.get_y())
		skin = (drct_look.get_y() > 0) ? 'v' : '^';

	if (0 != drct_move.get_x())
	{
		crd.add_x(drct_move.get_x());
		ret++;
	}

	if (0 != drct_move.get_y())
	{
		crd.add_y(drct_move.get_y());
		ret++;
	}

	drct_move.set(0, 0);

	return (ret > 0) ? true : false;
}