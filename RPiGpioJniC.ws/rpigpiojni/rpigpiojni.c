/*
 * rpigpiojni.c
 *
 *  Created on: May 8, 2020
 *      Author: don
 */

#include "rpigpiojni.h"
#include "c_gpio.h"

// #define TEST_ONLY

JNIEXPORT jint JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_setup
  (JNIEnv * e, jobject o) {
	jint ret = 0;
#ifndef TEST_ONLY
	ret = setup();
#endif
	return ret;
}

JNIEXPORT void JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_setup_1gpio
  (JNIEnv * e, jobject o, jint pt, jint dir, jint pu) {
#ifndef TEST_ONLY
	setup_gpio(pt, dir, pu);
#endif
}

JNIEXPORT jint JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_gpio_1function
  (JNIEnv * e, jobject o, jint i) {
	jint ret = 0;
#ifndef TEST_ONLY
	ret = gpio_function(i);
#endif
	return ret;
}

JNIEXPORT void JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_output_1gpio
  (JNIEnv * e, jobject o, jint pt, jint val) {
#ifndef TEST_ONLY
	output_gpio(pt, val);
#endif
}

JNIEXPORT jint JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_input_1gpio
  (JNIEnv * e, jobject o, jint pt) {
	jint ret = 0;
#ifndef TEST_ONLY
	ret = input_gpio(pt);
#endif
	return ret;
}

JNIEXPORT void JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_set_1rising_1event
  (JNIEnv * e, jobject o, jint i, jint j){
#ifndef TEST_ONLY
	set_rising_event(i, j);
#endif
}

JNIEXPORT void JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_set_1falling_1event
  (JNIEnv * e, jobject o, jint i, jint j) {
#ifndef TEST_ONLY
	set_falling_event(i, j);
#endif
}

JNIEXPORT void JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_set_1high_1event
  (JNIEnv * e, jobject o, jint i , jint j) {
#ifndef TEST_ONLY
	set_high_event(i, j);
#endif
}

JNIEXPORT void JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_set_1low_1event
  (JNIEnv * e, jobject o, jint i, jint j) {
#ifndef TEST_ONLY
	set_low_event(i, j);
#endif
}

JNIEXPORT jint JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_eventdetected
  (JNIEnv * e, jobject o, jint i) {
	jint ret = 0;
#ifndef TEST_ONLY
	eventdetected(i);
#endif
	return ret;
}

JNIEXPORT void JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_cleanup
  (JNIEnv * e, jobject o) {
#ifndef TEST_ONLY
	cleanup();
#endif
}

JNIEXPORT jint JNICALL Java_com_stokesautomation_gpio_rpi_RPiGpio_getVersion
  (JNIEnv * e, jobject o) {
	return com_stokesautomation_gpio_rpi_RPiGpio_VERSION;
}
