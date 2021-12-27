#include "fb.h"
#include "descriptor_tables.h"
#include "timer.h"
#include "paging.h"
#include "kheap.h"
#include "standard.h"

int main(){
	// init_descriptor_tables();

	// fb_clear();
	// fb_write("Hello, world!\n");

	// asm volatile ("int $0x3");
	// asm volatile ("int $0x4");

	// asm volatile ("sti");
	// init_timer(50);

    // init_descriptor_tables();
    // fb_clear();

    // initialise_paging();
    // fb_write("Hello, paging world!\n");

    // u32int *ptr = (u32int*)0xA0000000;
    // u32int do_page_fault = *ptr;

	// init_descriptor_tables();
	// fb_clear();

	// u32int a = kmalloc(8);
    // initialise_paging();
    // u32int b = kmalloc(8);
    // u32int c = kmalloc(8);
    // fb_write("a: ");
    // fb_write_hex(a);
    // fb_write(", b: ");
    // fb_write_hex(b);
    // fb_write("\nc: ");
    // fb_write_hex(c);

    // kfree(c);
    // kfree(b);
    // u32int d = kmalloc(12);
    // fb_write(", d: ");
    // fb_write_hex(d);
	// fb_putc('\n', FB_BLACK, FB_WHITE);
	// fb_write("To nadal dziala!");

	init_descriptor_tables();
	fb_clear();
	initialise_paging();

	u32int x = (u32int) kmalloc(8);
	fb_write_hex(x);
	fb_putc('\n', FB_BLACK, FB_WHITE);
	x = 69;
	fb_write_dec(x);
	fb_putc('\n', FB_BLACK, FB_WHITE);

	char *string = (char*) kmalloc(12);
	strcpy(string, "Ala ma kota");
	fb_write(string);
	return 0;
}
