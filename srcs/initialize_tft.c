#include "tft_ili9486_at2560.h"

void initialize_tft(void) {
	/* Reset LCD Driver */
	pin_mode(LCD_RST, OUTPUT);
	digital_write(LCD_RST, HIGH);
	_delay_ms(1);
	digital_write(LCD_RST, LOW);
	_delay_ms(10);
	digital_write(LCD_RST, HIGH);
	_delay_ms(120);

	pin_mode(LCD_CS, OUTPUT);
	pin_mode(LCD_RS, OUTPUT);
	pin_mode(LCD_RD, OUTPUT);
	ddr_write(E, 0x38, 0x38);
	ddr_write(G, 0x20, 0x20);
	ddr_write(H, 0x78, 0x78);
	pin_mode(LCD_WR, OUTPUT);

	/* Init Screen */
	// Soft Reset (resets the commands and parameters to their S/W Reset default values)
	write_bus(0x01, COMMAND);
	_delay_ms(5);
	// Sleep Out
	write_bus(0x11, COMMAND);
	_delay_ms(120);
	// Set pixel format to RGB565 (16bit)
	write_bus(0x3A, COMMAND);
	// 0101 0101
	write_bus(0x55, INDEX);
	// Memory Access Control (Vertical Mode)
	write_bus(0x36, COMMAND);
	write_bus(0x08, INDEX);
	// Display on
	write_bus(0x29, COMMAND);
}
