#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct GameState;struct GameResources;struct State;struct S;struct CoordinateState;
extern "C" {
void Graphics_CacheFourMainBackgroundControlsOnce(volatile State* p);void* Zone3D_GetMainInstance();unsigned _ZN12ZoneFeatures8GetColorEv(void*);
void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);void ResourceStringLoader_Reset(char *p);void Menu_ResetLayout(char* obj);void Graphics_InitializeCanvasTransferState(char* p);void Selection_InitializeDisplayController(State* p);void TextCanvas_InitializeLayoutAndTransferDefaults(unsigned char* object);void Resource_InitializeSharedRecordState(char* self,int id,int mode);void Menu_ResetCatalogue(void *object);void ZoneRecord_ResetCompactAttributeTable(unsigned int* p);void EquipmentMenu_ResetCursorRectangle(CoordinateState* self);void _ZN23ZoneContainerRenderPart5ResetEv(void *);void* GameState_GetIndexList(GameState* state);unsigned EquipmentMenu_GetCategoryInventoryType(void* unused, unsigned index);unsigned EquipmentMenu_GetCategoryLinkedEquipmentIndex(void* unused, unsigned index);int Inventory_GetGroupCapacity(short *p,unsigned int i);void* memset(void* dest, int value, unsigned int count);void Grid_InitializeDirectionalSelection(char* p);GameResources* GameResources_GetInstance();unsigned Field_GetSharedSubscreenInstance(void* self);short Inventory_CountPositiveQuantitySlots(void *p,int i);void* __clear(void* destination, unsigned int count);GameObject* GameState_GetObjectWithFlag100(GameState* state, int index);int GameObject_GetLinkedStatOrInvalid(char* p,int i);int Inventory_GetItemQuantityAcrossTypeGroups(const State* s,int key,unsigned type);unsigned int Inventory_GetGroupItemIds(S* p,unsigned int i);
}
#define B(o) (*(unsigned char*)(p+(o)))
#define S8(o) (*(signed char*)(p+(o)))
#define H(o) (*(short*)(p+(o)))
#define W(o) (*(unsigned*)(p+(o)))
struct Row{char prefix[0x2d90];short id;unsigned char kind,skip;unsigned snapshot,render;int x,y,offset;short loaded,pad;};
// Original: arm9/ov005 @ 0x02153BA4; symbol: EquipmentMenu_InitializeController; size: 0x5F4.
// Initializes menu allocators, rendering/selection state, row records and member-dependent page counts.
extern "C" void EquipmentMenu_InitializeController(unsigned self){
#define p ((unsigned char*)self)
 
 B(0xe7c)=0;B(0xe7d)=0;Graphics_CacheFourMainBackgroundControlsOnce((State*)(p+0xe6c));
 W(0xe80)=(*(volatile unsigned*)0x04000000&0x1f00)>>8;
 H(0x3dc2)=_ZN12ZoneFeatures8GetColorEv((char*)Zone3D_GetMainInstance()+0x6c);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+20);
 for(int i=0;i<8;i++)_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x28+i*20);
 for(int i=0;i<16;i++)_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0xc8+i*20);
 _ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x208);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x21c);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x230);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x244);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x258);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x26c);_ZN13SafeAllocator21ResetAllocatorPointerEv(p+0x280);
 W(0xdf4)=0;ResourceStringLoader_Reset((char*)p+0xdf8);W(0xe10)=0;Menu_ResetLayout((char*)p+0xe18);W(0xe64)=0;W(0xe68)=0;
 Graphics_InitializeCanvasTransferState((char*)p+0xe84);Graphics_InitializeCanvasTransferState((char*)p+0xea4);Graphics_InitializeCanvasTransferState((char*)p+0xec4);Selection_InitializeDisplayController((State*)(p+0xee4));
 for(int i=0;i<3;i++)TextCanvas_InitializeLayoutAndTransferDefaults(p+0xfa0+i*224);
 W(0x1240)=0;Resource_InitializeSharedRecordState((char*)p+0x1244,-1,0);Menu_ResetCatalogue(p+0x19e0);ZoneRecord_ResetCompactAttributeTable((unsigned*)(p+0x19ec));EquipmentMenu_ResetCursorRectangle((CoordinateState*)(p+0x1a34));
 for(int i=0;i<36;i++)_ZN23ZoneContainerRenderPart5ResetEv(p+0x1a70+i*136);
 for(int i=0;i<24;i++)_ZN23ZoneContainerRenderPart5ResetEv(p+0x3030+i*136);
 _ZN23ZoneContainerRenderPart5ResetEv(p+0x3cf0);
 H(0x3d78)=-1;W(0x3d7c)=0;W(0x3d80)=0;W(0x3d84)=0;W(0x3d88)=0;W(0x3d8c)=0;W(0x3d90)=0;W(0x3d94)=0;
 for(int i=0;i<24;i++){Row* row=(Row*)(self+i*28);row->id=-1;row->kind=0;row->skip=0;row->snapshot=0;row->render=0;row->x=0;row->y=0;row->offset=-1;row->loaded=-1;}
 GameState* game=(GameState*)((void*)GameState::GetInstance());unsigned char* list=(unsigned char*)GameState_GetIndexList(game);
 for(int i=0;i<8;i++){unsigned group=EquipmentMenu_GetCategoryInventoryType(p,i);*(short*)((p+(i<<1))+0x3d98)=Inventory_GetGroupCapacity((short*)(list+0x1d4),group);}
 B(0x3da8)=0;B(0x3da9)=0;B(0x3daa)=0;B(0x3dab)=0;H(0x3dac)=0;H(0x3dae)=0;H(0x3db0)=0;H(0x3db2)=0;H(0x3db4)=0;B(0x3db7)=0;B(0x3db8)=2;B(0x3db9)=2;B(0x3dba)=0;B(0x3dbb)=0;B(0x3dbc)=0;B(0x3dbe)=0;B(0x3dbd)=0;B(0x3dbf)=0;B(0x3dc4)=0;W(0x3dc8)=0;
 memset(p+0x3dcc,0,4);S8(0x3dc0)=-1;Grid_InitializeDirectionalSelection((char*)p+0x19f4);
 B(0x1a31)=0;B(0x3dd0)=0;B(0x3dd1)=0;B(0x3dd2)=0;B(0x3dd3)=0;
 for(int i=0;i<8;i++)*(unsigned char*)((p+i)+0x3dd4)=0;
 B(0x3ddc)=0;B(0x3ddd)=0;B(0x3dde)=0;B(0x3ddf)=0;
 for(int i=0;i<8;i++){for(int j=0;j<64;j++)*(unsigned short*)((p+(i<<7)+(j<<1))+0x3e84)=65535;*(unsigned char*)((p+i)+0x4284)=0;}
 H(0x3de2)=0;W(0x3de4)=0;W(0x3de8)=0;W(0x3dec)=0;B(0x3df0)=3;B(0x3df1)=30;B(0x3df2)=30;B(0x3df3)=0;
 char* resources=(char*)GameResources_GetInstance();char* object=(char*)Field_GetSharedSubscreenInstance(*(void**)(resources+0x3708));int* ids=(int*)(object+0x4ec);int members=*(int*)(object+0x4e8);
 for(int i=0;i<8;i++){
  unsigned group=EquipmentMenu_GetCategoryInventoryType(p,i);unsigned slot=EquipmentMenu_GetCategoryLinkedEquipmentIndex(p,i);int count=Inventory_CountPositiveQuantitySlots(list+0x1d4,group);
  short values[4];__clear(values,8);
  for(int j=0;j<members;j++){char* actor=(char*)GameState_GetObjectWithFlag100(game,ids[j]);if(actor){values[j]=GameObject_GetLinkedStatOrInvalid(actor,slot);if(values[j]>0){int k=0;while(k<j)k++;if(!Inventory_GetItemQuantityAcrossTypeGroups((State*)(list+0x1d4),values[j],9))count++;}}}
  unsigned char* pages; if(count>0){*(unsigned char*)((p+0x3df4)+i)=(count-1)/16+1;pages=(p+0x3df4)+i;}else{*(unsigned char*)((p+0x3df4)+i)=1;pages=(p+0x3df4)+i;}
  short* entries=(short*)Inventory_GetGroupItemIds((S*)(list+0x1d4),group);int length=Inventory_GetGroupCapacity((short*)(list+0x1d4),group);int last=0;
  for(int j=0;j<length;j++){if(entries[j]>0 && last<j)last=j;}
  unsigned char used=last/16+1;if(used>*pages)*pages=used;*(unsigned char*)((p+i)+0x3dfc)=0;
 }
 B(0x3e04)=0;B(0x3e05)=0;S8(0x3e07)=-2;B(0x3e06)=0;H(0x3e08)=-1;H(0x3e0a)=-1;
}
