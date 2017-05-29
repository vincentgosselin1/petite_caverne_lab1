/*
 * interval_timer_driver.h
 *
 *  Created on: 2017-05-26
 *      Author: ak82770
 */

#ifndef INTERVAL_TIMER_DRIVER_H_
#define INTERVAL_TIMER_DRIVER_H_

#define TIMER_STAT_REG_OFT    0 //registre de statut
#define TIMER_CTRL_REG_OFT    1 //Registre de controle
#define TIMER_PERIODL_REG_OFT 2 //registre de periode, bits 15:0
#define TIMER_PERIODH_REG_OFT 3 //registre de periode, bits 31:16

/* Acces de base */
/* Le champ to du registre de status est mis a 1 lorsque le compteur atteint 0
 * et demeure a 1 jusqu'a ce que le processur ecrive un 0 sur ce champ.
 * il est possible de l'utiliser comme un tick que l'on verifiera periodiquement.
 * les macros suivantes servent a verifier et reinitialiser le champ to */

#define timer_read_tick(base) IORD(base, TIMER_STAT_REG_OFT) & 0X01)
// ^ buggais donc j'ai fait des fonctions customs...

#define timer_clear_tick(base) IOWR(base, TIMER_STAT_REG_OFT, 0)
// ^ buggais donc j'ai fait des fonctions customs...

/* routine de configuration */
/* cette fonction programme la periode et lance le compteur */
void timer_write_period(alt_u32 timer_base, alt_u32 period)
{
	alt_u16 high, low;

	/* separer la periode 32bits en 2 valeurs de 16 bits */
	high = (alt_u16) (period >> 16);
	low = (alt_u16) (period & 0x0000FFFF);

	/*ecrire la periode */
	IOWR(timer_base, TIMER_PERIODH_REG_OFT, high);
	IOWR(timer_base, TIMER_PERIODL_REG_OFT, low);

	/* configuration du timer pour demarrage, SANS le mode continu, SANS interrupt */
	IOWR(timer_base, TIMER_CTRL_REG_OFT, 0x0004); //bit 2 active seulement
	// code a l'air d'etre correct afterall?
}

alt_u32 ms_to_nb_of_steps(int period_in_ms){
	//Formulae is Period(in Milli seconds) = X * 20us
	//We want to find X.

	return (period_in_ms*1000000/20);//Pour division complete sans reste.
}

// read_timer fct. Return 1 if timer is done, 0 if running.
alt_u32 timer_is_done(alt_u32 timer_base){
	alt_u32 timer_done = IORD(timer_base, TIMER_STAT_REG_OFT);
	if(timer_done == 1)
	{
		return 1;
	} else {
		return 0;
	}
}

void restart_timer(alt_u32 timer_base){
	//reset 1sec timer
	IOWR(TIMER_0_BASE, TIMER_STAT_REG_OFT, 0);
	//start timer again
	IOWR(TIMER_0_BASE, TIMER_CTRL_REG_OFT, 4);
}

#endif /* INTERVAL_TIMER_DRIVER_H_ */
