#include "io.h"
#include "fb.h"
#include "common.h"

u16int *video_memory = (u16int*) 0xB8000;	//Address of the first cell in the framebuffer

// Stores the cursor position
u8int cursor_x = 0;
u8int cursor_y = 0;

u8int fb_width = 80; 	//Framebuffer is 80 columnds wide
u8int fb_height = 25; 	//Framebuffer is 25 rows high

void fb_move_cursor(){
	u16int cursorLocation = cursor_y * 80 + cursor_x;
	outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);		//Setting the high cursor byte
	outb(FB_DATA_PORT, cursorLocation);					//Send the high cursor byte
	outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);			//Setting the low cursor byte
	outb(FB_DATA_PORT, cursorLocation);					//Send the low cursor byte
}

void fb_scroll(){
    // Get a space character with the default colour attributes.
    u8int attributeByte = (FB_BLACK << 4) | (FB_WHITE & 0x0F);
    u16int blank = 0x20 | (attributeByte << 8);	// 0x20 == ' ' (space)

    // Row 25 is the end, this means we need to scroll up
    if(cursor_y >= fb_height){
        // Move the current text chunk that makes up the screen in the buffer by a line
        for (int i = 0; i < (fb_height-1)*fb_width; i++)
            video_memory[i] = video_memory[i+fb_width];

        // Clear the last line
        for (int i = (fb_height-1)*fb_width; i < fb_height*fb_width; i++)
            video_memory[i] = blank;

        // Move the cursor to the last line
        cursor_y = 24;
    }
}

void fb_putc(char c, unsigned char bg, unsigned char fg){

	//fb[i*2] = c;
	//fb[i*2 + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);


    // The attribute byte is made up of two nibbles - the lower being the 
    // foreground colour, and the upper the background colour
    u8int  attributeByte = (bg << 4) | (fg & 0x0F);
    // The attribute byte is the top 8 bits of the word we have to send to the VGA board
    u16int attribute = attributeByte << 8;
    u16int *location;

    // Backspace
    if (c == 0x08 && cursor_x)
        cursor_x--;

	//Tab
    else if (c == 0x09)
        cursor_x = (cursor_x+8) & ~(8-1);

    // Carriage return
    else if (c == '\r')
        cursor_x = 0;

    // Newline
    else if (c == '\n'){
        cursor_x = 0;
        cursor_y++;
    }

    // Other characters
    else if(c >= ' '){
        location = video_memory + (cursor_y*fb_width + cursor_x);
        *location = c | attribute;
        cursor_x++;
    }

	// Check if we need a newline
    if (cursor_x >= fb_width){
        cursor_x = 0;
        cursor_y ++;
    }

    fb_scroll();
    fb_move_cursor();
}	

void fb_clear(){
    u8int attributeByte = (FB_BLACK << 4) | (FB_WHITE & 0x0F);
    u16int blank = 0x20 | (attributeByte << 8);	// 0x20 == ' ' (space)

    for (int i = 0; i < 80*25; i++)
        video_memory[i] = blank;

    // Move the hardware cursor back to the start
    cursor_x = 0;
    cursor_y = 0;
    fb_move_cursor();
}

void fb_write(char *buf){
	int i = 0;
	while(buf[i])
		fb_putc(buf[i++], FB_BLACK, FB_WHITE);
}


