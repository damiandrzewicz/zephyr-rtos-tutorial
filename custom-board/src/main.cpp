/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
//#include <zephyr/drivers/gpio.h>

// #define SLEEP_TIME_MS   1000

// #define MY_GPIOS_NODE DT_NODELABEL(green_led_2)

// static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(MY_GPIOS_NODE, gpios);

int main(void)
{
    // int ret;

	// if (!device_is_ready(led.port)) {
	// 	return 0;
	// }

	// ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_ACTIVE);
	// if (ret < 0) {
	// 	return 0;
	// }

    // while (1) {
	// 	ret = gpio_pin_toggle_dt(&led);
	// 	if (ret < 0) {
	// 		return 0;
	// 	}

	// 	k_msleep(SLEEP_TIME_MS);
	// }
}
