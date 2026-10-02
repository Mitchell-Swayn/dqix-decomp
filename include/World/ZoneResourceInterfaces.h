#pragma once

class GameState;
struct Zone3D_StructPtr_8;

#if defined(jpn)
#define func_02011584 func_020112f4
#define func_02099950 func_0209b684
#define func_0207df50 func_0207ecd0
#endif

// Opaque shared interfaces; callers may use partial views of the returned data.
extern "C" {
    void* func_02011584(GameState*);
    Zone3D_StructPtr_8* func_02099950(void*, unsigned short);
    void* func_0207df50(void*);
}
