#include <keyboardDriver.h>
#include <videoDriver.h>

#define BUFFERSIZE 1024
#define TRUE  1;
#define FALSE 0;

char keyboardList[128] = {0,27,'1','2','3','4','5','6','7','8','9','0','-','=','\b','\t','q','w','e','r','t','y','u','i',
                          'o','p','[',']','\n',0,'a','s','d','f','g','h','j','k','l',';','\'','`',0,'\\', 'z','x','c','v','b',
                          'n','m',',','.','/',0, '*', 0, ' ', 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'-',0,0,0,
                          '+',0,0,0,0,0,0,0,0,0,0,0};     //hecho con la pagina de osdev

char keyboardShiftList[128]={0,27,'!','@','#','$','%','^','&','*','(',')','_','+','\b','\t','q','w','e','r','t','y','u','i','o','p','{','}','\n',0,'a','s','d','f','g','h','j','k','l',':','\"','~',0,'|', 'z','x','c','v','b','n','m','<','>','?',0, '*', 0, ' ', 0, 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'-',0,0,0,'+',0,0,0,0,0,0,0,0,0,0,0};

int capslock = 0;
int shift = 0;

char buffer[BUFFERSIZE] = {0}; // hay que crear el buffer
int bfw = 0; // posicion de escritura, para los putchar
int bfr = 0; // posicion de lectura, para los getchar

int size = 0;

void keyboardInterpreter()
{
    unsigned char key = (unsigned char) getKey();
    if (key & 0x80)                         //suelto
    {
        if(key == 0xAA || key == 0xB6)
            shift = 0;
    }
    else                                    //apretado
    {
        if (key == 58)
        {
            capslock = !capslock;
        }
        if(key == 0x2A || key == 0x36)
        {
            shift = 1;
        }
        char c = keyboardList[key];
        if (c>='a' && c <= 'z')
        {
            if ( (capslock && !shift) || (!capslock && shift) )
            {
                c = c - ('a'-'A');
            }
        }
        else if(shift)
        {
            c = keyboardShiftList[key];
        }
        charToBuffer(c);
    }
}

void charToBuffer(unsigned char c)
{
    if (c != 0){
        buffer[bfw] = c;
        bfw++;
        bfw = bfw % BUFFERSIZE;                 // bfw = BUFFERWRITE
        size++;
    }
}

char returnNextChar()
{
    char res = 0;
    if(size == 0){
        return res;
    }
    res = buffer[bfr++];
    bfr = bfr % BUFFERSIZE;                   // bfr = BUFFERREAD
    size--;
    return res;
}

int newToRead(){
    if (size == 0 || bfr == bfw){
        return 0;
    }
    return 1;
}
