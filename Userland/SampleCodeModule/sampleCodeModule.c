/* sampleCodeModule.c */
#include <stdint.h>

char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;

extern int syscall(uint64_t rdi, uint64_t rsi);

int main() {
	//All the following code may be removed
    char *sentence = "Hellooooooooooooo ieieeiie";
    //syscall(1,(uint64_t)sentence);


	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;

	return 0xDEADBEEF;
}
