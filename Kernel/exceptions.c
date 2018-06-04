#include "videoDriver.h"
#include "exceptions.h"
#include "keyboardDriver.h"

#define REGS 16

static char* registers[REGS] = {" r15: "," r14: "," r13: ", " r12: "," r11: "," r10: "," r9: ",
" r8: ", " rsi: ", " rdi: "," rbp: ", " rdx: "," rcx: "," rbx: "," rax: "," rip: "};

int flagReg =1;
int flagExc = 1;

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
	if(flagReg)
	{
		flagReg = 0;
		printRegisters(rsp);
	}
}

static void zeroDivision()
{
	if (flagExc) {
		newWindow();
		drawString("\n Cannot divide by 0\n");
		flagExc = 0;
	}
}

static void invalidOpcode()
{
	if (flagExc)
	{
		newWindow();
		drawString("\n No such function\n");
		flagExc = 0;
	}
}

void printRegisters(uint64_t * rsp)
{
	for (int i = 0; i < REGS; i++)
	{
		drawChar('\n');
		drawString(registers[REGS-1-i]);
		drawHexa(rsp[REGS-1-i]);
	}
}
