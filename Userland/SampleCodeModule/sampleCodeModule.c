#include <stdint.h>

char * v = (char*)0xB8000 + 80 * 2;

static int var1 = 0;
static int var2 = 0;


int main() {
	//All the following code may be removed
	// char* string = "Arquitectura de las Computadoras";
	// while ( string != '\0'){
	// 	v = string;
	// 	*(v+1) = 0x74;
	// 	string++;
	//

	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;

	return 0xDEADBEEF;
}
