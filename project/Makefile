# makfile configuration

CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: runToy.elf

runToy.elf: ${COMMON_OBJECTS} toymain.o
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lTimer -lp2sw -lLcd

load: runToy.elf
	msp430loader.sh runToy.elf

clean:
	rm -f *.o *.elf *~
