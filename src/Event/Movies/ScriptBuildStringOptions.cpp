#include <globaldefs.h>
#include <std_library_functions.h>
ARM
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned,unsigned);
// These owner-local tags and member order come from the integrated owning definition AppendCopiedOptionsEntry.cpp.
struct Entry; struct List;
extern "C" void AppendCopiedOptionsEntry(List*,const Entry*);
// Original data: arm9/ov016 @ 0x219d1bc; symbol: data_ov016_0219d1bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov016.md.
extern "C" unsigned* ScriptBuildStringOptions_UnknownRoleZeroInitializedStorage;
struct Options {short a,b;char* text[3];bool enabled,flag;short value;int integer,pad;};
// Original: arm9/ov016 @ 0x0218DE60; symbol: func_ov016_0218de60; size: 0x1AC.
// Copies three script strings into allocated storage and packs optional flags.
extern "C" int ScriptBuildStringOptions(char* params,int count) {
 unsigned allocator=ScriptBuildStringOptions_UnknownRoleZeroInitializedStorage[2];Options options;memset(&options,0,28);
 options.a=_ZNK6Script9Parameter5ToIntEv(params);
 options.b=_ZNK6Script9Parameter5ToIntEv(params+8);
 const char* text=_ZNK6Script9Parameter8ToStringEv(params+16);
 if(text) {options.text[0]=_ZN13SafeAllocator8AllocateEj(allocator,strlen(text)+1);if(options.text[0])strcpy(options.text[0],text);}
 text=_ZNK6Script9Parameter8ToStringEv(params+24);
 if(text && strlen(text)) {options.text[1]=_ZN13SafeAllocator8AllocateEj(allocator,strlen(text)+1);if(options.text[1])strcpy(options.text[1],text);}
 text=_ZNK6Script9Parameter8ToStringEv(params+32);
 if(text && strlen(text)) {options.text[2]=_ZN13SafeAllocator8AllocateEj(allocator,strlen(text)+1);if(options.text[2])strcpy(options.text[2],text);}
 options.value=_ZNK6Script9Parameter5ToIntEv(params+40);
 char* integerParam=params+48;params+=56;
 options.integer=_ZNK6Script9Parameter5ToIntEv(integerParam);count-=7;
 if(count>0){int enabled=_ZNK6Script9Parameter5ToIntEv(params);params+=8;options.enabled=enabled!=0;--count;}else options.enabled=true;
 if(count>0)options.flag=_ZNK6Script9Parameter5ToIntEv(params)!=0;else options.flag=false;
 AppendCopiedOptionsEntry((List*)ScriptBuildStringOptions_UnknownRoleZeroInitializedStorage,(const Entry*)&options);return 1;
}
