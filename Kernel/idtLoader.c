#include <idtLoader.h>

#pragma pack(push)		/* Push de la alineación actual */
#pragma pack (1) 		/* Alinear las siguiente estructuras a 1 byte */

/* Descriptor de interrupcion */
typedef struct {
  uint16_t offsetL, selector;
  uint8_t cero, access;
  uint16_t offsetM;
  uint32_t offsetH, otherCero;
} descrInt;

#pragma pack(pop)		/* Reestablece la alinceación actual */

descrInt * idt = (descrInt *) 0;	// IDT de 255 entradas

static void setupIDTEntry (int index, uint64_t offset);

void loadIDT()
{
    _cli();                                                 // el flag de INTR = 0 --> no le llegan interrupciones

    setupIDTEntry (0x00, (uint64_t)&_exception0Handler);    //hasta 20h excepciones
    setupIDTEntry (0x06, (uint64_t)&_exception6Handler);    //Invalid Opcode
    setupIDTEntry (0x20, (uint64_t)&_irq00Handler);
    setupIDTEntry (0x21, (uint64_t)&_irq01Handler);
    setupIDTEntry (0x80, (uint64_t)&sysCallHandler);

	 picMasterMask(0xFC);
	 picSlaveMask(0xFF);

	 _sti();                                                 // el flag de INTR = 1 --> vuelve al estado anterior
}

static void setupIDTEntry (int index, uint64_t offset)      // setea el formato de la IDT
{
  idt[index].selector = 0x08;
  idt[index].offsetL = offset & 0xFFFF;
  idt[index].offsetM = (offset >> 16) & 0xFFFF;
  idt[index].offsetH = (offset >> 32) & 0xFFFFFFFF;
  idt[index].access = ACS_INT;
  idt[index].cero = 0;
  idt[index].otherCero = (uint64_t) 0;
}
