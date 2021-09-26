#include "stm32l1xx_hal.h"
#include "stm32l1xx_hal_flash_ex.h"

#define ShouldExecuteBootLoader 		0xDEADBEEF
#define EEPROM_Address_Mode_Of_Execution	        0x08081FF0
/*
 STM32L15xxE device EEPROM Address space is:
Data EEPROM bank 1 0x0808 0000 - 0x0808 1FFF
Data EEPROM bank 2 0x0808 2000 - 0x0808 3FFF
*/

void GoToBootLoader(void);