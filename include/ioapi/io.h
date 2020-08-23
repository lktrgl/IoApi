#ifndef IOAPI_IO_H_INCLUDED
#define IOAPI_IO_H_INCLUDED

#include <stdint.h>

/*---------------------------------------------------------------------------*/

int8_t open ( uint8_t id );
int16_t read ( int8_t desc, void* dest, uint16_t len );
int16_t write ( int8_t desc, const void* src, uint16_t len );
int16_t ioctl ( int8_t desc, uint16_t operation, void* ptr );
void close ( int8_t desc );

/*---------------------------------------------------------------------------*/

#endif /* IOAPI_IO_H_INCLUDED */
