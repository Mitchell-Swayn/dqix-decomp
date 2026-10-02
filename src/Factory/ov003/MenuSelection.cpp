#include "globaldefs.h"
#include "GameState/GameState.h"

// Partial views of existing objects. Unknown regions are not source-owned data.
struct SelectionMenu { char unknown00[0x36]; short selected; };
struct SelectionState {
    void* unknown00;
    void* controller;
    short* selection;
    char unknown0c[0x18-0x0c];
    SelectionMenu* menu;
    void* touchMenu;
    char unknown20[0x1dc-0x20];
    int cursorStyle;
    char unknown1e0[6];
    short page, previous, initial, message, nextMessage;
    char unknown1f0[7];
    signed char partyIndex;
    unsigned char state, phase, messagePhase, unknown1fb;
    unsigned int flags;
    int unknown200;
    void* alternateMenu;
};
struct TouchInput { char unknown00[0x55]; unsigned char active; };
struct TextArguments { const void* source; const void* alternate; unsigned int flags; };
struct MessageDisplay {
    TextArguments* arguments;
    char unknown04[12];
    TextArguments* alternateArguments;
    char unknown14[20];
    TextArguments* textArguments;
    char unknown2c[0x998-0x2c];
    int busy, mode, result;
};
struct PartyDetails { char unknown00[0x950]; int textIndex; };
struct PartyView { char unknown00[0x150]; PartyDetails* details; };

