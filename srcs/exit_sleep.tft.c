#include "tft_ili9486_at2560.h"

void exit_sleep_tft(void) {
	write_bus(0x11, COMMAND);
	_delay_ms(120);
	write_bus(0x29, COMMAND);
}
