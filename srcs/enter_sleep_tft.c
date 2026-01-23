#include "tft_ili9486_at2560.h"

void enter_sleep_tft(void) {
	write_bus(0x28, COMMAND);
	_delay_ms(10);
	write_bus(0x10, COMMAND);
	_delay_ms(120);
}
