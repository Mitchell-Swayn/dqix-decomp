#include <globaldefs.h>
struct Object {char pad[12];unsigned* values;};extern "C" Object* WorldScriptArray_FindEntryByKey(void*,unsigned);
// Original: arm9/main @ 0x0208DA18; symbol: func_0208da18; size: 0xAC.
extern "C" unsigned Object_ReadOneOfEightSelectedRecordValues(void* self,unsigned id,unsigned selector) {unsigned result=0;Object* object=WorldScriptArray_FindEntryByKey(self,id);if(object)switch(selector) {case 0:break;case 1:result=object->values[0];break;case 2:result=object->values[1];break;case 3:result=object->values[2];break;case 4:result=object->values[3];break;case 5:result=object->values[4];break;case 6:result=object->values[5];break;case 7:result=object->values[6];break;case 8:result=object->values[7];break;}return result;}
