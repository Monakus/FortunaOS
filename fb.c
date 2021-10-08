#include "fb.h"

/* Write a character to the framebuffer */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg){
	char *fb = (char *) 0x000B83C0;		//160(10) == A(16) == jedna linia w OS ma 160 bitow? jednostek?
	fb[i*2] = c;
	fb[i*2 + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

/* Move cursor in the framebuffer */
void fb_move_cursor(unsigned short pos){
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
	outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
	outb(FB_DATA_PORT, pos & 0x00FF);
}

/* Write text of set length in the frambuffer */
int fb_write(char *buf, unsigned int len){
	unsigned int i = 0;
	for(i=0; i<len; i++){
		fb_write_cell(i, buf[i], FB_BLACK, FB_WHITE);
	}
	//fb_move_cursor(491);			//jedna linia ma 80 kolumn, wiec 6*80 (6 linii) + 11 (dlugosc napisu)
	return 0;
}