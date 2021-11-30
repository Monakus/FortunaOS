#include "fb.h"
#include "serial.h"
#include "descriptor_tables.h"
#include "timer.h"

int main(){
	init_descriptor_tables();

	fb_clear();
	fb_write("Hello, world!\n");

	asm volatile ("int $0x3");
	asm volatile ("int $0x4");

	asm volatile ("sti");
	init_timer(50);

	return 0;
}
