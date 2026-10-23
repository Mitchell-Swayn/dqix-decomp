#include <globaldefs.h>
ARM
#pragma force_active on
#define WORD(p,o) (*(int*)((p)+(o)))
#define UWORD(p,o) (*(unsigned*)((p)+(o)))
#define HALF(p,o) (*(short*)((p)+(o)))
#define UHALF(p,o) (*(unsigned short*)((p)+(o)))
#define BYTE(p,o) (*(unsigned char*)((p)+(o)))
#define SBYTE(p,o) (*(signed char*)((p)+(o)))
#define PTR(p,o) (*(char**)((p)+(o)))
struct Record;struct WindowCanvasOwner;struct WindowCanvasRecord;struct Owner;
struct ActionIdWord {unsigned id:12;unsigned rest:20;};
extern "C" {
unsigned TextContext_GetSharedInstance();
void* memset(void*,int,unsigned);
Record* BattleMenu_FindActionDefinition(unsigned char*,unsigned);
void Text_CopyActionDescriptionByKey(int,char*);
void* ResourceStringTable_GetTextByKey(void*,void*);
void TextMarkup_ExpandAndWrapText(void*,int,void*,void*,int,int,unsigned);
WindowCanvasRecord* Window_FindActiveCanvasById(WindowCanvasOwner*,unsigned);
int Window_ReplaceCanvasTextById(Owner*,unsigned,void*,unsigned,unsigned char);
int Window_PushTextCanvas(...);
}
// Original: arm9/ov000 @ 0x0217A19C; symbol: func_ov000_0217a19c; size: 0x140.
// Wraps the selected shared action description and replaces or opens canvas 24.
extern "C" void BattleMenu_UpdateSharedPartyActionDescriptionWindow(char* self,unsigned char* record) {
    char* panel;
    char* scratch=PTR((char*)TextContext_GetSharedInstance(),0x5c);
    memset(scratch,0,0x960);
    char* action=(char*)BattleMenu_FindActionDefinition(record,UHALF(self+SBYTE(self,0x1d6d)*2,0x10));
    if(action) Text_CopyActionDescriptionByKey(((ActionIdWord*)(action+4))->id,scratch);
    else scratch=(char*)ResourceStringTable_GetTextByKey(self+0xb8,(void*)32);
    char wrap[0x800];
    TextMarkup_ExpandAndWrapText((void*)TextContext_GetSharedInstance(),10,scratch,wrap,152,0,0);
    scratch=wrap;
    panel=self+0x188;
    if(Window_FindActiveCanvasById((WindowCanvasOwner*)panel,24)) Window_ReplaceCanvasTextById((Owner*)panel,24,scratch,1,0);
    else {
        HALF(panel,0xa0)=22;HALF(panel,0xa2)=7;HALF(panel,0xa4)=5;HALF(panel,0xa6)=24;
        HALF(panel,0xa8)=12;HALF(panel,0xaa)=8;HALF(panel,0xac)=10;HALF(panel,0xae)=14;
        BYTE(panel,0xb1)=24;
        Window_PushTextCanvas(panel,scratch,0,0,0,1,0,0);
    }
}
