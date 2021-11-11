#include "fb.h"
#include "serial.h"
#include "descriptor_tables.h"

int main(){
	init_descriptor_tables();

	fb_clear();
	fb_write("Hello, world!\n");

	asm volatile ("int $0x3");
	asm volatile ("int $0x4");

	fb_write("To dziala, jest pogchamp\n");
	asm volatile ("int $0x5");

	return 0;
}
