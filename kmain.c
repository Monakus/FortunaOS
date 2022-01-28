#include "fb.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"
#include "kheap.h"
#include "standard.h"

int main(){
	init_descriptor_tables();
	fb_clear();
	initialise_paging();

	u32int x = (u32int) kmalloc(8);
	fb_write_hex(x);
	fb_putc('\n', FB_BLACK, FB_WHITE);
	x = 73;
	fb_write_dec(x);
	fb_putc('\n', FB_BLACK, FB_WHITE);

	char *string = (char*) kmalloc(12);
	strcpy(string, "Ala ma kota");
	fb_write(string);
	return 0;
}
