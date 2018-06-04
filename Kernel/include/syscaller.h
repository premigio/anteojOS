#ifndef SYSCALLER_H
#define SYSCALLER_H

#include <stdint.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#include <timeDriver.h>
#include <beepDriver.h>
#include <videoDriver.h>
#include "sleep.h"

#define NFUNCTIONS 30                             // number of functions

/* eax = 1
** draws a string with a given string in rdi
*/
uint64_t write(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 2
** returns the next character to consume from the buffer
*/
uint64_t read(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 3
** return the hour
*/
uint64_t getHour(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 4
** return the minutes
*/
uint64_t getMin(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 5
** return the seconds
*/
uint64_t getSec(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 6
** makes a beep sound from the motherload
*/
uint64_t beep(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 7
** return the seconds elapsed
*/
uint64_t timeElapsed(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 8
** suspends the system for a determined time
*/
uint64_t sleep(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 9
** draws a pixel in coordinates rdi (x) and rsi (y) with a given colour (r=rdx g=rcx b=r8)
*/
uint64_t userDrawPixel(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 10
** returns the resolutions in given pointers (rdi for width resolution and rsi for height resolution)
*/
uint64_t getResolutions(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 11
** changes the font colour with a given colour (r=rdi g=rsi b=rdx)
*/
uint64_t changeFontColour(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 12
** draws an image from coordinates rdi(x) and rsi(y), using a given hexa map on rdx,
** and with a determined width on rcx and height on r8
*/
uint64_t printImage(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 13
** returns a boolean whether there is a new character to read or not
*/
uint64_t newCharInBuffer(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 14
** makes a beep sound and exits
*/
uint64_t exit(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 15
** return the seconds elapsed
*/
uint64_t userRequestNewWindow(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 16
** draws a newWindow
*/
uint64_t putChar(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 17
** makes a backSpace
*/
uint64_t removeChar(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

/* eax = 18
** sets a new background colour (r=rdi g=rsi b=rdx)
*/
uint64_t changeBackgroundColour(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8);

#endif
