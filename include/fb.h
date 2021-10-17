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
#define FB_LOW_BYTE_COMMAND	15

/**  fb_write_cell: 
*	Writes a character with the fiven foreground and background to position i in the framebuffer.
*
*	@param i	The location in the frambuffer
*	@param c	The character
*	@param fg	The foreground color
*	@param bg	The background color
*/
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);

/**  fb_move_cursor:
*	Moves the cursor of the frambuffer to the given position
*
*	@param pos The new position of the cursor
*/
void fb_move_cursor(unsigned short pos);

/** fb_write:
*	Writes the contents of the buffer to the screen
*
*	@param buf Pointer to the buffer containing the text
*	@param len Length of the text contained in the buffer
*/
int fb_write(char *buf, unsigned int len);

