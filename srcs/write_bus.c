#include "tft_ili9486_at2560.h"

void write_bus(uint8_t cmd, uint8_t dcx) {
	pin_mode(LCD_CS, OUTPUT);
	digital_write(LCD_CS, LOW);
	pin_mode(LCD_RS, OUTPUT);
	digital_write(LCD_RS, dcx); // dcs- command: low, index: high
	pin_mode(LCD_RD, OUTPUT);
	digital_write(LCD_RD, HIGH); // read inactivate
//	for (digital_pins_t d = D0; d <= D7; ++d) {
//		pin_mode(d, OUTPUT);
//		digital_write(d, (cmd >> d) & 1);
//	}
	ddr_write(E, 0x2f, cmd & 0x2f);
	port_write(E, 0x2f, cmd & 0x2f);
	ddr_write(G, 0x10, cmd & 0x10);
	port_write(G, 0x10, cmd & 0x10);
	ddr_write(H, 0xc0, cmd & 0xc0);
	port_write(H, 0xc0, cmd & 0xc0);
	pin_mode(LCD_WR, OUTPUT);
	digital_write(LCD_WR, LOW);
	_delay_ms(1);
	digital_write(LCD_WR, HIGH);
}
