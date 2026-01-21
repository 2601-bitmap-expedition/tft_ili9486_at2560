#ifndef TFT_ILI9486_AT2560_H
# define TFT_ILI9486_AT2560_H

# include <inttypes.h>
//# include <avr/io.h>
# include <util/delay.h>
# include "io_at2560.h"

# define LCD_RD	D54
# define LCD_WR	D55
# define LCD_RS	D56
# define LCD_CS	D57
# define LCD_RST	D58
# define SD_SCK	D13
# define SD_DO	D12
# define SD_DI	D11
# define SD_CS	D10
# define LCD_D1	D9
# define LCD_DC	D8
# define LCD_D7	D7
# define LCD_D6	D6
# define LCD_D5	D5
# define LCD_D4	D4
# define LCD_D3	D3
# define LCD_D2	D2

# define COMMAND LOW
# define INDEX HIGH

void write_bus(uint8_t cmd, uint8_t dcx);
void initialize_tft(void);
int put_pixel(uint16_t x, uint16_t y);

#endif
