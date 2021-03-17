#ifndef IOAPI_DEVICE_ASYNC_H_INCLUDED
#define IOAPI_DEVICE_ASYNC_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------------------------------------------------------------*/

typedef enum device_io_operation_enum_tag
{
  DEVICE_OPERATION_READ,
  DEVICE_OPERATION_WRITE,
  DEVICE_OPERATION_IOCTL,
} device_io_operation_t;

/*---------------------------------------------------------------------------*/

typedef enum device_io_status_enum_tag
{
  DEVICE_STATUS_NONE,
  DEVICE_STATUS_PENDING,
  DEVICE_STATUS_DONE,
  DEVICE_STATUS_FAIL,
} device_io_status_t;

/*---------------------------------------------------------------------------*/

typedef struct device_io_result_tag
{
  device_io_operation_t operation;
  device_io_status_t status;
  uint32_t data_len;
  void* data_src;
  void* data_dest;
} device_io_result_t;

/*---------------------------------------------------------------------------*/

typedef void ( *device_callback_io_complete_t ) ( device_io_operation_t io_operation, device_io_result_t* result );

/*---------------------------------------------------------------------------*/

#ifdef __cplusplus
} /* extern "C" */
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_DEVICE_ASYNC_H_INCLUDED */
