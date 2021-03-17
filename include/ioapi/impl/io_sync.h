#ifndef IOAPI_IO_SYNC_H_INCLUDED
#define IOAPI_IO_SYNC_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

int16_t io_read ( int8_t desc, void* dest, uint16_t len );
int16_t io_write ( int8_t desc, const void* src, uint16_t len );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_IO_SYNC_H_INCLUDED */
