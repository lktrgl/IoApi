#ifndef IOAPI_IO_GENERIC_H_INCLUDED
#define IOAPI_IO_GENERIC_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

int8_t io_open ( const char* device_name );
void io_close ( int8_t desc );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_IO_GENERIC_H_INCLUDED */
