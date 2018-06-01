#ifndef SCLIB_H
#define SCLIB_H


    void write(char * string);
    char read();
    unsigned int getHour();
    unsigned int  getMinute();
    unsigned int  getSecond();
    void beep();
    void timeElapsed();
    void sleep(unsigned int rdi);
    void userDrawPixel(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);
    void getResolutions(unsigned int * rdi, unsigned int * rsi);
    void setFontColour(uint8_t R, uint8_t G, uint8_t B);
    void printImage(unsigned int rdi, unsigned int rsi, const unsigned short *rdx, unsigned int rcx, unsigned int r8);



#endif
