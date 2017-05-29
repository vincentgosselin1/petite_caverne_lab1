/*
 * led_driver.h
 *
 *  Created on: 2017-05-25
 *      Author: ak82770
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

void get_switches(alt_u32 sw_base, int *period)
{
	*period = IORD(sw_base, 0) & 0x000003FF;
}

void led_flash(alt_u32 led_base, int period)
{
	static alt_u8 led_pattern = 0x01;

	alt_u32 i, itr;

	led_pattern ^= 0x03;
	IOWR(led_base, 0, led_pattern);
	itr = period * 2000;
	for(i = 0; i < itr; i++)
	{
		;;
	}
}

void all_leds_off(void){
	IOWR(LEDS_BASE, 0, 0x00);//Leds Off when writing 0.
}


void inverting_leds (alt_u32 led_base){
	static alt_u8 led_pattern = 0x01;//original pattern. Since its static, this line is executed only once.
	led_pattern ^= 0x03;
	IOWR(led_base, 0, led_pattern);
}

#endif /* LED_DRIVER_H_ */
