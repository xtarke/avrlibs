/*
 * i2c.h
 *
 *  Created on: Nov 4, 2016
 *      Author: xtarke
 */

#ifndef I2C_H_
#define I2C_H_

void i2c_init();
uint8_t i2c_read(uint8_t addr, uint8_t i2c_addr);
void i2c_write(uint8_t addr, uint8_t data, uint8_t i2c_addr);



#endif /* I2C_H_ */
