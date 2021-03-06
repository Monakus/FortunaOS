#include "serial.h"

void serial_configure_baud_rate(unsigned short com, unsigned short divisor){
    outb(SERIAL_LINE_COMMAND_PORT(com), SERIAL_LINE_ENABLE_DLAB);
    outb(SERIAL_DATA_PORT(com), (divisor >> 8) & 0x00FF);
    outb(SERIAL_DATA_PORT(com), divisor & 0x00FF);
}

void serial_configure_line(unsigned short com){
    /* Bit:      | 7 | 6 | 5 4 3 | 2 | 1 0 |
    *  Content:  | d | b | prty  | s | dl  |
    *  Value:    | 0 | 0 | 0 0 0 | 0 | 1 1 | = 0x03
    */
    outb(SERIAL_LINE_COMMAND_PORT(com), 0x03);
}

void serial_init(unsigned short com, unsigned short divisor){
    serial_configure_baud_rate(com, divisor);
    serial_configure_line(com);
}

int serial_is_transmit_fifo_empty(unsigned int com){
    /* 0x20 = 0010 0000 */
    return inb(SERIAL_LINE_STATUS_PORT(com)) & 0x20;
}

int serial_write_string(char *buf, unsigned int len, unsigned short com){
    for(unsigned int i=0; i < len; i++){
        while(!serial_is_transmit_fifo_empty(com)); //waits for the FIFO to be empty
        outb(com, buf[i]);
    }
    return 0;
}