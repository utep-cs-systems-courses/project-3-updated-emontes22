#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include <p2switches.h>
#include <shape.h>
#include <abCircle.h>
#include "buzzer.h"

#define GREEN_LED BIT6

int main()
{
  P1DIR |= GREEN_LED; /* green led on when CPU on */
  P1OUT |= GREEN_LED;
  
  configureClocks();
  lcd_init();

  //for(int rc = 1; rc <= 10; rc++)
    drawPixel(5, 10, COLOR_WHITE);

}
