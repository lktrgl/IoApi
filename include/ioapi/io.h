#ifndef IOAPI_IO_H_INCLUDED
#define IOAPI_IO_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

int8_t io_open ( const char* device_name );
int16_t io_read ( int8_t desc, void* dest, uint16_t len );
int16_t io_write ( int8_t desc, const void* src, uint16_t len );
int16_t io_ioctl ( int8_t desc, uint16_t operation, void* ptr );
void io_close ( int8_t desc );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_IO_H_INCLUDED */
