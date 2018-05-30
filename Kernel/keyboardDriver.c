#include "keyboardDriver.h"
#include "videoDriver.h"
#define BUFFERSIZE 1024

char keyboardList[128] = {0,27,'1','2','3','4','5','6','7','8','9','0','-','=','\b','\t','q','w','e','r','t','y','u','i',
'o','p','[',']','\n',0,'a','s','d','f','g','h','j','k','l',';','\'','`',0,'\\', 'z','x','c','v','b',
'n','m',',','.','/',0, '*', 0, ' ', 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'-',0,0,0,
'+',0,0,0,0,0,0,0,0,0,0,0};//hecho con la pagina de osdev
char keyboardShiftList[128]={0,27,'!','@','#','$','%','^','&','*','(',')','_','+','\b','\t','q','w','e','r','t','y','u','i','o','p','{','}','\n',0,'a','s','d','f','g','h','j','k','l',':','\"','~',0,'|', 'z','x','c','v','b','n','m','<','>','?',0, '*', 0, ' ', 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'-',0,0,0,'+',0,0,0,0,0,0,0,0,0,0,0};

int capslock = 0;
int shift = 0;
int f1 = 0; //lo seteo como tecla que cambia el color del reloj. De aca deberia salir el beep


char buffer[BUFFERSIZE] = {0}; // hay que crear el buffer
int bfw = 0; // posicion de escritura, para los putchar
int bfr = 0; // posicion de lectura, para los getchar

int size = 0;


void keyboardInterpreter(){

    unsigned char key = getKey();
    if (key & 0x80){//suelto
      if(key == 0x2A || key == 0x36)
        shift = 0;
    }else{ // apretado
      if (key == 58){
          capslock = !capslock;
      }
      if(key == 0x2A || key == 0x36){
          shift = 1;
      }
      if (key == 1) {
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
      putChar(c);
    }
}

void putChar(char c){
  buffer[bfw] = c;
  Colour colour = {55,55,55};
  drawChar(c,(Colour)colour);
  bfw = ++bfw % BUFFERSIZE;
  size++;
}

void getChar(char * res) {
  if(size == 0)
    return 0;
  *res = buffer[bfr++];
  bfr = bfr % BUFFERSIZE;
  size--;
}
