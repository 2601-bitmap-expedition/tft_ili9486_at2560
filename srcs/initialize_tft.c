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

	/* Start Initial Sequence */
	write_bus(0x42, COMMAND);
	write_bus(0x18, INDEX);
	write_bus(0xA3, INDEX);
	write_bus(0x12, INDEX);
	write_bus(0x02, INDEX);
	write_bus(0xB2, INDEX);
	write_bus(0x12, INDEX);
	write_bus(0xFF, INDEX);
	write_bus(0x10, INDEX);
	write_bus(0x00, INDEX);

	write_bus(0xF8, COMMAND);
	write_bus(0x21, INDEX);
	write_bus(0x04, INDEX);

	write_bus(0xF9, COMMAND);
	write_bus(0x00, INDEX);
	write_bus(0x08, INDEX);

	write_bus(0x36, COMMAND);
	write_bus(0x08, INDEX);

	write_bus(0xB4, COMMAND);
	write_bus(0x00, INDEX);

	write_bus(0xC1, COMMAND);
	write_bus(0x41, INDEX);

	write_bus(0xC5, COMMAND);
	write_bus(0x00, INDEX);
	write_bus(0x53, INDEX);

	write_bus(0xE0, COMMAND);
	write_bus(0x0F, INDEX);
	write_bus(0x1B, INDEX);
	write_bus(0x18, INDEX);
	write_bus(0x0B, INDEX);
	write_bus(0x0E, INDEX);
	write_bus(0x09, INDEX);
	write_bus(0x47, INDEX);
	write_bus(0x94, INDEX);
	write_bus(0x35, INDEX);
	write_bus(0x0A, INDEX);
	write_bus(0x13, INDEX);
	write_bus(0x05, INDEX);
	write_bus(0x08, INDEX);
	write_bus(0x03, INDEX);
	write_bus(0x00, INDEX);

	write_bus(0xE1, COMMAND);
	write_bus(0x0F, INDEX);
	write_bus(0x3A, INDEX);
	write_bus(0x37, INDEX);
	write_bus(0x0B, INDEX);
	write_bus(0x0C, INDEX);
	write_bus(0x05, INDEX);
	write_bus(0x4A, INDEX);
	write_bus(0x24, INDEX);
	write_bus(0x39, INDEX);
	write_bus(0x07, INDEX);
	write_bus(0x10, INDEX);
	write_bus(0x04, INDEX);
	write_bus(0x27, INDEX);
	write_bus(0x25, INDEX);
	write_bus(0x00, INDEX);

	write_bus(0x11, COMMAND);
	_delay_ms(120);
	write_bus(0x29, COMMAND);
}
