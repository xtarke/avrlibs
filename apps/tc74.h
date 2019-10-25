/*
 * tc74.h
 *
 *  Created on: Mar 27, 2018
 *      Author: Renan Augusto Starke
 *      Instituto Federal de Santa Catarina
 *
 *      I2C Tiny Serial Digital Thermal Sensor
 *
 */

#ifndef APPS_TC74_H_
#define APPS_TC74_H_

#define TC74_I2C_ADDR 0b10010000

void tc74_init();
uint8_t perform_temp_measure();


#endif /* APPS_TC74_H_ */
