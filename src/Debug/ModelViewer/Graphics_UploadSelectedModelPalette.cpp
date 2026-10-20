#include <globaldefs.h>
#include "System/LoadToVRAM.h"
#include "World/Zone3DEmbeddedState.h"
ARM
struct Record;
extern "C" {
void* ZoneState2754_FindPrimaryRecordByKey(ZoneState2754*,int);
ARM unsigned ZoneSerializedRecord_GetSelectedPaletteParameter(Record*,int,int);
void* _ZN7Model3D7GetTEX0Ev(void*);
void* CharacterPalette_GetGlobalConfiguration();
void _Z28LockStagedTextureVRAMCopyingv();void _Z30UnlockStagedTextureVRAMCopyingv();
void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);void _Z15CleanCacheRangePKvj(const void*,unsigned);
void CharacterPalette_ReplaceModelPaletteSliceFromConfiguration(void*,unsigned,unsigned,unsigned);
}
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define W(p,o) (*(unsigned*)((p)+(o)))
// Original: arm9/ov015 @ 0x0218C3A4; symbol: func_ov015_0218c3a4; size: 0x194.
// Selects a serialized palette field and uploads the chosen global palette range or dispatches the model palette helper.
extern "C" void Graphics_UploadSelectedModelPalette(unsigned char* self,int index) {
 Record* record=(Record*)ZoneState2754_FindPrimaryRecordByKey((ZoneState2754*)(P(self,0)+0x4c),(short)W(P(self,0x20),index*4));
 if(!record || !W((unsigned char*)record,0))return;
 unsigned char* state=P(P(self,4),0)+index*0x70;
 if(self[0x1c]==1) {
 unsigned selected=ZoneSerializedRecord_GetSelectedPaletteParameter(record,0,self[0x3b]);
 if(!selected)return;
 unsigned count=selected*2;
 unsigned char* tex=(unsigned char*)_ZN7Model3D7GetTEX0Ev(P(P(self,0x24)+index*0xac,8));
 if(!tex)return;
 unsigned short aligned=*(unsigned short*)(tex+0x30)*8;
 aligned=(aligned+31)&~31;
 int adjustment=48;
 int reserve=32;if(index==0)reserve=512;
 adjustment-=aligned-reserve;
 unsigned char* global=(unsigned char*)CharacterPalette_GetGlobalConfiguration();
 unsigned char* source=0;
 unsigned length=count*2;
 switch(count) {
 case 2: source=global+0x28+self[0x3e]*4;break;
 case 4: source=global+0x48+self[0x3e]*8;break;
 case 8: source=global+0x88+self[0x3e]*16;break;
 }
 unsigned destination=(W(state,0x68)&0xffff)*8;
 if(destination && length) {
 _Z28LockStagedTextureVRAMCopyingv();
 _Z25CleanInvalidateCacheRangePKvj(source,length);
 MemoryMapTexturePalette();LoadToTexturePalette(source,destination+adjustment,length);MemoryUnmapTexturePalette();
 _Z15CleanCacheRangePKvj(source,length);_Z30UnlockStagedTextureVRAMCopyingv();
 }
 }else {
 unsigned selected=ZoneSerializedRecord_GetSelectedPaletteParameter(record,1,self[0x3b]);
 void* model=P(P(self,0x24)+index*0xac,8);
 if(index==4)CharacterPalette_ReplaceModelPaletteSliceFromConfiguration(model,selected,self[0x3e],16);
 else CharacterPalette_ReplaceModelPaletteSliceFromConfiguration(model,selected,self[0x3e],4);
 }
}
