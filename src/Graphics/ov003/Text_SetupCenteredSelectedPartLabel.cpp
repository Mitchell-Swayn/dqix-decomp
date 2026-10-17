#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" int TextLayout_ComputeWidthWithGlyphSpacing(const char*,int);
extern "C" void Object_SetSelectedPartLowTwoBitMode(char*,int,int);
extern "C" void Object_ReadSelectedPartXYHalfwords(char*,int,short*,short*);
extern "C" void WriteResolvedHalfwordPair6And8(char*,int,int,int);
extern "C" void SetKeyedRecordFlagMaskOne(unsigned char*,int);
extern "C" void Object_ApplyModeOneToSelectedPartGroup(unsigned char*,int);
extern "C" void WriteResolvedEntryByte13HighNibble(char*,int,unsigned);
extern "C" void SetKeyedRecordFirstWord(char*,int,int);
extern "C" void Object_SetSelectedPartInitialWord(char*,int,int);
extern "C" void* Object_ResolveSelectedPartMessageId(char*,int);
extern "C" void WriteResolvedEntryHalfword0E(char*,int,short);
extern "C" void* LookupGlobalResourceByKey(unsigned);
// Original: arm9/ov003 @ 0x02167E28; symbol: func_ov003_02167e28; size: 0x17C.
extern "C" void Text_SetupCenteredSelectedPartLabel(char* self,int text,int value,int label,unsigned char badge,int first,int second) {
 char* p=*(char**)(self+0x10);
 SetKeyedRecordFirstWord(p,3,(int)LookupGlobalResourceByKey(0x3f3));
 Object_SetSelectedPartLowTwoBitMode(p,3,1);
 SetKeyedRecordFirstWord(p,0,text);
 Object_SetSelectedPartLowTwoBitMode(p,0,1);
 WriteResolvedEntryHalfword0E(p,1,(short)value);
 Object_SetSelectedPartInitialWord(p,5,first);
 Object_SetSelectedPartInitialWord(p,6,second);
 WriteResolvedEntryHalfword0E(p,2,(short)(label+2));
 int width=TextLayout_ComputeWidthWithGlyphSpacing((const char*)Object_ResolveSelectedPartMessageId(p,2),0);
 short x,y;
 Object_ReadSelectedPartXYHalfwords(p,2,&x,&y);
 x=0x40;
 x-=(width>>1);
 WriteResolvedHalfwordPair6And8(p,2,x,y);
 SetKeyedRecordFlagMaskOne((unsigned char*)p,0x2c);
 if(!badge)return;
 Object_ApplyModeOneToSelectedPartGroup((unsigned char*)p,0x2c);
 WriteResolvedHalfwordPair6And8(p,0x2c,(short)(x+width+1),y);
 WriteResolvedEntryHalfword0E(p,0x2c,(short)(badge+0x1c));
 unsigned nibble=5;
 if(badge==10)nibble=13;
 WriteResolvedEntryByte13HighNibble(p,0x2c,nibble);
}
