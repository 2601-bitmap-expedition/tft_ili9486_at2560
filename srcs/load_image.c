#include "tft_ili9486_at2560.h"

static void set_print_range(int16_t *x_range, int16_t *y_range) {
	int16_t sx = x_range[0], ex = x_range[1];
	int16_t sy = y_range[0], ey = y_range[1];

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
}

static void refresh_range(int16_t sx, int16_t sy, int16_t *x_range, int16_t *y_range) {
	x_range[0] = sx;
	y_range[0] = sy;
	set_print_range(x_range, y_range);
	write_bus(0x2C, COMMAND);
}

static void load_pixel(uint16_t rgb) {
	write_bus((rgb & 0xFF00) >> 8, INDEX);
	write_bus(rgb & 0x00FF, INDEX);
}

int load_image(image_t *img) {
	int16_t x_range[2] = { img->x_range[0], img->x_range[1] };
	int16_t y_range[2] = { img->x_range[0], img->y_range[1] };
	refresh_range(img->x_range[0], img->y_range[0], x_range, y_range);

	// Memory Write
	uint16_t rgb = img->color;
	int blank = 0;
	for (int16_t y = img->y_range[0]; y <= img->y_range[1]; ++y) {
		for (int16_t x = img->x_range[0]; x <= img->x_range[1]; ++x) {
			if ((img->storage[y % ROWMEM][x / 8] >> (x % 8)) & 1) {
				if (blank || x < x_range[0]) {
					blank = 0;
					refresh_range(x, y, x_range, y_range);
				}
				load_pixel(rgb);
			}
			else {
				if (!blank) {
					blank = 1;
				}
			}
		}
	}

	return 1;
}
