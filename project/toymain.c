#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <shape.h>
#include <abCircle.h>
#include "buzzer.h"
#include "switches.h"
#include "led.h"
#include "stateMachines.h"


int redrawScreen = 1; /* Checks whether screen needs to be redrawn */

/* Draw a square */
void drawFigure(u_char col, u_char row, u_int color)
{
  int i, j;
  for (i = 1; i <= col; i++)
      for (j = 1; j <= row; j++)
	drawPixel(6, 15, COLOR_RED);
}

int main()
{ 
  configureClocks();
  lcd_init();

  enableWDTInterrupts();      /* enable periodic interrupt */
  

  or_sr(0x08);              /* GIE (enable interrupts) */
  //clearScreen(COLOR_WHITE);
}

void wdt_c_handler()
{
  static short count = 0;
  count++;
}
