#include <globaldefs.h>
struct State;
struct TilemapOwner { unsigned int field0[5]; unsigned short* tiles; };
extern "C" void* Menu_GetDisplayRecordRegistry(State*);
extern "C" void* MenuRecordList_LocateByKey(void**,unsigned short);
extern "C" void* MenuLayerRecord_GetLayerTransferState(void*);
extern "C" int TextCanvas_HasActiveTilemap(char*);
extern "C" int TextCanvas_ClassifyOverlappingCorner(void*,int);
extern "C" void Tilemap_FillClippedRectangle(TilemapOwner*,unsigned int,short,short,short,short,unsigned int);
// Original: arm9/ov023 @ 0x021F86FC; symbol: func_ov023_021f86fc; size: 0x1BC.
// Draws the configured entry rectangle and optional corner tiles in its tilemap.
extern "C" void DrawConfiguredRecordTilemapBorder(unsigned char* self,void* owner) {
    void* list=Menu_GetDisplayRecordRegistry((State*)owner);
    void* record=MenuRecordList_LocateByKey((void**)list,self[0x108]);
    if(!record) return;
    TilemapOwner* tilemap=(TilemapOwner*)MenuLayerRecord_GetLayerTransferState(record);
    if(!TextCanvas_HasActiveTilemap((char*)self+0x20)) return;
    unsigned char flags=self[0xe5];
    if(flags&0x20) return;
    if(flags&0x80) return;
    short x=*(short*)(self+0xcc);
    short y=*(short*)(self+0xce);
    short width=*(short*)(self+0xc8);
    short height=*(short*)(self+0xe0);
    Tilemap_FillClippedRectangle(tilemap,1,x,y,width,height,0);
    if(height==0) return;
    if(!TextCanvas_ClassifyOverlappingCorner(self+0x20,1))
        Tilemap_FillClippedRectangle(tilemap,2,x,y,1,1,0);
    if(!TextCanvas_ClassifyOverlappingCorner(self+0x20,2))
        Tilemap_FillClippedRectangle(tilemap,0x402,(short)(x+width-1),y,1,1,0);
    if(!TextCanvas_ClassifyOverlappingCorner(self+0x20,4))
        Tilemap_FillClippedRectangle(tilemap,0x802,x,(short)(y+height-1),1,1,0);
    if(!TextCanvas_ClassifyOverlappingCorner(self+0x20,8))
        Tilemap_FillClippedRectangle(tilemap,0xc02,(short)(x+width-1),(short)(y+height-1),1,1,0);
}
