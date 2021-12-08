#pragma once

class coord {
private:
	int x;
	int y;

public:
	coord() : x(0), y(0) {};
	coord(int usr_x, int usr_y) : x(usr_x), y(usr_y) {};
	~coord() {};

	void set(int usr_x, int usr_y);
	void set_x(int usr_x);
	void set_y(int usr_y);
	const void get(int &out_x, int &out_y);
	const int  get_x(void);
	const int  get_y(void);
	void add(int add_x, int add_y);
	void add_x(int add_x);
	void add_y(int add_y);
};

