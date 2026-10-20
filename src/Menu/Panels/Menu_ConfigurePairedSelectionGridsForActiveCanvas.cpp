#include <globaldefs.h>
ARM
extern "C" {
    void* _ZN9GameState11GetInstanceEv();
    void Selection_InitializeTouchAndDirectionalControls(void*);
    void Grid_SetOrientationAndCoordinatePointers(void*,int,int,int);
    void Grid_SetEntryCountAndClampSelection(void*,int);
    void Grid_SelectIndexAndInvalidateTouchHistory(void*,void*);
    void Grid_SelectIndexAndComputePageCoordinates(void*,void*);
    void Selection_DisableTouchInput(void*);
    void Selection_DisableDirectionalInput(void*);
}
struct PackedCounts {
    unsigned short low:5;
    unsigned short high:11;
};
// Original: arm9/ov023 @ 0x021E6E60; symbol: func_ov023_021e6e60; size: 0x23C.
// Configures paired embedded controls; selector meanings and resource roles remain uncertain.
extern "C" void Menu_ConfigurePairedSelectionGridsForActiveCanvas(unsigned char* p) {
    _ZN9GameState11GetInstanceEv();
    int kind,width,count,mode=0;
    unsigned range;
    void* resource;
    switch(p[0x1371]) {
        case 1:count=1;
        range=6;
        kind=count;
        width=range;
        resource=*(void**)(p+0x13d4);
        break;
        case 2:count=1;
        range=4;
        kind=count;
        width=range;
        resource=*(void**)(p+0x13d8);
        break;
        case 3:resource=*(void**)(p+0x13dc);
        kind=2;
        width=8;
        count=12;
        range=192;
        break;
        case 4:count=1;
        width=8;
        kind=count;
        range=width;
        resource=*(void**)(p+0x13e0);
        break;
        case 5:range=((PackedCounts*)(p+0x13c4))->low;
        kind=1;
        count=(int)(range-1)/9+1;
        width=9;
        if(range<9)width=range;
        resource=*(void**)(p+0x13e4);
        break;
        case 6:count=1;
        range=2;
        kind=count;
        width=range;
        resource=*(void**)(p+0x13f8);
        break;
        case 10:count=1;
        range=2;
        kind=count;
        width=range;
        resource=*(void**)(p+0x13e8);
        break;
        case 11:resource=*(void**)(p+0x13ec);
        count=6;
        kind=1;
        width=10;
        range=60;
        break;
        case 12:range=((PackedCounts*)(p+0x13c4))->high;
        kind=2;
        mode=1;
        count=(int)(range-1)/16+1;
        width=(int)(range-1)/2+1;
        if(width>8)width=8;
        resource=*(void**)(p+0x13f0);
        break;
        case 13:kind=1;
        width=8;
        count=kind;
        range=width;
        resource=*(void**)(p+0x13f4);
        break;
        default:Selection_DisableTouchInput(p+0xac);
        Selection_DisableDirectionalInput(p+0xac);
        return;
    }
    Selection_InitializeTouchAndDirectionalControls(p+0xac);
    Grid_SetOrientationAndCoordinatePointers(p+0xb0,kind,width,mode);
    Grid_SetOrientationAndCoordinatePointers(p+0x100,kind,width,mode);
    Grid_SetEntryCountAndClampSelection(p+0xb0,range);
    Grid_SetEntryCountAndClampSelection(p+0x100,range);
    *(int*)(p+0xb4)=count;
    *(int*)(p+0x104)=count;
    Grid_SelectIndexAndInvalidateTouchHistory(p+0xb0,resource);
    Grid_SelectIndexAndComputePageCoordinates(p+0x100,resource);
    p[0x140]=1;
    p[0x141]=1;
    p[0x13a0]=0;
}
