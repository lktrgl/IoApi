#ifndef IOAPI_DEVICE_SYNC_H_INCLUDED
#define IOAPI_DEVICE_SYNC_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

typedef int16_t ( *device_read_t ) ( void* dest, uint16_t len );
typedef int16_t ( *device_write_t ) ( const void* src, uint16_t len );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_DEVICE_SYNC_H_INCLUDED */
