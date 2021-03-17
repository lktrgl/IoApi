#ifndef IOAPI_DEVICE_H_INCLUDED
#define IOAPI_DEVICE_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#include <ioapi/impl/device_generic.h>

/*---------------------------------------------------------------------------*/

#ifdef IOAPI_SYNC
  #include <ioapi/impl/device_sync.h>
#endif

/*---------------------------------------------------------------------------*/

#ifdef IOAPI_CTL
  #include <ioapi/impl/device_ctl.h>
#endif

/*---------------------------------------------------------------------------*/

#ifdef IOAPI_EVENT
  #include <ioapi/impl/device_event.h>
#endif

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

enum device_codes_enum
{
  DEVICE_ERROR = -1,
  DEVICE_OK = 1
};

/*---------------------------------------------------------------------------*/

typedef int8_t device_id_t;

/*---------------------------------------------------------------------------*/

typedef struct device_descriptor_tag
{
  const char* device_name;
  device_init_t init;
  device_open_t open;
  device_close_t close;

#ifdef IOAPI_SYNC
  device_read_t read;
  device_write_t write;
#endif

#ifdef IOAPI_CTL
  device_ioctl_t ioctl;
#endif

#ifdef IOAPI_ASYNC
  device_callback_io_complete_t io_complete;
#endif

#ifdef IOAPI_EVENT
  device_callback_event_t event;
#endif

} device_descriptor_t;

/*---------------------------------------------------------------------------*/

int8_t device_register ( const device_descriptor_t** device );

/*---------------------------------------------------------------------------*/

int8_t device_init_all ();

/*---------------------------------------------------------------------------*/

device_id_t device_get_id ( const char* device_name );

/*---------------------------------------------------------------------------*/

const device_descriptor_t* device_get_descriptor ( device_id_t id );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_DEVICE_H_INCLUDED */
