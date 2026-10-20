#pragma thumb off
#pragma optimization_level 2
#pragma optimize_for_size off
#pragma opt_common_subs off
#pragma always_inline on
struct Item{unsigned char kind,length;unsigned short pad;const void* data;};// A slot is addressed relative to its preceding word; only item is written.
struct ItemWindow{unsigned preceding;Item item;};union ItemList{struct Layout{unsigned char count,pad[3];Item items[16];}fields;unsigned words[33];};

// Original: arm9/main @ 0x020D4C7C; symbol: func_020d4c7c; size: 0x158.
extern "C" void WM_GetOtherElements(ItemList* out,const unsigned short* packet){ItemList list;if(packet[30]){list.fields.count=0;*out=list;return;}list.fields.count=packet[31];if(!list.fields.count){*out=list;return;}if(list.fields.count>16)list.fields.count=16;const unsigned char* cursor=(const unsigned char*)(packet+32);unsigned char limit=packet[0]*2-64;int i;unsigned char consumed=0;i=consumed;int bound;if(i<list.fields.count){do{ItemWindow* window=(ItemWindow*)((char*)&list+i*8);window->item.kind=cursor[0];window->item.length=cursor[1];window->item.data=cursor+2;unsigned char step=window->item.length+2;consumed+=step;if(consumed>limit){list.fields.count=0;*out=list;return;}bound=list.fields.count;++i;cursor+=step;}while(i<bound);}*out=list;}
