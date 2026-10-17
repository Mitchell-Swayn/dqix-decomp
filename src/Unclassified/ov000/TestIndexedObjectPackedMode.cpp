#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" char* GameState_FindIndexedObjectWithFlag400(void*,int);
// Original: arm9/ov000 @ 0x02156068; symbol: func_ov000_02156068; size: 0xb0.
extern "C" int TestIndexedObjectPackedMode(void*,int index,int value,int mode) {
    bool valid;
    if(index>=0 && index<=3)valid=true;
    else valid=false;
    if(valid)return 0;
    char* obj=GameState_FindIndexedObjectWithFlag400(_ZN9GameState11GetInstanceEv(),index);
    if(!obj)return 0;
    char* record=*(char**)(obj+0x144);
    if(!record)return 0;
    struct Bits {
        unsigned short pad[5];
        unsigned short low:7;
        unsigned short value:4;
        unsigned short bit11:1;
        unsigned short bit12:1;
    };
    Bits* bits=(Bits*)record;
    if(mode>0) {
        if(mode==1) {
            if(bits->bit12)return 1;
        } else {
            if(bits->bit11)return 1;
        }
    } else if(value==bits->value)return 1;
    return 0;
}