extern "C" {
extern char data_02114e30[];
extern TouchInput data_02114e54;
extern char data_02108760[];
void func_ov023_021eb4f4(void*);
void func_0207fd88(SelectionMenu*);
void func_020e2834(void*);
int func_02081da8(SelectionMenu*, short);
int func_0204c7e0();
int func_020e28dc(void*);
void func_020809c4(SelectionMenu*, short, short, short*, short*);
void func_020e263c(void*, int);
void func_020e28f0(void*, short, short);
void func_0205ae8c(void*);
int func_02012444(void*, unsigned int);
int func_020e2918(void*);
void func_02012a84(TouchInput*, int*, int*);
int func_02080dd4(SelectionMenu*, short, short, short, unsigned char*, int);
void func_020813ec(SelectionMenu*, short);
int func_020e2984(void*);
int func_02080d54(SelectionMenu*, short, short, short);
void func_0208203c(void*);
void func_0205eaa0(void*, int, int);
void func_02080c04(SelectionMenu*, short);
void func_020e29a8(void*, signed char);
void func_020e280c(void*, int);
MessageDisplay* func_020421a0();
void func_02046380(MessageDisplay*);
int func_ov003_02156034(SelectionState*);
const char* func_020e0434(void*, short);
void func_020e4bf4(TextArguments*, int);
void func_020e4b34(TextArguments*, const void*, const void*, int,
                 int, int, int, int, int, int, int, int);
void func_02046574(MessageDisplay*, int, const char*);
void func_0204500c(MessageDisplay*, const char*, int, int);
int func_ov003_021538e0(void*);
void func_02043204(MessageDisplay*);
void func_02043124(MessageDisplay*);

void func_ov003_02154fd0(SelectionState* s)
{
    if (!s->state) return;
    if (s->alternateMenu) func_ov023_021eb4f4(s->alternateMenu);
    else if (s->menu) func_0207fd88(s->menu);
    if (s->touchMenu) func_020e2834(s->touchMenu);
}

void func_ov003_0215501c(SelectionState* s)
{
    if (!s->selection || s->page < 0) return;
    if (!func_02081da8(s->menu, s->page)) return;
    if (!func_0204c7e0() || !s->touchMenu) return;
    if (func_020e28dc(s->touchMenu)) return;
    short x, y;
    func_020809c4(s->menu, s->page, *s->selection, &x, &y);
    func_020e263c(s->touchMenu, s->cursorStyle);
    x -= 16;
    y -= 3;
    func_020e28f0(s->touchMenu, x, y);
    func_0205ae8c((char*)s + 0x2c);
}

unsigned char func_ov003_021550dc(SelectionState* s)
{
    unsigned char confirm = 0;
    if (func_02012444(data_02114e30, 0x401)) confirm = 1;
    if (s->touchMenu && func_020e28dc(s->touchMenu)) {
        int selected = func_020e2918(s->touchMenu);
        if (selected >= 0) { confirm = 1; *s->selection = selected + 6; }
    } else if (data_02114e54.active && s->selection) {
        int x, y;
        SelectionMenu* menu = s->menu;
        func_02012a84(&data_02114e54, &x, &y);
        s->previous = *s->selection;
        int selected = func_02080dd4(menu, s->page, (short)x, (short)y, &confirm, 1);
        if (selected < 0) return 0;
        *s->selection = selected;
        if (s->previous != *s->selection) {
            menu->selected = *s->selection;
            func_020813ec(menu, s->page);
        }
    }
    return confirm;
}

int func_ov003_02155208(SelectionState* s)
{
    int cancel = 0;
    if (func_02012444(data_02114e30, 2)) cancel = 1;
    if (s->touchMenu && func_020e28dc(s->touchMenu)) {
        if (func_020e2984(s->touchMenu)) cancel = 1;
    } else if (data_02114e54.active) {
        int x, y;
        func_02012a84(&data_02114e54, &x, &y);
        if (!func_02080d54(s->menu, s->page, (short)x, (short)y)) cancel = 1;
    }
    return cancel;
}

void func_ov003_021552b8(SelectionState* s)
{
    MessageDisplay* display = func_020421a0();
    if (s->messagePhase == 0) {
        short message = s->message;
        if (s->flags & 1) {
            switch (message) {
            case 6: message = 27; break;
            case 7: message = 28; break;
            case 8: message = 29; break;
            case 9: message = 30; break;
            case 10: message = 31; break;
            case 11: message = 32; break;
            case 12: message = 33; break;
            case 13: message = 34; break;
            case 48: message = 50; break;
            case 49: message = 51; break;
            }
            s->message = message;
        }
        func_02046380(display);
        GameObject* member = GameState::GetInstance()->GetPartyMemberByIndex(s->partyIndex);
        int textIndex = 0;
        if (member) textIndex = ((PartyView*)member)->details->textIndex;
        short firstIndex = func_ov003_02156034(s) + 35;
        const char* first = func_020e0434((char*)s + 0xe4, (short)firstIndex);
        const char* second = func_020e0434((char*)s + 0xe4, (short)(textIndex + 35));
        TextArguments arguments;
        func_020e4bf4(&arguments, s->partyIndex);
        display->arguments = &arguments;
        display->alternateArguments = &arguments;
        const char* text = first;
        if (message == 16 || message == 19 || message == 22) text = second;
        TextArguments textArguments;
        func_020e4b34(&textArguments, text, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        display->textArguments = &textArguments;
        func_02046574(display, 1, first);
        func_02046574(display, 2, second);
        func_02046574(display, 3, func_020e0434((char*)s + 0xe4, (short)(textIndex + 52)));
        func_0204500c(display, func_020e0434((char*)s + 0xe4, message), 0, 227);
        display->busy = 1;
        display->mode = 1;
        ++s->messagePhase;
    } else if (s->messagePhase == 1) {
        if (!display->busy) {
            s->message = s->nextMessage;
            s->nextMessage = -1;
            s->state = 7;
            s->messagePhase = 0;
            if (!func_ov003_021538e0(s->controller)) { s->state = 5; s->phase = 0; }
        } else if (display->result == 3) {
            s->message = s->nextMessage;
            s->nextMessage = -1;
            if (s->message < 0 && (s->flags & 2)) {
                func_02043204(display);
                func_02043124(display);
                s->flags &= ~2;
            }
            s->messagePhase = 0;
        }
    }
}

void func_ov003_02155580(SelectionState* s, int mode)
{
    s->page = 1;
    s->previous = s->initial = 6;
    s->menu->selected = s->initial;
    func_020813ec(s->menu, s->page);
    func_0208203c((char*)s + 0x80);
    s->selection = 0;
    func_0205eaa0(data_02108760, 5, 0);
    if (s->touchMenu) {
        func_02080c04(s->menu, s->page);
        func_020e29a8(s->touchMenu, (signed char)mode);
        func_020e280c(s->touchMenu, -1);
    }
}
}
