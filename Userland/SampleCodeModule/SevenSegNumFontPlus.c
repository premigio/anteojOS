// SevenSegNumFontPlus.c
#include "SevenSegNumFontPlus.h"


const unsigned char * charMap(int c) {
	// 31 es el numero (segun codigo ascii) a partir del cual están las letras
	// en el arreglo __font_bitmap__
	return SevenSegNumFont + CHAR_HEIGHT *  * c;
}