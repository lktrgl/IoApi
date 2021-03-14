#include <ioapi/io.h>

#include <ioapi/device.h>

/*---------------------------------------------------------------------------*/

#ifdef IOAPI_CHECKED_BUILD
static uint8_t s_descriptor_opened[IOAPI_DEVICE_COUNT_MAX] = {0};
#endif /* IOAPI_CHECKED_BUILD */

/*---------------------------------------------------------------------------*/

int8_t io_open ( const char* device_name )
{
  const device_id_t id = device_get_id ( device_name );

#ifdef IOAPI_CHECKED_BUILD

  if ( id == DEVICE_ERROR )
  {
    return DEVICE_ERROR;
  }

  if ( id >= IOAPI_DEVICE_COUNT_MAX )
  {
    return DEVICE_ERROR;
  }

  if ( s_descriptor_opened[id] )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  const device_descriptor_t* device = device_get_descriptor ( id );

#ifdef IOAPI_CHECKED_BUILD

  if ( device && device->open )
#endif /* IOAPI_CHECKED_BUILD */
  {
    /* open the device */
    if ( DEVICE_OK == device->open ( device_name ) )
    {
#ifdef IOAPI_CHECKED_BUILD
      s_descriptor_opened[id] = 0xFF;
#endif /* IOAPI_CHECKED_BUILD */

      return id;
    }
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

int16_t io_read ( int8_t desc, void* dest, uint16_t len )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( desc < 0 || desc >= IOAPI_DEVICE_COUNT_MAX )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  const device_descriptor_t* device = device_get_descriptor ( desc );

#ifdef IOAPI_CHECKED_BUILD

  if ( device && device->read )
#endif /* IOAPI_CHECKED_BUILD */
  {
    return device->read ( dest, len );
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

int16_t io_write ( int8_t desc, const void* src, uint16_t len )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( desc < 0 || desc >= IOAPI_DEVICE_COUNT_MAX )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  const device_descriptor_t* device = device_get_descriptor ( desc );

#ifdef IOAPI_CHECKED_BUILD

  if ( device && device->write )
#endif /* IOAPI_CHECKED_BUILD */
  {
    return device->write ( src, len );
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

int16_t io_ioctl ( int8_t desc, uint16_t operation, void* ptr )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( desc < 0 || desc >= IOAPI_DEVICE_COUNT_MAX )
  {
    return DEVICE_ERROR;
  }

#endif /* IOAPI_CHECKED_BUILD */

  const device_descriptor_t* device = device_get_descriptor ( desc );

#ifdef IOAPI_CHECKED_BUILD

  if ( device && device->ioctl )
#endif /* IOAPI_CHECKED_BUILD */
  {
    return device->ioctl ( operation, ptr );
  }

  return DEVICE_ERROR;
}

/*---------------------------------------------------------------------------*/

void io_close ( int8_t desc )
{
#ifdef IOAPI_CHECKED_BUILD

  if ( desc >= IOAPI_DEVICE_COUNT_MAX )
  {
    return;
  }

  if ( !s_descriptor_opened[desc] )
  {
    return;
  }

#endif /* IOAPI_CHECKED_BUILD */

  const device_descriptor_t* device = device_get_descriptor ( desc );

#ifdef IOAPI_CHECKED_BUILD

  if ( device && device->close )
#endif /* IOAPI_CHECKED_BUILD */
  {
    /* close the device */
    device->close ( desc );

#ifdef IOAPI_CHECKED_BUILD
    s_descriptor_opened[desc] = 0;
#endif /* IOAPI_CHECKED_BUILD */
  }
}


