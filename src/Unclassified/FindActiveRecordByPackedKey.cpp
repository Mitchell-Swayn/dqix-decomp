#include <globaldefs.h>
ARM
extern "C" int AreBothWordFieldsD4And9CNonzero(void*);extern "C" int Graphics_GetShiftedCharacterAddress(void*);
// Original: arm9/main @ 0x02081E18; symbol: func_02081e18; size: 0x8C.
extern "C" int FindActiveRecordByPackedKey(unsigned char* object,unsigned key){if(!*(unsigned*)(object+0x2c)||!*(unsigned*)(object+0x30))return 0;unsigned char* record;for(int i=object[0x39]-1;i>=0;i--){record=*(unsigned char**)(object+0x30)+i*0xe0;if(AreBothWordFieldsD4And9CNonzero(record) && *(unsigned*)(record+4)){unsigned char* data=*(unsigned char**)(record+4);if(key==(((unsigned)data[0x1c]<<24)>>28))return *(int*)(record+0xa0)+*(int*)(record+0xa4);}}return Graphics_GetShiftedCharacterAddress(*(void**)(*(unsigned char**)(object+0x30)+4));}
