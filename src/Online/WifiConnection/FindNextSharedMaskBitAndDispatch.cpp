#include <globaldefs.h>
ARM
extern "C" {unsigned WM_GetAllowedChannel();void WirelessHost_StoreErrorUnlessTerminal(unsigned);void WirelessHost_SetSystemState(int);void WirelessHost_HandleChannelOccupancyMeasurement();unsigned WirelessHost_MeasureChannelWithFixedSurveyParameters(void(*)(),unsigned);}
// Original: arm9/ov031 @ 0x02239CD4; symbol: func_ov031_02239cd4; size: 0x9C.
extern "C" unsigned short FindNextSharedMaskBitAndDispatch(unsigned short index){
unsigned mask=WM_GetAllowedChannel();
if(mask==0x8000){WirelessHost_StoreErrorUnlessTerminal(3);WirelessHost_SetSystemState(9);return 3;}
if(mask==0){WirelessHost_StoreErrorUnlessTerminal(22);WirelessHost_SetSystemState(9);return 24;}
while(!(mask&(1<<(index-1)))){index++;if(index>16)return 24;}
return WirelessHost_MeasureChannelWithFixedSurveyParameters(WirelessHost_HandleChannelOccupancyMeasurement,index);
}
