#include "fb.h"

void run(){
	/*char* c = (char*) 10000;
	c[0] = 'H';
	c[1] = 'i';

	fb_write(c, 2);*/
	fb_write("Ala ma kota", 11);
	unsigned int cursor_start_pos = 480;
	fb_move_cursor(cursor_start_pos + 11);
}
