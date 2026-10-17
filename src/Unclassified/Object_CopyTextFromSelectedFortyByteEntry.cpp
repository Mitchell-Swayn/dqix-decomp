#include <globaldefs.h>
ARM
extern unsigned char* data_02105244;extern "C" void Text_MapInputBytesToVariableLengthOutputSequences(void*,unsigned,int);
// Original: arm9/main @ 0x0203C248; symbol: func_0203c248; size: 0x3C.
extern "C" void Object_CopyTextFromSelectedFortyByteEntry(unsigned char* object,unsigned value){if(!data_02105244)return;unsigned char* base=data_02105244+4;short index=*(short*)(object+20);if(index<0)return;Text_MapInputBytesToVariableLengthOutputSequences(base+index*0x28,value,0);}
