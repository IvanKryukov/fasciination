#pragma once
#include "coord.h"

class bodyobj {
private:
	coord crd;
	coord drct_look;
	coord drct_move;
	char skin;
public:
	bodyobj();
	bodyobj(coord usr_crd, coord usr_drct, char usr_skin);
	~bodyobj() {};

	void set_skin(const char usr_skin);
	const char get_skin(void);
	bool is_move(void);

	const coord get_coord(void);
	const int get_coord_x(void);
	const int get_coord_y(void);

	void set_drct_look_x(const int usr_look_x);
	void set_drct_look_y(const int usr_look_y);
	const coord get_drct_look(void);
	const int get_drct_look_x(void);
	const int get_drct_look_y(void);

	void set_drct_move_x(const int usr_drct_x);
	void set_drct_move_y(const int usr_drct_y);
	const coord get_drct_move(void);
	const int get_drct_move_x(void);
	const int get_drct_move_y(void);

	bool update_coord(void);
};

