#include <globaldefs.h>
ARM
extern "C" void InitializeTypeFourStateAndBuffers(void*, int);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_GetProgressChapter(void*);
extern "C" int GameState_ReadUnknown5cb4(void*);
extern "C" void* memcpy(void*, const void*, unsigned);
extern "C" void* memset(void*, int, unsigned);
extern "C" unsigned char FieldEvent_InitializeLuidaScriptRequest_TextEvluidaStb[];
extern "C" unsigned char FieldEvent_InitializeLuidaScriptRequest_TextF12Ev3D[];
// Original: arm9/ov017 @ 0x021BBAE4; symbol: InitializeObjectRecordFromGameState; size: 0x100.
// Initializes a compact object record from game-state values, supplied bytes and overlay defaults.
extern "C" void FieldEvent_InitializeLuidaScriptRequest(void* self, const unsigned char* input, unsigned char value) {
    unsigned char* bytes = (unsigned char*)self;
    if (bytes[2] != 0) return;
    InitializeTypeFourStateAndBuffers(self, 1);
    bytes[0xcc] = value;
    void* state = _ZN9GameState11GetInstanceEv();
    bytes[0x0c] = (unsigned char)GameState_GetProgressChapter(state);
    bytes[0x0e] = (unsigned char)GameState_GetProgressChapter(state);
    bytes[0x0d] = (unsigned char)GameState_ReadUnknown5cb4(state);
    bytes[0x0f] = (unsigned char)GameState_ReadUnknown5cb4(state);
    *(unsigned short*)(bytes + 0x16) = 1;
    bytes[0x10] = 1;
    bytes[0x11] = 0;
    *(unsigned short*)(bytes + 0x1a) = *(const unsigned short*)input;
    memcpy(bytes + 0x1e, input + 5, 7);
    memcpy(bytes + 0x3e, FieldEvent_InitializeLuidaScriptRequest_TextEvluidaStb, 12);
    *(unsigned short*)(bytes + 0x4a) = 100;
    *(unsigned short*)(bytes + 0x4c) = 200;
    *(unsigned short*)(bytes + 0x4e) = 300;
    *(unsigned short*)(bytes + 0x50) = 16;
    *(short*)(bytes + 0x52) = 16 - 17;
    bytes[0x12] = 0;
    memset(bytes + 0x54, 0, 12);
    *(unsigned short*)(bytes + 0x60) = 0;
    bytes[0x13] = 1;
    memcpy(bytes + 0x62, FieldEvent_InitializeLuidaScriptRequest_TextF12Ev3D, 7);
}
