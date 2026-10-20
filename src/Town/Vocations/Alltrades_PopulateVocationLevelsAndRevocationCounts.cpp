#include <globaldefs.h>
ARM
class GameState;class Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(GameState*,int);
extern "C" unsigned char* GameObject_GetLinkedIndexedState(void*);
extern "C" void TextCanvas_DisableGroupEntryNavigation(unsigned char*);
extern "C" void TextCanvas_EnableEntryNavigation(unsigned char*,int);
extern "C" void TextCanvas_GetGroupPixelOrigin(char*,int,short*,short*);
extern "C" void TextCanvas_SetGroupOriginFromPixels(unsigned char*,int,int,int);
extern "C" void TextCanvas_GetEntryLocalPosition(char*,int,short*,short*);
extern "C" void TextCanvas_SetEntryLocalPosition(char*,int,int,int);
extern "C" void TextCanvas_GetGroupTileDimensions(char*,int,short*,short*);
extern "C" void TextCanvas_SetGroupTileDimensions(unsigned char*,int,int,int);
extern "C" void TextCanvas_GetEntryTextWidthOrRectangleDimensions(unsigned char*,unsigned,short*,short*);
extern "C" void TextCanvas_ShowEntry(unsigned char*,int);
extern "C" void TextCanvas_HideGroupEntries(char*,int);
extern "C" void TextCanvas_SetEntryTextColor(char*,int,unsigned);
extern "C" void TextCanvas_SetEntryNumericValue(char*,int,int);
extern "C" void TextCanvas_SetEntryTextFromResourceKey(unsigned char*,int,int);
extern "C" void TextCanvas_SetEntryMessageKey(char*,int,short);
extern "C" void TextCanvas_EnableEntryHorizontalCentering(unsigned char*,int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
extern "C" int CountNonNullEntries12(char*);
// Original: arm9/ov003 @ 0x02158480; symbol: func_ov003_02158480; size: 0x2BC.
// Populates twelve listed member values and status markers, then aligns group six to the populated-size group.
extern "C" void Alltrades_PopulateVocationLevelsAndRevocationCounts(char* p) {
 char* display=*(char**)(p+0x18);
 int key=0x13;short secondary=0x1f,valueKey=0x2b,statusKey=0x37;
 TextCanvas_HideGroupEntries(display,6);
 // Original caller supplies group six in r1 although the current callee ignores that register.
 ((void (*)(unsigned char*,int))TextCanvas_DisableGroupEntryNavigation)((unsigned char*)display,6);
 TextCanvas_ShowEntry((unsigned char*)display,0x43);
 TextCanvas_EnableEntryHorizontalCentering((unsigned char*)display,0x43);
 int count=CountNonNullEntries12(p);int group=-1;
 if(count<=6)group=7;else if(count>=7&&count<=8)group=8;else if(count>=9&&count<=10)group=9;
 Object3D* member=_ZN9GameState21GetPartyMemberByIndexEi((GameState*)_ZN9GameState11GetInstanceEv(),(signed char)p[0x1f7]);
 if(member) {
 unsigned char* values=GameObject_GetLinkedIndexedState(member);
 for(unsigned char i=0;i<12;++i) {
 int entry=(*(int**)(p+0x20))[i];
 if(entry) {
 TextCanvas_EnableEntryNavigation((unsigned char*)display,key);
 TextCanvas_ShowEntry((unsigned char*)display,key);
 TextCanvas_ShowEntry((unsigned char*)display,secondary);
 TextCanvas_ShowEntry((unsigned char*)display,valueKey);
 TextCanvas_SetEntryMessageKey(display,key,(short)(entry-1));
 TextCanvas_SetEntryNumericValue(display,valueKey,*(unsigned short*)(values+entry*2+0x16c));
 unsigned status=(values+entry)[0x186];
 if(status) {
 short statusValue=status+0x12;int nibble=5;if(status==10)nibble=13;
 short x,y,width,kind;
 TextCanvas_GetEntryLocalPosition(display,key,&x,&y);
 TextCanvas_GetEntryTextWidthOrRectangleDimensions((unsigned char*)display,key,&width,&kind);
 TextCanvas_SetEntryLocalPosition(display,statusKey,(short)(x+width+1),y);
 TextCanvas_ShowEntry((unsigned char*)display,statusKey);
 TextCanvas_SetEntryTextFromResourceKey((unsigned char*)display,statusKey,statusValue);
 TextCanvas_SetEntryTextColor(display,statusKey,nibble);
 }
 }
 key=(short)(key+1);++secondary;++valueKey;++statusKey;
 }
 }
 if(group>0) {
 short x,y,a,b;
 TextCanvas_GetGroupPixelOrigin(display,group,&x,&y);
 TextCanvas_GetGroupTileDimensions(display,group,&a,&b);
 TextCanvas_SetGroupOriginFromPixels((unsigned char*)display,6,x,y);
 TextCanvas_SetGroupTileDimensions((unsigned char*)display,6,a,b);
 TextCanvas_GetGroupPixelOrigin(display,6,&x,&y);
 TextCanvas_GetGroupTileDimensions(display,6,&a,&b);
 }
 TextCanvas_CreateAndConfigureDisplayPart(display,6);
}
