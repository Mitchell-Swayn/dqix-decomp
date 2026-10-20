#include <globaldefs.h>
ARM
extern "C" char* strcpy(char*,const char*);
extern "C" char* strrchr(const char*,int);
extern "C" int _ffix(unsigned);
extern "C" unsigned _fmul(unsigned,unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" const char* _ZNK6Script9Parameter8ToStringEv(const void*);
struct Configuration {signed char selected;char pad[3];int values[9];};
// Original data: arm9/ov003 @ 0x2180cd0; symbol: data_ov003_02180cd0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" Configuration FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov003 @ 0x2180cf8; symbol: data_ov003_02180cf8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
// Original data: arm9/ov003 @ 0x2180d08; symbol: data_ov003_02180d08.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 56 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" char TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant3[],TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant4[];
// Original: arm9/ov003 @ 0x0217BB1C; symbol: func_ov003_0217bb1c; size: 0x19C.
extern "C" int Script_SetSelectedResourceNamesAndFixedValues(char* args) {
 int selected=_ZNK6Script9Parameter5ToIntEv(args);
 if(selected!=FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.selected)return 1;
 const char* name=_ZNK6Script9Parameter8ToStringEv(args+8);
 const char* other=_ZNK6Script9Parameter8ToStringEv(args+16);
 char* slash=strrchr(name,47);
 if(slash)name=slash+1;
 strcpy(TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant3,name);
 strcpy(TownAdvanceModelPreviewLoading_UnknownRoleZeroInitializedStorage_Variant4,other);
 FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.values[0]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+24)));
 FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.values[1]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+32)));
 FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.values[2]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+40)));
 FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.values[3]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+48)));
 FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.values[4]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+56)));
 FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.values[5]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+64)));
 FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.values[6]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+72)));
 FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.values[7]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+80)));
 FilesystemExecuteScriptAfterBackgroundLoad_UnknownRoleZeroInitializedStorage.values[8]=_ffix(_fmul(0x45800000,_ZNK6Script9Parameter7ToFloatEv(args+88)));
 return 1;
}
