#include "fb.h"
#include "serial.h"

void run(){

	fb_clear();
	fb_write("To jest testowanko\n");
	// serial_init(SERIAL_COM1_BASE, 2);
	// serial_write_string("Ala ma kota", 11, SERIAL_COM1_BASE);
	fb_write("Po napisaniu do COM1");
	fb_write("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	fb_write("Test1\n");
	fb_write("Test2\n");
	fb_write("Test3\n");
	fb_write("Test4\nTest5\nTu sie powinno zescrollowac");
}
