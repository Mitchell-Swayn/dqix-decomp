#include <globaldefs.h>
ARM
extern "C" void* memset(void*,int,unsigned);
extern "C" const char* ResourceStringTable_GetTextByKey(void*,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" void Window_PushTextCanvas(void*,void*,int,int,int,int,int,int);
// Original: arm9/ov023 @ 0x021D9C7C; symbol: Resource_ConfigureOwnerDefaultsAndLoadFormattedRecord; size: 0xb8.
extern "C" void CharacterCreation_OpenAppearanceChoiceWindow(char* self) {
 char* owner=self+0x2b4;*(short*)(owner+0xa0)=13;*(short*)(owner+0xa2)=2;*(short*)(owner+0xa4)=2;*(short*)(owner+0xa6)=19;*(short*)(owner+0xa8)=2;*(short*)(owner+0xaa)=2;*(short*)(owner+0xac)=10;*(short*)(owner+0xae)=12;owner[0xb1]=2;owner[0xb7]=10;owner[0xb5]=1;owner[0xb6]=1;
 char* buffer=*(char**)(self+0xf8);memset(buffer,0,2400);sprintf(buffer,ResourceStringTable_GetTextByKey(self+0xe0,17012));Window_PushTextCanvas(owner,buffer,0,0,0,1,0,0);
}
