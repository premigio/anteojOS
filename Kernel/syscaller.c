#include <stdint.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#define NFUNCTIONS 2

void write(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
void read(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

typedef void (*func_type)();


func_type fList[NFUNCTIONS] = {write, read,/* drawAPixel, Systime*/};

void syscaller(uint64_t rax, uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8){//pa dsps si es que quiero color, guia 3
//aca tenemos que poner las funciones de lectura/impresion char etc
  void (*function)(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
  function = fList[rax-1];
  function(rdi,rsi,rdx,rcx,r8);
}

void write(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
  const char * string = (const char *) rdi;
  if(rsi == 0 && rdx == 0 && rcx == 0)
  {
    drawString(string);
  }
  else
  {
    Colour colour = {(uint8_t)rdx,(uint8_t)rcx,(uint8_t)r8};
    drawStringWithColour(string,colour);
  }
}
void read(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
  char * c = (char*) rdi;
  getChar(c);
}
