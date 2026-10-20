#include <globaldefs.h>
ARM
#pragma optimization_level 4
struct BGControl { unsigned short priority:2; unsigned short character:4; unsigned short unused:1; unsigned short color:1; unsigned short screen:5; unsigned short extended:1; unsigned short size:2; };
extern "C" {
void* _ZN16BackgroundLoader11GetInstanceEv();
void _ZN16BackgroundLoader10RemoveTaskEi(void*,int);
void Graphics_WriteBackgroundControlRegisterFields(unsigned,unsigned,unsigned,unsigned,unsigned);
void Graphics_SetBG1Priority(unsigned);
void Graphics_ConfigureMainBackgroundTwoControl(unsigned,unsigned,unsigned,unsigned);
void Graphics_SetBackground2Priority(unsigned);
void CancelOwnerTaskAndResetEmbeddedState(void*);
void Ov017_AllocateVRAMStagingEntries(char*,int,unsigned);
void Window_ClearResourceBuffers(unsigned char*);
void Graphics_ResetCountedThirtyTwoByteTransfers(void*);
void Window_ResetResourceTransfers(void*);
void Graphics_FreeVRAMStagingEntries(void*,int);
void Selection_ReleaseAttachedDisplayResources(unsigned char*);
void* memset(void*,int,unsigned);
void _Z25CleanInvalidateCacheRangePKvj(const void*,unsigned);
void LoadToMainBG1CharacterData(const void*,unsigned,unsigned);
void Graphics_InitializeRecordGridAndCanvasArrays(unsigned char*);
}
// Original: arm9/ov017 @ 0x02199780; symbol: func_ov017_02199780; size: 0x1E4.
extern "C" void Field_RestoreBackgroundsAfterActionShortcutDisplay(unsigned char* self) {
 if(!*(int*)(self+0x4080))return;
 if(*(int*)(self+0x4078)) {
  *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x100;
  if(*(int*)(self+0x407c)>=0) {
   void* loader=_ZN16BackgroundLoader11GetInstanceEv();
   _ZN16BackgroundLoader10RemoveTaskEi(loader,*(int*)(self+0x407c));
  }
  *(volatile unsigned short*)0x04000050=0;
  *(volatile unsigned short*)0x04000008=(*(volatile unsigned short*)0x04000008&~3)|1;
  BGControl* bg=*(BGControl**)(self+0x3ca8);
  Graphics_WriteBackgroundControlRegisterFields(bg->size,bg->color,bg->screen,bg->character,bg->extended);
  Graphics_SetBG1Priority(bg->priority);
  bg=*(BGControl**)(self+0x3cac);
  Graphics_ConfigureMainBackgroundTwoControl(bg->size,bg->color,bg->screen,bg->character);
  Graphics_SetBackground2Priority(bg->priority);
  if(*(void**)(self+0x4084)) {
   CancelOwnerTaskAndResetEmbeddedState(*(void**)(self+0x4084));
   *(void**)(self+0x4084)=0;
  }
  if(*(void**)(self+0x4074)) {
   Ov017_AllocateVRAMStagingEntries((char*)self+0x3cb4,2,0x800);
   Window_ClearResourceBuffers(*(unsigned char**)(self+0x3cb0));
   Graphics_ResetCountedThirtyTwoByteTransfers(*(void**)(self+0x3cb0));
   Window_ResetResourceTransfers(*(void**)(self+0x3cb0));
   Graphics_FreeVRAMStagingEntries(self+0x3cb4,2);
   Selection_ReleaseAttachedDisplayResources(*(unsigned char**)(self+0x3cb0));
   memset(*(void**)(self+0x4074),0,32);
   _Z25CleanInvalidateCacheRangePKvj(*(void**)(self+0x4074),32);
   LoadToMainBG1CharacterData(*(void**)(self+0x4074),0,32);
  }
  *(volatile unsigned*)0x04000000=(*(volatile unsigned*)0x04000000&~0x1f00)|0x1300;
 }
 Graphics_InitializeRecordGridAndCanvasArrays(self);
}
