#include "tft_ili9486_at2560.h"

int put_pixel(uint16_t sx, uint16_t ex, uint16_t sy, uint16_t ey, uint16_t rgb) {
	if (sx > ex || ex >= 320 || sy > ey || ey >= 480) {
		return 0;
	}

	// Column
	write_bus(0x2A, COMMAND);
	write_bus((sx & 0xFF00) >> 8, INDEX);
	write_bus(sx & 0x00FF, INDEX);
	write_bus((ex & 0xFF00) >> 8, INDEX);
	write_bus(ex & 0x00FF, INDEX);

	// Page
	write_bus(0x2B, COMMAND);
	write_bus((sy & 0xFF00) >> 8, INDEX);
	write_bus(sy & 0x00FF, INDEX);
	write_bus((ey & 0xFF00) >> 8, INDEX);
	write_bus(ey & 0x00FF, INDEX);

	// Memory Write
	// 11 1111 0000 0000 0000
	write_bus(0x2C, COMMAND);
	for (uint16_t y = sy; y <= ey; ++y) {
		for (uint16_t x = sx; x <= ex; ++x) {
			write_bus((rgb & 0xFF00) >> 8, INDEX);
			write_bus(rgb & 0x00FF, INDEX);
		}
	}

	return 1;
}
