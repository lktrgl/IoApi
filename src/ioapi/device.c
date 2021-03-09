#include <ioapi/device.h>

#include <ioapi/impl/io_cfg.h>

#include <stddef.h>
#include <string.h>

/*---------------------------------------------------------------------------*/

static const device_descriptor_t** s_device_registry = NULL;

/*---------------------------------------------------------------------------*/

static uint8_t s_device_count = 0;

/*---------------------------------------------------------------------------*/

int8_t device_register ( const device_descriptor_t** device )
{
  uint16_t i;
#ifdef IOAPI_CHECKED_BUILD

  if ( !device )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */
  s_device_registry = device;

  for ( i = 0; *device; ++i, ++device )
  {
    ++s_device_count;
  }

#ifdef IOAPI_CHECKED_BUILD

  if ( s_device_count > IOAPI_DEVICE_COUNT_MAX )
  {
    s_device_registry = NULL;
    s_device_count = 0;

    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  return DEVICE_OK;
}

/*---------------------------------------------------------------------------*/

int8_t device_init_all ()
{
  int8_t result = DEVICE_OK;
  uint8_t i;

#ifdef IOAPI_CHECKED_BUILD

  if ( !s_device_registry || !s_device_count )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  for ( i = 0; i < s_device_count; ++i )
  {
    const device_descriptor_t* device = s_device_registry[i];

    if ( device )
    {
      device_init_t init = device->init;

#ifdef IOAPI_CHECKED_BUILD

      if ( init )
#endif /* IOAPI_CHECKED_BUILD */
      {
        if (
          DEVICE_ERROR == init() )
        {
          result = DEVICE_ERROR;
        }
      }
    }
  }

  return result;
}

/*---------------------------------------------------------------------------*/

device_id_t device_get_id ( const char* device_name )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( !s_device_count )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  for ( uint8_t id = 0; id < s_device_count; ++id )
  {
    if ( !strcmp ( s_device_registry[id]->device_name, device_name ) )
    {
      return ( device_id_t ) id;
    }
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

const device_descriptor_t* device_get_descriptor ( const device_id_t id )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( !s_device_registry || !s_device_count )
  {
    return NULL;
  }

  if ( id == DEVICE_ERROR )
  {
    return NULL;
  }

  if ( ( uint8_t ) id >= s_device_count )
  {
    return NULL;
  }

#endif /* IOAPI_CHECKED_BUILD */

  return s_device_registry[id];
}

/*---------------------------------------------------------------------------*/
