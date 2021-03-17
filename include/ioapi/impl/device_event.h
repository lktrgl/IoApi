#ifndef IOAPI_DEVICE_EVENT_H_INCLUDED
#define IOAPI_DEVICE_EVENT_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

typedef void ( *device_callback_event_t ) ( uint8_t io_event );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_DEVICE_EVENT_H_INCLUDED */
