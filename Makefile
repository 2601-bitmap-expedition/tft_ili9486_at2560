NAME=libtft9486.a

SRCS_DIR=srcs
INC_DIR=includes
OBJS_DIR=.objs

SRCS=$(wildcard $(SRCS_DIR)/*.c)
OBJS=$(subst $(SRCS_DIR),$(OBJS_DIR),$(SRCS:.c=.o))

CC=avr-gcc
CFLAGS=-mmcu=atmega2560 -DF_CPU=16000000UL -std=gnu11 -Wall -Os -I$(INC_DIR)

AR=avr-ar
ARFLAGS=rcs

RM=rm
RMFLAGS=-rf

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(RMFLAGS) $(NAME) $(OBJS_DIR)

re:
	make clean && make all

.PHONY: all clean re
