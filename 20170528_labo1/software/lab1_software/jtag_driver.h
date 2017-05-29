/*
 * jtag_driver.h
 *
 *  Created on: 2017-05-26
 *      Author: ak82770
 */

#ifndef JTAG_DRIVER_H_
#define JTAG_DRIVER_H_

/* Exemple d'envoi de chaine de characteres a travers le JTAG UART */
#define JUART_DATA_REG_OFT   0			//offset du data register
#define JUART_CTRL_REG_OFT   1			//offset du control register
#define JUART_WSPACE_MASK    0xffff0000
#define JUART_WSPACE_BIT_OFT 16			//bit offset du champ wspace
#define JUART_CHAR_MASK		 0x000000ff

/* verifier l'espace disponible dans le tampon FIFO ecriture */
#define juart_read_wspace(base) \
	((IORD(base, JUART_CTRL_REG_OFT) & JUART_WSPACE_MASK) >> JUART_WSPACE_BIT_OFT)

/* ecriture un charactere 8 bits */
#define juart_write_char(base, data) \
	IOWR(base, JUART_DATA_REG_OFT, data & JUART_CHAR_MASK)

/* routine pour l'envoi d'une chaine de characteres. methode "busy-waiting" */
void juart_write_string(alt_u32 jtag_base, char *message)
{
	// message est une cstr (chaine de charactere terminee par NUL)
	alt_u32 data32;

	while(*message != '\0') {
		data32 = (alt_u32) *message;
		if(juart_read_wspace(jtag_base) != 0) {
			juart_write_char(jtag_base, data32);
		}
			message++; // ERREUR CORRIGEE ;)
	}
}


#endif /* JTAG_DRIVER_H_ */
