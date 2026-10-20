#include <globaldefs.h>
ARM
extern "C" unsigned TextContext_GetSharedInstance(void);
extern "C" void* memset(void*, int, unsigned);
extern "C" void Text_AppendIndexedObjectNames(char*, char*);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
// Original: arm9/ov000 @ 0x02177CB8; symbol: func_ov000_02177cb8; size: 0x4C.
extern "C" void GameState_BuildIndexedNameBufferAndLoadRecord(char* object) {
    unsigned char* buffer = *(unsigned char**)(TextContext_GetSharedInstance() + 0x5c);
    memset(buffer, 0, 0x960);
    Text_AppendIndexedObjectNames(object, (char*)buffer);
    Window_ReplaceCanvasTextById(object + 0x188, 5, buffer, 1, 0);
}
