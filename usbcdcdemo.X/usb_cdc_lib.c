#include "usb_cdc_lib.h"

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <conio.h>

#include "usb_device.h"

void initUSBLib()
{
    // Enable global and peripheral interrupts.
    INTCONbits.GIE = 1;
    INTCONbits.PEIE = 1;
    
    USBDeviceInit();
    USBDeviceAttach();
}

inline void processUSBTasks()
{
    if(INTCONbits.PEIE == 1)
    {       
        if(PIE2bits.USBIE == 1 && PIR2bits.USBIF == 1)
        {
            USB_USBDeviceTasks();
        } 
    }
}

unsigned char isUSBReady()
{
    return ((USBGetDeviceState() < CONFIGURED_STATE) || (USBIsDeviceSuspended() == true)) ? 0x00 : 0xFF;        
}