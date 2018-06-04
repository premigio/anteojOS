#include "SevenSegNumFontPlus.h"

const unsigned short * charMap(int c)
{
	return SevenSegNumFont + CHAR_HEIGHT * 4 * c;
}
