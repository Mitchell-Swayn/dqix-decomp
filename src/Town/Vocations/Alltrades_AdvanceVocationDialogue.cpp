#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
#pragma scheduling off
struct Bits {
    unsigned a : 6, b : 6, c : 6, d : 6, e : 2, f : 1, g : 1, h : 1, pad : 1, i : 1, rest : 1;
};
struct Record {
    unsigned x, y;
    Bits flags;
};
struct Buffer {
    char pad[0x4ac];
    char names[16][64];
};
extern "C" {
unsigned int TextContext_GetSharedInstance();
void Graphics_ClearAndStageSharedBuffers(char* p);
void TextWindow_ResetGlyphBuffersAndFrameContexts(void* p);
void TextWindow_StartFormattedMessage(void*, unsigned, unsigned, unsigned);
void TextLayout_ResetFormattingWorkspace(signed char* object);
void TextContext_SetStringArgument(Buffer* p, int i, const char* s);
void* ResourceStringTable_GetTextByKey(void* a, void* b);
void Text_InitializeNameDescriptor(Record* p, unsigned x, unsigned y, unsigned a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char f, unsigned char g, unsigned char h, unsigned char i);
void GameState_BuildTwelveByteDescriptorForPartyMember(void* out, int index);
int Alltrades_IsVocationPreviewReady(unsigned char* p);
void* Alltrades_GetSelectedVocation(void* object);
}

// Original: arm9/ov003 @ 0x021552B8; symbol: func_ov003_021552b8; size: 0x2C8.
// Advances Alltrades vocation dialogue: remaps stored message keys, fills
// selected/current vocation name arguments, then waits on the text window.
extern "C" void Alltrades_AdvanceVocationDialogue(unsigned char* self)
{
    unsigned int shared = TextContext_GetSharedInstance();
    Buffer* context = (Buffer*)shared;
    unsigned char phase = self[0x1fa];
    if (phase == 0) {
        int flags = *(int*)(self + 0x1fc);
        short message = *(short*)(self + 0x1ec);
        if (flags & 1) {
            switch (message) {
            case 6:
                message = 0x1b;
                break;
            case 7:
                message = 0x1c;
                break;
            case 8:
                message = 0x1d;
                break;
            case 9:
                message = 0x1e;
                break;
            case 10:
                message = 0x1f;
                break;
            case 11:
                message = 0x20;
                break;
            case 12:
                message = 0x21;
                break;
            case 13:
                message = 0x22;
                break;
            case 0x30:
                message = 0x32;
                break;
            case 0x31:
                message = 0x33;
                break;
            }
            *(short*)(self + 0x1ec) = message;
        }
        TextLayout_ResetFormattingWorkspace((signed char*)shared);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(*(signed char*)(self + 0x1f7));
        int currentVocation = 0;
        if (member)
            currentVocation = *(int*)(*(unsigned char**)((unsigned char*)member + 0x150) + 0x950);
        void* selectedKey = (void*)(int)(short)((int)Alltrades_GetSelectedVocation(self) + 0x23);
        void* selectedName = ResourceStringTable_GetTextByKey(self + 0xe4, selectedKey);
        void* currentName = ResourceStringTable_GetTextByKey(self + 0xe4, (void*)(int)(short)(currentVocation + 0x23));
        unsigned char partyDesc[12];
        GameState_BuildTwelveByteDescriptorForPartyMember(partyDesc, *(signed char*)(self + 0x1f7));
        *(void**)shared = partyDesc;
        *(void**)((char*)shared + 0x10) = partyDesc;
        unsigned name = (unsigned)selectedName;
        if (message == 0x10 || message == 0x13 || message == 0x16)
            name = (unsigned)currentName;
        Record nameDesc;
        Text_InitializeNameDescriptor(&nameDesc, name, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        *(Record**)((char*)shared + 0x28) = &nameDesc;
        TextContext_SetStringArgument(context, 1, (const char*)selectedName);
        TextContext_SetStringArgument(context, 2, (const char*)currentName);
        void* extraName = ResourceStringTable_GetTextByKey(self + 0xe4, (void*)(int)(short)(currentVocation + 0x34));
        TextContext_SetStringArgument(context, 3, (const char*)extraName);
        void* text = ResourceStringTable_GetTextByKey(self + 0xe4, (void*)(int)(short)message);
        TextWindow_StartFormattedMessage((void*)shared, (unsigned)text, 0, 0xe3);
        *(int*)((char*)shared + 0x998) = 1;
        *(int*)((char*)shared + 0x99c) = 1;
        self[0x1fa] = (unsigned char)(self[0x1fa] + 1);
    } else if (phase == 1) {
        if (*(int*)((char*)shared + 0x998) == 0) {
            *(short*)(self + 0x1ec) = *(short*)(self + 0x1ee);
            *(short*)(self + 0x1ee) = -1;
            self[0x1f8] = 7;
            self[0x1fa] = 0;
            if (!Alltrades_IsVocationPreviewReady(*(unsigned char**)(self + 4))) {
                self[0x1f8] = 5;
                self[0x1f9] = 0;
            }
        } else if (*(int*)((char*)shared + 0x9a0) == 3) {
            *(short*)(self + 0x1ec) = *(short*)(self + 0x1ee);
            *(short*)(self + 0x1ee) = -1;
            if (*(short*)(self + 0x1ec) < 0) {
                if (*(int*)(self + 0x1fc) & 2) {
                    TextWindow_ResetGlyphBuffersAndFrameContexts((void*)shared);
                    Graphics_ClearAndStageSharedBuffers((char*)shared);
                    *(int*)(self + 0x1fc) = *(int*)(self + 0x1fc) & ~2;
                }
            }
            self[0x1fa] = 0;
        }
    }
}
