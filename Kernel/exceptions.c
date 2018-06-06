#include "videoDriver.h"
#include "exceptions.h"
#include "keyboardDriver.h"

extern uint64_t rip;
extern uint64_t stack;
extern void _hlt();

#define REGS 15

static char* registers[REGS] = {" rax: "," rbx: "," rcx: ", " rdx: "," rbp: "," rdi: "," rsi: ",
" r8: ", " r9: ", " r10: "," r11: ", " r12: "," r13: "," r14: "," r15: "};


void exceptionDispatcher(uint64_t exception, uint64_t * rsp)
{
	if (exception == ZERO_EXCEPTION_ID)
	{
		zeroDivision();
	}
	if (exception == INVALID_OPCODE_ID)
	{
		invalidOpcode();
	}
		printRegisters(rsp);
		for (int i = 0; i < 30; i++) {
			kernelSleep();
		}

}

static void zeroDivision()
{
		newWindow();
		drawString("\n Cannot divide by 0\n");
}

static void invalidOpcode()
{
		newWindow();
		drawString("\n No such function\n");
}

void printRegisters(uint64_t * stack)
{
	int j = 0;
	for (int i = 14; i>= 0; i--, j++)
	{
		drawChar('\n');
		drawString(registers[i]);
		drawHexa(stack[j]);
	}
	drawChar('\n');
	drawString(" rip: ");
	drawHexa(stack[j]);
}
