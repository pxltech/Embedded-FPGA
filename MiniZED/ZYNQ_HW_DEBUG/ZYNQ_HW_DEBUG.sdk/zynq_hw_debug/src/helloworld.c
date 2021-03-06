/* Developed by Vincent Claes
 * 12/12/2018
 *
 * vincent[at]cteq.eu
 *
 */

#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "xparameters.h"
#include "xgpio.h"
#include "sleep.h"

#define GPIO_CHANNEL 1

XGpio Gpio;

int main()
{
	int Status;

	init_platform();

	Status = XGpio_Initialize(&Gpio,XPAR_AXI_GPIO_0_DEVICE_ID);
	XGpio_SetDataDirection(&Gpio,GPIO_CHANNEL,~0b1111); // We used 4 bits as GPIO output Width

    xil_printf("Application by Vincent Claes\n\r");
    int value = 0b0001;
    while(1){
    	for(int i=0;i<4;i++){
    		if(value == 0b1000)
    			value = 0b0001;
    		else
    			value= value << 1;

    		XGpio_DiscreteWrite(&Gpio,GPIO_CHANNEL,value);
    		usleep_A9(100);
    	}

    }


    cleanup_platform();
    return 0;
}
