// Original: arm9/ov031 @ 0x0223CBBC; symbol: func_ov031_0223cbbc; size: 0x5C.
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned engine,unsigned mask) {
    if(engine==1){
        volatile unsigned* reg=(volatile unsigned*)0x04001000;
        unsigned planes=(*reg&0x1f00)>>8;
        *reg=(*reg&~0x1f00)|((planes&~mask)<<8);
    }else{
        volatile unsigned* reg=(volatile unsigned*)0x04000000;
        unsigned planes=(*reg&0x1f00)>>8;
        *reg=(*reg&~0x1f00)|((planes&~mask)<<8);
    }
}
