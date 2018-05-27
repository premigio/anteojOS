/* sampleCodeModule.c */


char * v = (char*)0xB8000 + 79 * 2;

static int var1 = 0;
static int var2 = 0;


int main() {
	//All the following code may be removed
    int i = 0;
    int j = 0;
    char *sentence = "Hellooooooooooooo ieieeiie";
    
    while(*(sentence + j) != '\0'){
        *(v+i++) = *(sentence + j++);
        *(v+i++) = 0x0A;
    }
	//Test if BSS is properly set up
	if (var1 == 0 && var2 == 0)
		return 0xDEADC0DE;

	return 0xDEADBEEF;
}
