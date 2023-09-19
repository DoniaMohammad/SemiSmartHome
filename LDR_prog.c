#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "ADC_interface.h"
#include "LDR_cfg.h"
#include "LDR_interface.h"


uint8 LDR_u8GetLightLevel(uint16 copy_u8ChannelReading)
{
	uint8 Local_u8LightLevel;

	Local_u8LightLevel = (uint8)(((uint32)copy_u8ChannelReading*(uint32) 5000u)/(uint32)256u);

	return Local_u8LightLevel;
}
