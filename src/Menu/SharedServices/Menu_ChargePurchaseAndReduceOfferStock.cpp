#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct CountPrice{unsigned count:7,price:25;};
struct FlagBits{unsigned char a:1,b:1,index:6;};
struct Nibbles{unsigned char low:4,high:4;};
struct SixFlags{unsigned char index:6,a:1,b:1;};
extern "C" unsigned GameState_GetIndexList(...);
extern "C" unsigned GetTypeSevenRowMajorIndex(...);
extern "C" unsigned _ZN9GameState11GetInstanceEv(...);
extern "C" unsigned Menu_GetInventorySlotOnCurrentPage(...);
extern "C" unsigned Menu_QueueScriptEntry(...);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov004 @ 0x0215c0c0; symbol: SubtractSelectedQuantityAndDisplayPriceMessage.
extern "C" int Menu_ChargePurchaseAndReduceOfferStock(void* p){int index=GetTypeSevenRowMajorIndex(p,0x5b);if(index<0)return 0;char* record=(char*)Menu_GetInventorySlotOnCurrentPage(p,(unsigned char)index);if(!record)return 0;char* list=(char*)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());int quantity=B((void*)U(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),0x11);int price=((CountPrice*)(record+4))->price;int total=quantity*price;((CountPrice*)(record+4))->count-=quantity;unsigned char* shared=(unsigned char*)U(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8);U(list,0xf6c)-=B(shared,0x11)*((CountPrice*)(record+4))->price;B((void*)U(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),0x9d)=1;if(total>=50000)Menu_QueueScriptEntry(p,0x2366);else Menu_QueueScriptEntry(p,0x2364);return 0;}
