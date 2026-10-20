#include <globaldefs.h>
ARM
extern "C" int AllocatorUnion_AllocateFourByteAligned(...);
extern "C" int String_CountBytesUntilTerminator(...);
extern "C" int _ZNK6Script9Parameter5ToIntEv(...);
extern "C" int _ZNK6Script9Parameter8ToStringEv(...);
extern "C" int CharacterViewer_AppendScenePreset(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char Main_UnknownRoleZeroInitializedStorage_Variant3[];
// Original data: arm9/ov015 @ 0x2194560; symbol: data_ov015_02194560.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov015.md.
extern "C" char CharacterViewerScriptAppendMenuEntry_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov015 @ 0x0218B6E4; symbol: Script_CopyTitleAndBuildLinkedStringOptionList.
extern "C" int CharacterViewer_ScriptAppendScenePreset(char*parameter,int count){
char*initial=parameter;parameter+=8;char*title=C(_ZNK6Script9Parameter8ToStringEv(initial));struct Pair{char*title;char*head;};Pair pair;pair.title=0;pair.head=0;if(title){pair.title=C(AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,String_CountBytesUntilTerminator(title)+1));if(pair.title)strcpy(pair.title,title);}for(int i=1;i<count;i+=3){char*node;char*text=C(_ZNK6Script9Parameter8ToStringEv(parameter));int value=_ZNK6Script9Parameter5ToIntEv(parameter+8);char*last=parameter+16;parameter+=24;int flags=_ZNK6Script9Parameter5ToIntEv(last);node=C(AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,12));P(node,0)=0;H(node,4)=0;B(node,6)=0;P(node,8)=0;if(text){P(node,0)=C(AllocatorUnion_AllocateFourByteAligned(Main_UnknownRoleZeroInitializedStorage_Variant3,String_CountBytesUntilTerminator(text)+1));if(P(node,0))strcpy(P(node,0),text);}H(node,4)=value;B(node,6)=flags;char**link=&pair.head;while(*link)link=(char**)(*link+8);*link=node;}CharacterViewer_AppendScenePreset(P(CharacterViewerScriptAppendMenuEntry_UnknownRoleZeroInitializedStorage,0),&pair);return 1;
}
