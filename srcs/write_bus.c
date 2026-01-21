#include "tft_ili9486_at2560.h"

void write_bus(uint8_t cmd, uint8_t dcx) {
	pin_mode(LCD_CS, OUTPUT);
	digital_write(LCD_CS, LOW);
	pin_mode(LCD_RS, OUTPUT);
	digital_write(LCD_RS, dcx); // dcs- command: low, index: high
	pin_mode(LCD_RD, OUTPUT);
	digital_write(LCD_RD, HIGH); // read inactivate
	// D0=0
	// 이따 포트에 바로 쏘는 함수 만들자.
	for (int d = D0; d <= D7; ++d) {
		pin_mode(d, OUTPUT);
		digital_write(d, (cmd >> d) & 1);
	}
	pin_mode(LCD_WR, OUTPUT);
	digital_write(LCD_WR, LOW);
	_delay_ms(1);
	digital_write(LCD_WR, HIGH);
}
