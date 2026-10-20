struct WindowCanvasOwner;
struct WindowCanvasRecord;
#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((p)+(o)))
#define P(p,o) (*(unsigned char**)((p)+(o)))
#define H(p,o) (*(short*)((p)+(o)))
#define U(p,o) (*(unsigned short*)((p)+(o)))
// Original data: arm9/ov012 @ 0x218b088; symbol: data_ov012_0218b088.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 0000000000000000b4941802000000003499180200000000f49a180200000000bc9c180200000000fc9d180200000000b09f180200000000f4a1180200000000 ...; full span in module reference.
// Observed span: 128 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov012.md.
// Original data: arm9/main @ 0x20e6d5c; symbol: data_020e6d5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000000000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
struct Owner{};typedef void(Owner::*Handler)(char*,int);struct Table{Handler methods[16];};extern "C" {WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);void* memset(void*,int,unsigned);int Window_ReplaceCanvasTextById(void*,unsigned,void*,unsigned,unsigned char);extern Table ProfileEditorRefreshPageText_UnknownRoleProcedureReferenceRecords;extern Handler ShopUpdateInterface_UnknownRoleInitializedBytes;}
// Original: arm9/ov012 @ 0x02185BF0; symbol: Text_FormatReadyRecordThroughMemberTable; size: 0x108.
// Formats a ready record through copied native member-function table and reloads staged text.
extern "C" void ProfileEditor_RefreshPageText(unsigned char* self,unsigned id,int enabled){unsigned char* record=(unsigned char*)Window_FindActiveCanvasById((WindowCanvasOwner*)(self+0xac),id);if(!record)return;int styled=0;if(enabled)record[0xc5]|=64;else record[0xc5]&=~64;if(record[0xc5]&2)styled=1;memset(P(self,0x1374),0,2400);Table table=ProfileEditorRefreshPageText_UnknownRoleProcedureReferenceRecords;table.methods[0]=ShopUpdateInterface_UnknownRoleInitializedBytes;table.methods[15]=ShopUpdateInterface_UnknownRoleInitializedBytes;Handler selected=ShopUpdateInterface_UnknownRoleInitializedBytes;if(table.methods[id])(((Owner*)self)->*table.methods[id])((char*)P(self,0x1374),styled);Window_ReplaceCanvasTextById(self+0xac,id,P(self,0x1374),0,0);}
