#ifndef IOAPI_DEVICE_CTL_H_INCLUDED
#define IOAPI_DEVICE_CTL_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

typedef int16_t ( *device_ioctl_t ) ( uint16_t operation, void* ptr );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_DEVICE_CTL_H_INCLUDED */
