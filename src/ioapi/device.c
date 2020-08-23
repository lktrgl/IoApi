#include <ioapi/device.h>

#include <ioapi/impl/io_cfg.h>

#include <stddef.h>

/*---------------------------------------------------------------------------*/

static const device_descriptor_t* s_device_registry[IOAPI_DEVICE_MAX_COUNT] = {};
static uint8_t s_device_index[IOAPI_DEVICE_MAX_COUNT] = {};

/*---------------------------------------------------------------------------*/

int8_t device_register ( const device_descriptor_t* device )
{
  uint8_t i;
#ifdef IOAPI_CHECKED_BUILD

  if ( !device || device->id > IOAPI_DEVICE_MAX_COUNT )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  for ( i = 0; i < IOAPI_DEVICE_MAX_COUNT; ++i )
  {
    if ( s_device_registry[i] )
    {
      continue;
    }

    s_device_registry[i] = device;
    s_device_index[device->id] = i;

    return i;
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

int8_t device_init_all ()
{
  int8_t result = DEVICE_OK;
  uint8_t i;

  for ( i = 0; i < IOAPI_DEVICE_MAX_COUNT; ++i )
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

const device_descriptor_t* device_get_descriptor ( const device_id_t id )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( id > IOAPI_DEVICE_MAX_COUNT )
  {
    return NULL;
  }

#endif /* IOAPI_CHECKED_BUILD */

  return s_device_registry[s_device_index[id]];
}

/*---------------------------------------------------------------------------*/
