#include "syscaller.h"


typedef uint64_t (*func_type)();

func_type fList[NFUNCTIONS] = {write, read, getHour, getMin, getSec, beep, timeElapsed,
                               sleep, userDrawPixel, getResolutions, changeFontColour,
                               printImage, newCharInBuffer, exit, userRequestNewWindow,
                               putChar, removeChar, changeBackgroundColour};

uint64_t syscaller(uint64_t rax, uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8){//pa dsps si es que quiero color, guia 3
    //aca tenemos que poner las funciones de lectura/impresion char etc
    uint64_t (*function)(uint64_t , uint64_t , uint64_t , uint64_t , uint64_t );
    function = fList[rax-1]; //<------- pedro soluciona esto
    return function(rdi,rsi,rdx,rcx,r8);
}

uint64_t write(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    drawString((const char *) rdi);
    return 0;
}
uint64_t read(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    return (uint64_t) returnNextChar();
}
uint64_t getHour(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    return getTimeHour();
}
uint64_t getMin(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    return getTimeMin();
}
uint64_t getSec(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    return getTimeSec();
}
uint64_t beep(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    motherBeep();
    return 0;
}
uint64_t timeElapsed(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    return (uint64_t) secondsElapsed();
}
uint64_t sleep(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    kernelSleep((unsigned int) rdi);
    return 0;
}
uint64_t userDrawPixel(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    Colour colour = {(uint8_t) rdx, (uint8_t) rcx, (uint8_t) r8};
    drawAPixelWithColour((int) rdi, (int) rsi, colour);
    return 0;
}
uint64_t getResolutions(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    *((int*)rdi) = getXResolution();
    *((int*)rsi) = getYResolution();
    return 0;
}
uint64_t changeFontColour(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    Colour col = {(uint8_t)rdi,(uint8_t)rsi,(uint8_t)rdx};
    setFontColour(col);
    return 0;
}
uint64_t printImage(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    drawImage((unsigned int) rdi, (unsigned int) rsi, (const unsigned short *)rdx, (unsigned int) rcx, (unsigned int) r8);
    return 0;
}
uint64_t newCharInBuffer(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    return (uint64_t) newToRead();
}
uint64_t exit(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    //hace algo antes de morir
    motherBeep();
    return 0;
}
uint64_t userRequestNewWindow(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    newWindow();
    return 0;
}
uint64_t putChar(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    drawChar((char) rdi);
    return rdi;
}
uint64_t removeChar(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    backSpace();
    return 0;
}
uint64_t changeBackgroundColour(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8)
{
    Colour colour = {rdi,rsi,rdx};
    setBackgroundColour(colour);
    return 0;
}
