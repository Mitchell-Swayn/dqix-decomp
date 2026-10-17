#include <globaldefs.h>
ARM
extern "C" unsigned int ReadWordFieldAtOffset1C();
extern "C" void ClearOwnerBuffersAndResetSignedByteSentinels(signed char*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" const char* GameState_GetGrottoMetadataTextForValidIndex(void*,int);
extern "C" void VectorizedMemset(void*,int,unsigned int);
extern "C" char* strcpy(char*,const char*);
extern "C" void CopyBoundedNameToIndexedSlot(void*,int,const char*);
extern "C" void CopyBoundedTextIntoIndexedSixtyFourByteSlot(unsigned char*,int,const char*);
// Original: arm9/ov004 @ 0x02165D74; symbol: func_ov004_02165d74; size: 0x80.
extern "C" int GameState_CopyGrottoTextAndObjectNameToFirstSlot() {
 unsigned char* owner=(unsigned char*)ReadWordFieldAtOffset1C();
 ClearOwnerBuffersAndResetSignedByteSentinels((signed char*)owner);
 void* game=_ZN9GameState11GetInstanceEv();
 char* object=_ZN9GameState20GetUnknownGameObjectEv(game);
 char text[64]; VectorizedMemset(text,0,64);
 strcpy(text,GameState_GetGrottoMetadataTextForValidIndex(game,0));
 if(object) CopyBoundedNameToIndexedSlot(owner,0,*(const char**)(object+0x134));
 CopyBoundedTextIntoIndexedSixtyFourByteSlot(owner,0,text);
 return 0;
}
