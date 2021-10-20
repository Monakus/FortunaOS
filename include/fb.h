#ifndef FB_H
#define FB_H

// Text colors
#define FB_BLACK        0
#define FB_BLUE         1
#define FB_GREEN        2
#define FB_CYAN         3
#define FB_RED          4
#define FB_MAGENTA      5
#define FB_BROWN        6
#define FB_LT_GREY      7
#define FB_DARK_GREY    8
#define FB_LT_BLUE      9
#define FB_LT_GREEN    10
#define FB_LT_CYAN     11
#define FB_LT_RED      12
#define FB_LT_MAGENTA  13
#define FB_LT_BROWN    14
#define FB_WHITE       15

/* The I/O ports */
#define FB_COMMAND_PORT	0x3D4
#define FB_DATA_PORT 	0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND	14
#define FB_LOW_BYTE_COMMAND	    15

/** fb_move_cursor: 
*	Moves the cursor forawrd by one column in the framebuffer
*/
//static void fb_move_cursor();

/** fb_scroll: 
 *  Scrolls the framebuffer if needed
 */
void fb_scroll();

/** fb_putc: 
*	Writes a character with the fiven foreground and background to position i in the framebuffer.
*
*	@param c	The character
*	@param bg	The background color
*	@param fg	The foreground color
*/
void fb_putc(char c, unsigned char bg, unsigned char fg);

/** fb_write: 
*	Writes the contents of the buffer to the screen.
*
*	@param buf Pointer to the buffer containing the text
*/
void fb_write(char *buf);

/** fb_clear
*   Clear the framebuffer by setting everything to space with black background. 
*
*/
void fb_clear();

#endif