

void printinScreen(char * txt, char * v){
	int i = 0;
	int j = 0;
	char *sentence = txt;

	while(*(sentence + j) != '\0'){
		*(v+i++) = *(sentence + j++);
		*(v+i++) = 0x0A;
	}
}
