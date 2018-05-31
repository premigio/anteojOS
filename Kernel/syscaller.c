#include <stdint.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#include <timeDriver.h>
#include <beepDriver.h>


#define NFUNCTIONS 7 // <-------------- jojojojojojojoo

uint64_t write(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
uint64_t read(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
uint64_t getHour(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
uint64_t getMin(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
uint64_t getSec(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
uint64_t beep(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
uint64_t timeElapsed(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

typedef uint64_t (*func_type)();


func_type fList[NFUNCTIONS] = {write, read, getHour, getMin, getSec, beep, timeElapsed/* drawAPixel, Systime*/};

uint64_t syscaller(uint64_t rax, uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8){//pa dsps si es que quiero color, guia 3
  //aca tenemos que poner las funciones de lectura/impresion char etc
  uint64_t (*function)(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
  function = fList[rax-1];
  return function(rdi,rsi,rdx,rcx,r8);
}

uint64_t write(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
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
  return 0;
}
uint64_t read(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
  return getChar();
}
uint64_t getHour(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8){
  return getTimeHour();
}
uint64_t getMin(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8){
  return getTimeMin();
}
uint64_t getSec(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8){
  return getTimeSec();
}
uint64_t beep(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8){
  motherBeep();
  return 0;
}
uint64_t timeElapsed(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8){
    return secondsElapsed();
}

