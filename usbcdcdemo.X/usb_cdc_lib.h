#ifndef USBCDC_H
#define	USBCDC_H

// Suppress warning 520: function XXX is never called.
#pragma warning disable 520

// Suppress warning 759: expression generates no code.
#pragma warning disable 759

// Suppress advisory 1510: non-reentrant function XXX appears in multiple call graphs and has been duplicated by the compiler
#pragma warning disable 1510

#include "usb_device_cdc.h"

void initUSBLib(void);
unsigned char isUSBReady(void);

inline void processUSBTasks(void);

#endif	/* USBCDC_H */

