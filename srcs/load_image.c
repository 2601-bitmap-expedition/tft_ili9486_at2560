#include "tft_ili9486_at2560.h"

int load_image(image_t *img) {
	uint16_t sx = img->x_range[0], ex = img->x_range[1];
	uint16_t sy = img->y_range[0], ey = img->y_range[1];
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
	write_bus(0x2C, COMMAND);
	for (uint16_t y = sy; y <= ey; ++y) {
		for (uint16_t x = sx; x <= ex; ++x) {
			if ((img->storage[y % ROWMEM][x / 8] >> (x % 8)) & 1) {
				uint16_t rgb = img->color;
				write_bus((rgb & 0xFF00) >> 8, INDEX);
				write_bus(rgb & 0x00FF, INDEX);
			}
			else {
				write_bus(0x00, INDEX);
				write_bus(0x00, INDEX);
			}
		}
	}

	return 1;
}
