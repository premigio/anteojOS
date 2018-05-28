#include "keyboardDriver.h"
#define BUFFERSIZE 1024

char keyboardList[128] = {0,27,'1','2','3','4','5','6','7','8','9','0','-','=','\b','\t','q','w','e','r','t','y','u','i','o','p','[',']','\n',0,'a','s','d','f','g','h','j','k','l',';','\'','`',0,'\\', 'z','x','c','v','b','n','m',',','.','/',0, '*', 0, ' ', 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'-',0,0,0,'+',0,0,0,0,0,0,0,0,0,0,0};//hecho con la pagina de osdev
char keyboardShiftList[128]={0,27,'!','@','#','$','%','^','&','*','(',')','_','+','\b','\t','q','w','e','r','t','y','u','i','o','p','{','}','\n',0,'a','s','d','f','g','h','j','k','l',':','\"','~',0,'|', 'z','x','c','v','b','n','m','<','>','?',0, '*', 0, ' ', 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'-',0,0,0,'+',0,0,0,0,0,0,0,0,0,0,0};

int capslock = 0;
int shift = 0;
int f1 = 0; //lo seteo como tecla que cambia el color del reloj. De aca deberia salir el beep


char buffer[BUFFERSIZE] = {0}; // hay que crear el buffer
int bfw = 0; // posicion de escritura, para los putchar
int bfr = 0; // posicion de lectura, para los getchar


void keyboardInterpreter(){

    unsigned char key = getkey();
    if (key == 58){
        capslock = !capslock;
    }
    if(key == 0x2A || key == 0x36){
        shift = !shift;
    }
    if (key == 171) {
        //llama lo que deberia llamar para cambiar el color del reloj y hacer el beep
//necesito crear el metodo        putchar('\a');
    }
    char c = keyboardList[key];
    if (c>='a' && c <= 'z') {
        if ((capslock && !shift)||(!capslock && shift)){
            c = c - ('a'-'A');
        }
    }else if(shift){
        c = keyboardShiftList[key];
    }
    putchar(c);
}

void putchar(char c){
  buffer[bfw] = c;
  bfw = ++bfw % BUFFERSIZE;
}

char getchar() {
  char res = buffer[bfr++];
  bfr = bfr % BUFFERSIZE;
  return res;
}
