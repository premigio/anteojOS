#include "videoDriver.h"
#include "exceptions.h"
#include "keyboardDriver.h"

extern void _hlt();

#define REGS 16

static char* registers[REGS] = {" r15: "," r14: "," r13: ", " r12: "," r11: "," r10: "," r9: ",
" r8: ", " rsi: ", " rdi: "," rbp: ", " rdx: "," rcx: "," rbx: "," rax: "," rip: "};


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
		for (int i = 0; i < 50; i++) {
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

void printRegisters(uint64_t * rsp)
{
	for (int i = 0; i < REGS; i++)
	{
		drawChar('\n');
		drawString(registers[REGS-1-i]);
		drawHexa(rsp[REGS-i]);
	}
}
