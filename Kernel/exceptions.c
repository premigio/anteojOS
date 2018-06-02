#include "videoDriver.h"
#include "exceptions.h"
#include "keyboardDriver.h"

#define REGS 16

static char* registers[REGS] = {" rax: "," rbx: "," rcx: ", " rdx: "," rbp: "," rdi: "," rsi: ",
" r8: ", " r9: ", " r10: "," r11: ", " r12: "," r13: "," r14: "," r15: "," rip: "};

void exceptionDispatcher(uint64_t exception, uint64_t * rsp)
{
	char c;
	if (exception == ZERO_EXCEPTION_ID)
	{
		zeroDivision();
	}
	if (exception == INVALID_OPCODE_ID)
	{
		invalidOpcode();
	}
	printRegisters(rsp);
	do // hago esto para que quede visible los registros, de ultima lo borro
	{
		keyboardInterpreter();
		c = returnNextChar();
	}
	while(c != '\n' || c == 0);
}

static void zeroDivision()
{
	drawString("\n Cannot divide by 0\n");
}

static void invalidOpcode()
{
	drawString("\n No such function\n");
}

void printRegisters(uint64_t * rsp)
{
	drawString(registers[REGS-1]);
	drawHexa(*(rsp-8));
	for (int i = 0; i < REGS-1; i++)
	{
		if (i % 8 == 0)
		{
			drawChar('\n');
		}
		drawString(registers[i]);
		drawHexa(rsp[i]);
	}
}
