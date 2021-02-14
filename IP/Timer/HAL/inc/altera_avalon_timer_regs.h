/*
 * altera_avalon_timer_regs.h
 *
 *  Created on: Nov 4, 2019
 *  Author: Saif Saadaldin
 *
 *  Dokumentation av funktioner:
 *
 *  1- TIMER_STOP:
 *  	Deklaration: TIMER_STOP;
 *  	Argument: Inga;
 *  	Returnerad värde: Inga;
 *  	Exemple:se koden nedan;
 *
 *  2- TIMER_RESET:
 *  	Deklaration: TIMER_RESET;
 *  	Argument: Inga;
 *  	Returnerad värde: Inga;
 *  	Exemple:se koden nedan;
 *
 *  3- TIMER_START:
 *  	Deklaration: TIMER_START;
 *  	Argument: Inga;
 *  	Returnerad värde: Inga;
 *  	Exemple:se koden nedan;
 *
 *  4- TIMER_READ:
 *  	Deklaration: TIMER_READ;
 *  	Argument: Inga;
 *  	Returnerad värde: Inga;
 *  	Exemple:se koden nedan;
 *
 *
 *  	Exemple kod för funktioner ovan: koden nedan är en while loop som fungerar som en timer. Den räknar
 *  	antal sekunder och minuter. Se hur funktionerna ovan används i koden.
 *
#include "sys/alt_stdio.h"
#include <altera_avalon_timer_regs.h>
#include <stdio.h>

int main()
{
	int seconds = 0, minutss = 0;
	while(1)
	{
		while(TIMER_READ < 50000000){}//wait one second
		TIMER_RESET;
		TIMER_START;

		seconds++;
		if(seconds<=59){
			printf("Second = %d", seconds);
			printf("\n");
			}
		else{
			minutss++;
			seconds = 0;
			printf("Minutes = %d", minutss);
			printf("\n");
		}
	}
}
 */

#ifndef ALTERA_AVALON_TIMER_REGS_H_
#define ALTERA_AVALON_TIMER_REGS_H_

#include <io.h>
#include <system.h>

//siffran 4 efter base betyder att vi ändra i ofset 4, byte nr 4
#define TIMER_STOP 	IOWR_32DIRECT(TIMER_HW_IP_0_BASE,4,0X00000000) //skriver till control register

//nedan skickas B"0100 0000 0000 0000 0000 0000 0000 0000" till control register
#define TIMER_RESET	IOWR_32DIRECT(TIMER_HW_IP_0_BASE,4,0X40000000)

//nedan skickar B"1000 0000 0000 0000 0000 0000 0000 0000" till control register
#define TIMER_START	IOWR_32DIRECT(TIMER_HW_IP_0_BASE,4,0X80000000)

#define TIMER_READ IORD_32DIRECT(TIMER_HW_IP_0_BASE,0)//läser från data register

#endif /* ALTERA_AVALON_TIMER_REGS_H_ */
