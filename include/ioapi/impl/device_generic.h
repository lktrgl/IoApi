#ifndef IOAPI_DEVICE_GENERIC_H_INCLUDED
#define IOAPI_DEVICE_GENERIC_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

typedef int8_t ( *device_init_t ) ();
typedef int8_t ( *device_open_t ) ( const char* device_name );
typedef void ( *device_close_t ) ( int8_t id );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_DEVICE_GENERIC_H_INCLUDED */
