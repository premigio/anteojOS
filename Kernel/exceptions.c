#include "videoDriver.h"
#include "exceptions.h"

#define REGS 16

static char* registers[REGS] = {" rax: "," rbx: "," rcx: ", " rdx: "," rbp: "," rdi: "," rsi: ",
" r8: ", " r9: ", " r10: "," r11: ", " r12: "," r13: "," r14: "," r15: "," rip: "};

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
}

static void zeroDivision()
{
	drawString("Cannot divide by 0\n");
}

static void invalidOpcode()
{
	drawString("No such function\n");
}

void printRegisters(uint64_t * rsp)
{
	for (int i = 0; i < REGS; i++)
	{
		if (i % 8 == 0)
		{
			drawChar('\n');
		}
		drawString(registers[i]);
		drawHexa(rsp[i]);
	}
}
