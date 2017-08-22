CC=gcc
CFLAGS = -lm
b_conv_interface: b_conv_interface.c base_convert basic.h
	$(CC) b_conv_interface.c -o  b_conv_interface

base_convert: base_convert.c basic.h dec2base.h base2dec.h baseOp.h
	$(CC) base_convert.c -o base_convert -lm
