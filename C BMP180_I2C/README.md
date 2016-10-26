Description: It is an assignment task given for implementing a simple I2C device driver in C for a Bosch environmental sensor BMP180 using the I2C interface.

Data sheet: https://ae-bst.resource.bosch.com/media/_tech/media/datasheets/BST-BMP180-DS000-121.pdf

A simple I2C interface is provided:

// I2C burst read (reads from 7 bit I2C device 'address' 'size' bytes starting with register 'reg' into data)

i2c_read(uint8_t address, uint8_t reg, uint8_t *data, size_t size);

// I2C burst write (writes to 7 but I2C device 'address' 'size' bytes, starting with register 'reg')

i2c_write(uint8_t address, uint8_t reg, uint8_t *data, size_t size);

*Write two interface functions that allow to (1) read temperature in degrees celsius (C) and (2) pressure in hecto-pascal (hPa) as a double.

*Read measured data as burst reads and convert to temperature and pressure.

