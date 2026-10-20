#include <globaldefs.h>
ARM
#include <std_library_functions.h>
extern "C" void Graphics_TransferScreenBuffer(void*,int);extern "C" void Resource_ResetActiveOwnerState(void*);extern "C" void Text_AppendSelectedPackedRecord(void*,char*,int,void*);extern "C" int Window_ReplaceCanvasTextById(void*,unsigned,void*,unsigned,unsigned char);extern "C" void Graphics_RefreshEitherDirtyPackedTextRecord(void*,int);extern "C" void Window_ResetResourceTransfers(void*);
// Original: arm9/ov008 @ 0x02184968; symbol: RefreshPackedTextUnlessModeSuppressesIt; size: 0xC4.
// Refreshes dirty packed-record text and entry resources outside modes0/1/14.
extern "C" void RefreshPackedTextUnlessModeSuppressesIt(char* self){int mode=*(signed char*)(self+0xb10);if(mode==0||mode==1||mode==14)return;if(!*(unsigned*)(self+0xb24))Graphics_TransferScreenBuffer(self+0xd0,0);if(*(void**)(self+0xb08)){Resource_ResetActiveOwnerState(*(void**)(self+0xb08));return;}if(*(unsigned*)(self+0xb18)&0x800){memset(*(void**)(self+0xb8),0,0x960);Text_AppendSelectedPackedRecord(self,*(char**)(self+0xb8),0,0);Window_ReplaceCanvasTextById(self+0x130,1,*(void**)(self+0xb8),1,0);*(unsigned*)(self+0xb18)&=~0x800;}Graphics_RefreshEitherDirtyPackedTextRecord(self,1);Window_ResetResourceTransfers(self+0x130);}
