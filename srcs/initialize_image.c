#include "tft_ili9486_at2560.h"

void initialize_image(image_t *img) {
	img->frame_no = 0;
	memset(img->storage, 0, sizeof(img->storage));
	img->x_range[0] = -1;
	img->y_range[0] = -1;
}
