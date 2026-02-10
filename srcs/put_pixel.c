#include "tft_ili9486_at2560.h"

static uint8_t check_frame_no(uint16_t y) {
	for (uint8_t i = 1; i <= 4; ++i) {
		if (y < ROWMEM * i) {
			return i;
		}
	}
	return 0;
}

// frame size: 120*320px
// 120 rows
// 320 columns -> 40bytes*8bits
int put_pixel(image_t *img, int16_t x, int16_t y, uint16_t rgb) {
	if (x >= COLSIZE || y >= ROWSIZE) {
		return 0;
	}

	uint8_t frame_no = check_frame_no(y);
	if (img->frame_no && frame_no != img->frame_no) {
		load_image(img);
		initialize_image(img);
	}
	img->frame_no = frame_no;
	img->storage[y % ROWMEM][x / 8] |= 1 << (x % 8);
	img->x_range[0] = x < img->x_range[0] ? x : img->x_range[0];
	img->x_range[1] = x > img->x_range[1] ? x : img->x_range[1];

	img->y_range[0] = y < img->y_range[0] ? y : img->y_range[0];
	img->y_range[1] = y > img->y_range[1] ? y : img->y_range[1];

	img->color = rgb;

	return 1;
}
