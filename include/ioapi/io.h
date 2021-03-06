#ifndef IOAPI_IO_H_INCLUDED
#define IOAPI_IO_H_INCLUDED

#include <stdint.h>

#include <ioapi/impl/io_cfg.h>

/*---------------------------------------------------------------------------*/

#include <ioapi/impl/io_generic.h>

/*---------------------------------------------------------------------------*/

#ifdef IOAPI_SYNC
  #include <ioapi/impl/io_sync.h>
#endif

/*---------------------------------------------------------------------------*/

#ifdef IOAPI_ASYNC
  #include <ioapi/impl/io_async.h>
#endif

/*---------------------------------------------------------------------------*/

#ifdef IOAPI_CTL
  #include <ioapi/impl/io_ctl.h>
#endif

/* ------------------------------------------------------------------------- */

#endif /* IOAPI_IO_H_INCLUDED */
