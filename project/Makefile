# makfile configuration

CPU             	= msp430g2553
CFLAGS          	= -mmcu=${CPU} -Os -I../h
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c

all: runToy.elf

runToy.elf: ${COMMON_OBJECTS} toymain.o buzzer.o led.o stateMachines.o switches.o p2_interrupt_handler.o 
	$(CC) $(CFLAGS) ${LDFLAGS} -o $@ $^ -lTimer -lp2sw -lLcd

load: runToy.elf
	msp430loader.sh runToy.elf

clean:
	rm -f *.o *.elf *~

buzzer.o: buzzer.h

stateMachines.o: buzzer.h stateMachines.h led.h

led.o: led.h led.c
