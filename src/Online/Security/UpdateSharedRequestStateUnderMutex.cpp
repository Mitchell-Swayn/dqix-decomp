#include <globaldefs.h>
ARM
extern "C" void _Z9LockMutexP5Mutex(void*);
extern "C" void _Z11UnlockMutexP5Mutex(void*);
extern "C" void Ssl_SetCurrentSocketHandshakeTimeoutEnabled(int);
// Original: arm9/ov031 @ 0x022079AC; symbol: func_ov031_022079ac; size: 0x64.
extern "C" int UpdateSharedRequestStateUnderMutex(void* request) {
    unsigned char* owner = *(unsigned char**)((char*)request + 4);
    unsigned char* object = *(unsigned char**)(owner + 0x64);
    unsigned char* state = *(unsigned char**)(object + 0xc4);
    _Z9LockMutexP5Mutex(object + 0xe0);
    unsigned value = *(unsigned*)((char*)request + 0x10);
    if (value != 0) {
        *(unsigned*)(state + 0xc) = value;
        Ssl_SetCurrentSocketHandshakeTimeoutEnabled(1);
        owner[0x73] = 4;
    } else {
        owner[0x73] = 0;
        Ssl_SetCurrentSocketHandshakeTimeoutEnabled(0);
        *(unsigned*)(state + 0xc) = 0;
    }
    _Z11UnlockMutexP5Mutex(object + 0xe0);
    return 0;
}
