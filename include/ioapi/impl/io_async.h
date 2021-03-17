#ifndef IOAPI_IO_ASYNC_H_INCLUDED
#define IOAPI_IO_ASYNC_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef IOAPI_ASYNC
  #include <ioapi/impl/device_async.h>
#endif

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

int16_t io_read_async ( int8_t desc, device_io_result_t* result );
int16_t io_write_async ( int8_t desc, device_io_result_t* result );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_IO_ASYNC_H_INCLUDED */
