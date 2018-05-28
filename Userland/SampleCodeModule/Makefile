include ../Makefile.inc

MODULE=../0000-sampleCodeModule.bin
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
SOURCES_ASM=$(wildcard *.asm)
OBJECTS_ASM=$(SOURCES_ASM:.asm=.o)

all: $(MODULE)

$(MODULE): $(OBJECTS) $(OBJECTS_ASM)
	$(LD) $(LDFLAGS) -T sampleCodeModule.ld -o $(MODULE) $(OBJECTS) $(OBJECTS_ASM)

%.o: %.c
	$(GCC) $(GCCFLAGS) -c $< -o $@

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm -rf *.o

.PHONY: all clean print
