/* 
 *
 * This program executes every 500ms in a loop. Every loop it checks if push
 * button KEY[0] on DE10-Lite board is pressed. When button pressed the program goes
 * in a infinite loop "CPU stuck".  If watchdog key is enabled the system will reset
 * by its self within max 1 second. If watchdog not enabled then the user must reset
 * the system via key SW9.
 * 
 *
 * The purpose of this example is to demonstrate how watchdog functionality is
 * important to keep track of system availability. Using the Nios II HAL library we can
 * control LEDs, check if button is pressed and write to registers.

 */


#include "sys/alt_stdio.h"
#include <altera_avalon_timer_regs.h>
#include <alt_types.h>
#include <system.h>
#include "is_key_pressed.h"



int main()
{
	alt_u8 counter = 0;
	alt_putstr("Start!\n");


  TIMER_RESET;
  TIMER_START;

   /* Event loop never exits. */
  while (1){
	  TIMER_RESET;
	  TIMER_START;

	  //starts every 500ms
	  while(TIMER_READ <= 25000000){

		  if(is_key0_pressed()){
			 IOWR_8DIRECT(LED_DIODS_BASE,0,255);
			 IOWR_8DIRECT(KICKER_OUTPUT_BASE,0,0);
			 while(1);
		  }

		  //write high signal to kicker heartbeat
		  //count up seven segment
	  }

	  if(counter == 99){
		  counter = 0;
	  }
	  else{
	  counter += 1;
	  }
	  IOWR_8DIRECT(SEVEN_SEGMENT_LEDS_BASE,0,counter);
	  IOWR_8DIRECT(KICKER_OUTPUT_BASE,0,1);

  }

  return 0;
}
