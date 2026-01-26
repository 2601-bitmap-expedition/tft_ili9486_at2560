#include "tft_ili9486_at2560.h"

void write_bus(uint8_t cmd, uint8_t dcx) {
	digital_write(LCD_CS, LOW);
	digital_write(LCD_RS, dcx); // dcs- command: low, index: high
	digital_write(LCD_RD, HIGH); // read inactivate
	/*
	 * D8 D9 D2 D3 D4 D5 D6 D7
	 * H5 H6 E4 E5 G5 E3 H3 H4
	 *
	 * PORTE: 0011 1000, D2 << 2, D3 << 2, D5 >> 2
	 * PORTG: 0010 0000, D4 << 1
	 * PORTH: 0111 1000, D8 << 5, D9 << 5, D6 >> 3, D7 >> 3
	 */
	uint8_t converted_cmd = ((cmd & 0x0C) << 2) | ((cmd & 0x20) >> 2);
	port_write(E, 0x38, converted_cmd);

	converted_cmd = (cmd & 0x10) << 1;
	port_write(G, 0x20, converted_cmd);

	converted_cmd = ((cmd & 0x11) << 5) | ((cmd & 0xC0) >> 3);
	port_write(H, 0x78, converted_cmd);

	digital_write(LCD_WR, LOW);
	digital_write(LCD_WR, HIGH);
	digital_write(LCD_CS, HIGH);
}
