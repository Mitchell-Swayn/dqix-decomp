#include <globaldefs.h>
ARM
extern "C" {
void* _ZN9GameState11GetInstanceEv();
void* GameState_GetIndexList(void*);
int Inventory_GetNthPositiveItemId(void*,int,int);
int Inventory_GetNthPositiveQuantity(void*,int,int);
unsigned char Inventory_MapShopCategoryToGroup(unsigned);
void TextCanvas_EnableEntryUppercaseFormatting(unsigned char*,int);
void TextCanvas_EnableGroupEntryNavigation(unsigned char*,int);
void TextCanvas_DisableEntryNavigation(unsigned char*,int);
void TextCanvas_HideEntry(unsigned char*,int);
void TextCanvas_ShowGroupEntries(unsigned char*,int);
void TextCanvas_ShowDisplayPart(unsigned char*,int);
void TextCanvas_SetGroupPalette(char*,int,unsigned char);
void TextCanvas_SetEntryTextPointer(char*,int,int);
void TextCanvas_SetEntryNumericValue(char*,int,int);
void* TextCanvas_GetEntryMessageText(char*,int);
void TextCanvas_SetGroupBottomCornerSymbolsEnabled(char*,int,int);
int TextCanvas_CreateAndConfigureDisplayPart(char*,int);
int Inventory_CountOccupiedSlots(char*);
char* ZoneState2754_FindPrimaryRecordByKey(void*,int);
int GameState_CountPositiveSignedByteQuantitiesForGlobalElement(void*);
void Graphics_ConfigureSelectedPartModes(void*,void*,int,int);
}
// Original: arm9/ov003 @ 0x02177DD4; symbol: func_ov003_02177dd4; size: 0x3B8.
extern "C" void Shop_RefreshSellableItemList(char* p){
 char* list; int selected; short title,fourth,pagePart,pageCountPart,message; int count; short* keys; signed char* values; int word,half;char* record; int value;
 list=(char*)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
 selected=0;
 keys=0;values=0;
 char* display=*(char**)(p+0x89c);
 int group=0x16;short first=0xa7,second=0xaf,third=0xb7,fifth=0xc7;
 title=0xa6;fourth=0xbf;pagePart=0xcf;pageCountPart=0xd0;
 short rows=8;
 if(*(short*)(p+0x100c)==0x77){
 group=(short)(*(short*)(p+0x1012)-0x11e);
 selected=Inventory_MapShopCategoryToGroup(group);
 count=GameState_CountPositiveSignedByteQuantitiesForGlobalElement(p);
 *(short*)(p+0x1016)=(count+4)/5;
 if(*(short*)(p+0x1016)==0)*(short*)(p+0x1016)=1;
 message=(short)(group+0x11e);
 group=0x1e;title=0x126;first=0x127;second=0x12c;third=0x131;fourth=0x136;fifth=0x13b;pagePart=0x140;pageCountPart=0x141;rows=5;
 }else{
 count=Inventory_CountOccupiedSlots(list);
 keys=(short*)(list+0xc);values=(signed char*)(list+0x13c);message=0x7a;
 }
 TextCanvas_ShowDisplayPart((unsigned char*)display,group);
 TextCanvas_SetGroupPalette(display,group,0);
 TextCanvas_ShowGroupEntries((unsigned char*)display,group);
 TextCanvas_EnableGroupEntryNavigation((unsigned char*)display,group);
 TextCanvas_SetGroupBottomCornerSymbolsEnabled(display,group,rows<count);
 short start=(short)(*(short*)(p+0x1014)*rows);
 short end=(short)(start+rows);
 for(short i=start;i<end;i++){
 if(count<=i){
 TextCanvas_DisableEntryNavigation((unsigned char*)display,first);
 TextCanvas_HideEntry((unsigned char*)display,first);
 TextCanvas_HideEntry((unsigned char*)display,second);
 TextCanvas_HideEntry((unsigned char*)display,third);
 TextCanvas_HideEntry((unsigned char*)display,fourth);
 TextCanvas_HideEntry((unsigned char*)display,fifth);
 }else{
 word=0;half=0;int key;
 if(keys)key=keys[i];else key=Inventory_GetNthPositiveItemId(list+0x1d4,selected,i);
 record=ZoneState2754_FindPrimaryRecordByKey(p+0x874,key);
 if(record){word=*(int*)(record+4);half=*(unsigned short*)(record+0x1a);}
 if(values)value=values[i];else value=Inventory_GetNthPositiveQuantity(list+0x1d4,selected,i);
 Graphics_ConfigureSelectedPartModes(p,record,second,third);
 TextCanvas_EnableEntryUppercaseFormatting((unsigned char*)display,first);
 TextCanvas_SetEntryTextPointer(display,first,word);
 TextCanvas_SetEntryNumericValue(display,second,half);
 TextCanvas_SetEntryNumericValue(display,fifth,value);
 }
 first++;second++;third++;fourth++;fifth++;
 }
 TextCanvas_SetEntryTextPointer(display,title,(int)TextCanvas_GetEntryMessageText(display,message));
 TextCanvas_SetEntryNumericValue(display,pagePart,*(short*)(p+0x1014)+1);
 TextCanvas_SetEntryNumericValue(display,pageCountPart,*(short*)(p+0x1016));
 TextCanvas_CreateAndConfigureDisplayPart(display,group);
}
