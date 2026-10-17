#include <globaldefs.h>
ARM
struct State;struct T;
struct FontNibble { unsigned char font:4; unsigned char other:4; };
extern "C" void* func_ov011_021849c8(State*);
extern "C" void* func_ov023_021f6880(void*,unsigned);
extern "C" unsigned OV023_ReadHalfwordField04(void*);
extern "C" void* OV023_GetEmbeddedField20(void*);
extern "C" unsigned FindRecordValueByKeyOrZero(T*,int);
extern "C" int TestValueEqualsTwelve(int);
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
// Original: arm9/ov004 @ 0x0216AF24; symbol: func_ov004_0216af24; size: 0x8C.
extern "C" int Graphics_GetRecordTextWidth(State* self,unsigned index) {
void* owner=func_ov011_021849c8(self);
unsigned char* rec=(unsigned char*)func_ov023_021f6880(owner,index);
if(!rec) return 0;
const char* text=*(const char**)(rec+0x20);
if(!text) {
void* parent=func_ov023_021f6880(owner,*(unsigned short*)(rec+0x36));
if(OV023_ReadHalfwordField04(parent)==4) {
T* table=(T*)OV023_GetEmbeddedField20(parent);
text=(const char*)FindRecordValueByKeyOrZero(table,*(short*)(rec+0x38));
}
}
int width=0;
if(text) width=TextLayout_ComputeWidthWithGlyphSpacing(text,TestValueEqualsTwelve(((FontNibble*)(rec+0x44))->font));
return width;
}
