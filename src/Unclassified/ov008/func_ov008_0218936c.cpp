extern "C" { void Object_UpdateDisplayRecordsAndPendingSelection(void*); void func_ov008_021895a8(void*); void func_ov008_02189c70(void*); void func_ov008_0218af80(void*); void func_ov008_02184754(void*); void func_ov008_0218b084(void*); }
// Original: arm9/ov008 @ 0x0218936C; symbol: func_ov008_0218936c; size: 0x98.
extern "C" unsigned func_ov008_0218936c(signed char* object) {
    Object_UpdateDisplayRecordsAndPendingSelection(object+0x18);
    switch(object[0xe99]) { case 0:func_ov008_021895a8(object);break;case 1:func_ov008_02189c70(object);break;case 2:object[0xe9a]=0;break; }
    switch(object[0xe9b]) { case 0:func_ov008_0218af80(object);break;case 1:func_ov008_02184754(object+0x2a8);break;case 2:func_ov008_0218b084(object);break; }
    return ((unsigned char*)object)[0xeb8];
}
