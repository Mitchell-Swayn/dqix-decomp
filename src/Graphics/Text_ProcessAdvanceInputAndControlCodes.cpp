#include <globaldefs.h>
ARM
struct GameState;
struct Links;
struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned _ZNK9GameState12GetTickCountEv(GameState*);
extern "C" int Object_TestNewlySetHalfwordMask(unsigned short*,unsigned);
extern "C" void* Object_GetGlobalThirtyTwoEntryContainer();
extern "C" unsigned* GetBoundedSlotUnlessFlag8000(unsigned**,unsigned);
extern "C" void WriteFirstAvailableVerticalCoordinate(Links*,unsigned);
extern "C" void Reset128EntriesAndFlagArrays(char*);
extern "C" void ResetEmbeddedOwnerAndAssignTwoBufferPointers(unsigned char*);
extern "C" void ClearAndStageSharedGraphicsBuffers(char*);
extern "C" int ClassifyValidatedFF20ThroughFF25Code(void*,const void*);
extern "C" bool IsCopiedHalfwordHighByteFF(int,void*);
extern "C" void ProcessAndClearPendingFlagWhenBothBytesSet(unsigned char*);
extern "C" void DispatchStoredHalfwordIndexWithTwoArguments(char*,int,void*);
extern "C" unsigned short ReadCurrentIndexedHalfwordFromStoredArray(unsigned char*);
extern "C" void Object_ClearTransitionFlagWhenVerticalDataMatches(void*,int);
extern "C" void Text_ProcessBufferedHalfwordCodesAndResetCounters(Object*);
extern "C" void AdvanceTextCursorAndResetRenderBuffers(Object*);
extern "C" void SetFieldDAFlag2UnlessByteD4EqualsThree(unsigned char*);
extern "C" unsigned short data_02114e30[];
extern "C" unsigned char data_02114e54[];
extern "C" char data_02108760[];
// Original: arm9/main @ 0x020440CC; symbol: func_020440cc; size: 0x354.
extern "C" int Text_ProcessAdvanceInputAndControlCodes(unsigned char* self) {
if(!*(int*)(self+0x998)) return 1;
if(!self[0x19c1] && self[0x19c0]) return 0;
unsigned short mask=0x403;
bool advance=false;
if(self[0x19bf]) mask|=0x200;
if(self[0x19cf]) mask|=0x100;
if(Object_TestNewlySetHalfwordMask(data_02114e30,mask)) advance=true;
if(Object_TestNewlySetHalfwordMask(data_02114e30,0xf0)) advance=true;
if(data_02114e54[0x54] && *(unsigned*)(data_02114e54+0x44)<20) advance=true;
if(ReadCurrentIndexedHalfwordFromStoredArray(self)==0xff0c) {
unsigned ticks=_ZNK9GameState12GetTickCountEv((GameState*)_ZN9GameState11GetInstanceEv());
unsigned value=self[0x1961];
if(value) {
if(value<=ticks) {self[0x1961]=0;advance=true;}
else self[0x1961]=value-ticks;
}
}
if(!advance) return 0;
switch(*(unsigned*)(self+0x9a0)) {
case 0:
if(self[0x19be]) return 0;
if(ReadCurrentIndexedHalfwordFromStoredArray(self)==0xff02) {
unsigned* slot=GetBoundedSlotUnlessFlag8000((unsigned**)Object_GetGlobalThirtyTwoEntryContainer(),*(unsigned*)(self+0x1838));
if(slot) WriteFirstAvailableVerticalCoordinate((Links*)slot,*(unsigned*)(self+0x183c));
}
return 1;
case 1:
self[0x19ae]=0;self[0x19af]=0;self[0x19cd]=1;
*(unsigned*)(self+0x40)=0;*(unsigned*)(self+0x44)=0;self[0x912]=0;
Text_ProcessBufferedHalfwordCodesAndResetCounters((Object*)self);
*(unsigned*)(self+0x9a0)=5;
AdvanceTextCursorAndResetRenderBuffers((Object*)self);
if(!self[0x19d3]) DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
break;
case 3:self[0x19bd]=0;break;
case 2:
if(ReadCurrentIndexedHalfwordFromStoredArray(self)==0xff1f) {
unsigned short code;
while(*(unsigned*)(self+0x78)<*(unsigned*)(self+0x6c)) {
code=(*(unsigned short**)(self+0x4c))[*(unsigned*)(self+0x78)];
if(IsCopiedHalfwordHighByteFF((int)self,&code)) {
int n=ClassifyValidatedFF20ThroughFF25Code(self,&code);
if(n) {*(unsigned*)(self+0x78)=*(unsigned*)(self+0x78)+n+1;continue;}
if(code==0xff01 || code==0xff03) break;
if(code==0xff2c) {
*(unsigned*)(self+0x1844)=*(unsigned*)(self+0x183c);
self[0x19b6]=1;
Object_ClearTransitionFlagWhenVerticalDataMatches(self,1);
} else if(code==0xff12) {
unsigned char* object=*(unsigned char**)(self+0x8c);
if(object) SetFieldDAFlag2UnlessByteD4EqualsThree(object);
}
}
(*(unsigned*)(self+0x78))++;
}
ProcessAndClearPendingFlagWhenBothBytesSet(self);
*(unsigned*)(self+0x9a0)=0;
Reset128EntriesAndFlagArrays((char*)self);
ClearAndStageSharedGraphicsBuffers((char*)self);
ResetEmbeddedOwnerAndAssignTwoBufferPointers(self);
} else {
if(!self[0x19d3]) DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,1,0);
*(unsigned*)(self+0x9a0)=5;
(*(unsigned*)(self+0x78))++;
self[0x912]=0;
}
break;
}
return 0;
}
