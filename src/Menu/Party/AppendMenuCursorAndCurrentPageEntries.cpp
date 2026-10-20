#include <globaldefs.h>
ARM
struct MenuSelection {char pad[0x54];char range[4];};
extern "C" int TextMarkup_AppendFrameTag(char*,int,int,int,int,int);extern "C" int TextMarkup_AppendCursorTag(char*,int);extern "C" void Selection_ComputeBoundedPageEntryRange(void*,int*,int*);extern "C" void PartyMenu_AppendFieldActionNamesInRange(void*,char*,int,int,int);
// Original: arm9/ov002 @ 0x0215EC4C; symbol: AppendMenuCursorAndCurrentPageEntries; size: 0x98.
// Appends optional style and cursor markup, then formats current bounded page entries.
extern "C" void AppendMenuCursorAndCurrentPageEntries(char* self,char* out,int styled){if(!out)return;int cursor=*(short*)(self+0x1bfa)%8;if(styled)TextMarkup_AppendFrameTag(out,cursor,8,5,5,5);TextMarkup_AppendCursorTag(out,cursor);int first,last;Selection_ComputeBoundedPageEntryRange(&((MenuSelection*)(self+0xec8))->range,&first,&last);PartyMenu_AppendFieldActionNamesInRange(self,out,*(signed char*)(self+0x1c20),first,last);}
