#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/AllocatorUnion.h"
#include <std_library_functions.h>
ARM
struct GameState;
struct VariantFlags {unsigned char variant:1;unsigned char rest:7;};
extern "C" {
void Graphics_InitializeCanvasTransferState(char*);
void Graphics_InitializeSpriteResourceBuffers(unsigned char*);
void BitArray_SetIndexedBoolean(void*,unsigned char*,int,int);
unsigned BitArray_ReadNonnegativeIndexMask(void*,unsigned char*,int);
void KeyRepeater_Initialize(char*,char*);
void KrakPot_ResetRecipeInventoryContext(char*);
void KrakPot_InitializeAlchemyItemDescriptor(char*);
void Menu_ResetLayout(char*);
}
extern "C" {
void* GameState_GetSerializedProgressState();
void ScriptRecordTable_Reset(unsigned int*);
void ResourceStringLoader_Reset(char*);
}
#define W(o) (*(int*)(self+(o)))
#define H(o) (*(short*)(self+(o)))
// Original: arm9/ov006 @ 0x02157A60; symbol: func_ov006_02157a60; size: 0x218.
// Initializes grouped selection ownership, display records, invalid selections and protagonist variant.
extern "C" void KrakPot_InitializeMenu(unsigned char* self) {
 unsigned char* global=(unsigned char*)GameState_GetSerializedProgressState();
 if(!BitArray_ReadNonnegativeIndexMask(global,global+0x8c,0x777)) BitArray_SetIndexedBoolean(global,global+0x8c,0x777,1);
 W(0)=0;W(0x3b4)=0;W(0x428)=-1;self[0x42d]=0;self[0x42e]=0;
 W(8)=0;
 W(12)=0;
 W(16)=0;
 W(20)=0;
 W(24)=0;
 W(28)=0;
 W(32)=0;
 W(36)=0;
 W(40)=0;
 W(44)=0;
 W(48)=0;
 W(52)=0;
 W(56)=0;
 W(68)=0;
 W(72)=0;
 W(76)=0;
 W(80)=0;
 Graphics_InitializeCanvasTransferState((char*)self+0x54);
 KrakPot_ResetRecipeInventoryContext((char*)(self+0x74));
 KeyRepeater_Initialize((char*)self+0x9c,(char*)self+0xa8);
 Graphics_InitializeSpriteResourceBuffers(self+0xac);
 Menu_ResetLayout((char*)self+0x100);
 ScriptRecordTable_Reset((unsigned*)(self+0x14c));
 ResourceStringLoader_Reset((char*)self+0x158);
 for(unsigned char i=0;i<4;++i) KrakPot_InitializeAlchemyItemDescriptor((char*)self+0x17c+i*0x74);
 W(0x350)=0;W(0x354)=-1;W(0x358)=-1;H(0x35c)=0;
 H(862)=-1;
 H(864)=-1;
 H(866)=-1;
 H(868)=-1;
 H(870)=-1;
 H(872)=-1;
 H(874)=-1;
 H(876)=-1;
 H(878)=-1;
 H(880)=-1;
 H(0x376)=0;H(0x374)=0;H(0x372)=0;
 H(0x37c)=-1;H(0x378)=H(0x37a)=H(0x37c);H(0x37e)=-1;H(0x380)=0;H(0x382)=0;
 *((signed char*)self+0x384)=-1;*((signed char*)self+0x385)=-1;
 self[902]=0;
 self[903]=0;
 self[904]=0;
 self[905]=0;
 self[906]=0;
 self[907]=0;
 self[910]=0;
 self[909]=0;
 self[908]=0;
 self[911]=0;
 self[912]=0;
 self[913]=0;
 self[914]=0;
 self[915]=0;
 H(0x394)=0;self[0x396]=0;self[0x397]=0;
 GameState* state=GameState::GetInstance();
 GameObject* protagonist=state->GetProtagonist();
 unsigned char* nested=*(unsigned char**)((unsigned char*)protagonist+0x150);
 self[0x396]=((VariantFlags*)(nested+0x49c))->variant;
 W(0x39c)=0;W(0x3a4)=1;W(0x3a8)=0;W(0x3ac)=0;W(0x3b0)=-1;
 self[0x42f]=0;self[0x430]=self[0x431]=0;self[0x432]=0;self[0x433]=0;self[0x434]=0;self[0x42c]=0;
}
