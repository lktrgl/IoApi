#ifndef IOAPI_DEVICE_H_INCLUDED
#define IOAPI_DEVICE_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

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

enum device_io_operation_enum
{
  DEVICE_OPERATION_READ,
  DEVICE_OPERATION_WRITE,
  DEVICE_OPERATION_IOCTL,
};

typedef struct device_io_result_tag
{
  uint8_t status;
  uint32_t data_len;
  void* data_src;
  void* data_dest;
} device_io_result_t;

/*---------------------------------------------------------------------------*/

typedef int8_t ( *device_init_t ) ();
typedef int8_t ( *device_open_t ) ( const char* device_name );
typedef int16_t ( *device_read_t ) ( void* dest, uint16_t len );
typedef int16_t ( *device_write_t ) ( const void* src, uint16_t len );
typedef int16_t ( *device_ioctl_t ) ( uint16_t operation, void* ptr );
typedef void ( *device_close_t ) ( device_id_t id );

/*---------------------------------------------------------------------------*/

typedef void ( *device_callback_io_complete_t ) ( uint8_t io_operation, device_io_result_t* ptr );
typedef void ( *device_callback_event_t ) ( uint8_t io_event );

/*---------------------------------------------------------------------------*/

typedef struct device_descriptor_tag
{
  const char* device_name;
  device_init_t init;
  device_open_t open;
  device_read_t read;
  device_write_t write;
  device_ioctl_t ioctl;
  device_close_t close;

#ifdef IOAPI_CALLBACK_IO_COMPLETE
  device_callback_io_complete_t io_complete;
#endif
#ifdef IOAPI_CALLBACK_IO_EVENT
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
