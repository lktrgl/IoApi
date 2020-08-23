#include <ioapi/io.h>

#include <ioapi/impl/io_cfg.h>

#include <ioapi/device.h>

/*---------------------------------------------------------------------------*/

static device_id_t s_device_descriptor[IOAPI_DESCRIPTOR_MAX_COUNT] = {};

/*---------------------------------------------------------------------------*/

int8_t open ( const uint8_t id )
{
  /* whether the device has been opened */
  int8_t i;

  for ( i = 0; i < IOAPI_DESCRIPTOR_MAX_COUNT; ++i )
  {
    if ( id == s_device_descriptor[i] )
    {
      return i;
    }
  }

  /* it is not opened yet but whether the device has been registered */
  const device_descriptor_t* device = device_get_descriptor ( id );

#ifdef IOAPI_CHECKED_BUILD

  if ( device )
#endif /* IOAPI_CHECKED_BUILD */
  {
    for ( i = 0; i < IOAPI_DESCRIPTOR_MAX_COUNT; ++i )
    {
      /* found a free cell */
      if ( !s_device_descriptor[i] )
      {
        /* open the device */
        if ( DEVICE_OK == device->open ( id ) )
        {
          /* store the device id */
          s_device_descriptor[i] = id;
          return i;
        }
      }
    }
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

int16_t read ( int8_t desc, void* dest, uint16_t len )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( desc >= IOAPI_DESCRIPTOR_MAX_COUNT )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  const device_descriptor_t* device = device_get_descriptor ( s_device_descriptor[desc] );

#ifdef IOAPI_CHECKED_BUILD

  if ( device )
#endif /* IOAPI_CHECKED_BUILD */
  {
    return device->read ( dest, len );
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

int16_t write ( int8_t desc, const void* src, uint16_t len )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( desc >= IOAPI_DESCRIPTOR_MAX_COUNT )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  const device_descriptor_t* device = device_get_descriptor ( s_device_descriptor[desc] );

#ifdef IOAPI_CHECKED_BUILD

  if ( device )
#endif /* IOAPI_CHECKED_BUILD */
  {
    return device->write ( src, len );
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

int16_t ioctl ( int8_t desc, uint16_t operation, void* ptr )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( desc >= IOAPI_DESCRIPTOR_MAX_COUNT )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  const device_descriptor_t* device = device_get_descriptor ( s_device_descriptor[desc] );

#ifdef IOAPI_CHECKED_BUILD

  if ( device )
#endif /* IOAPI_CHECKED_BUILD */
  {
    return device->ioctl ( operation, ptr );
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

void close ( int8_t desc )
{
  /* whether the device has been opened */
  if ( !s_device_descriptor[desc] )
  {
    return;
  }

  /* it is not closed yet but whether the device has been registered */
  const device_id_t id = s_device_descriptor[desc];
  const device_descriptor_t* device = device_get_descriptor ( id );

#ifdef IOAPI_CHECKED_BUILD

  if ( device )
#endif /* IOAPI_CHECKED_BUILD */
  {
    device->close ( id );
    s_device_descriptor[desc] = 0;
  }
}


