#include "BL.h"

void GoToBootLoader(void)
{
  //Initializing the arguments for HAL functions
  FLASH_AdvOBProgramInitTypeDef OBbank1;
  OBbank1.BootConfig = OB_BOOT_BANK1;
  OBbank1.OptionType = OPTIONBYTE_BOOTCONFIG;  
  
  // Write to EEPROM that BootLoader should be executed 
  HAL_FLASHEx_DATAEEPROM_Unlock();
  HAL_FLASHEx_DATAEEPROM_Program(FLASH_TYPEPROGRAMDATA_WORD, 
                                 EEPROM_Address_Mode_Of_Execution, 
                                 ShouldExecuteBootLoader);
  
  //Change to (or stay at) bank1 and reset the device
  HAL_FLASH_OB_Unlock();  
  HAL_FLASHEx_AdvOBProgram(&OBbank1);         
  HAL_FLASH_Unlock();
  HAL_FLASH_OB_Launch();  
}




