#ifndef IOAPI_IO_CTL_H_INCLUDED
#define IOAPI_IO_CTL_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

int16_t io_ioctl ( int8_t desc, uint16_t operation, void* ptr );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_IO_CTL_H_INCLUDED */
