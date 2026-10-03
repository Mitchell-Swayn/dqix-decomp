#include "GameState/GameState.h"

// Layout inferred from this controller's lifecycle and dispatch routines.
// The resource lifecycle accesses flag_11 at offset 0x11 from its argument.
struct Ov23WidgetResource {
    unsigned char unknown_0[0x10];
    unsigned char flag_10, flag_11;
};

struct Ov23WidgetController {
    unsigned int unknown_0, unknown_4;
    Ov23WidgetResource resource;
    unsigned char padding_1a[2];
    unsigned int savedDisplayMode;
    unsigned char widgets[0xbc];
    unsigned int slots[4];
    int selection;
    unsigned char buffer_f0[0x14], buffer_104[0x14];
    unsigned char flag_118, flag_119, state, flag_11b;
    unsigned char flag_11c, flag_11d, flag_11e, padding_11f;
    unsigned int unknown_120;
    typedef void (Ov23WidgetController::*Handler)();
};
struct Ov23HandlerTable {
    Ov23WidgetController::Handler entries[4];
};
extern "C" {
void* memset(void*, int, unsigned int);
void func_02074b64(Ov23WidgetResource*);
void func_02074bf4(Ov23WidgetResource*);
void func_0205cfd4(void*);
int func_0205d67c(void*);
void func_0205d6a0(void*, int);
void func_0205d1e0(void*);
void func_0205d228(void*);
void func_0205d274(void*);
void func_0205d2bc(void*);
void func_0205d0e0(void*, unsigned int);
extern const Ov23HandlerTable data_ov023_021fd510;
extern const Ov23WidgetController::Handler data_020e6d5c;
}

extern "C" void func_ov023_021d8a40(Ov23WidgetController* self)
{
    self->resource.flag_10 = 0;
    self->resource.flag_11 = 0;
    func_02074b64(&self->resource);
    self->savedDisplayMode = (*(volatile unsigned int*)0x04001000 & 0x1f00) >> 8;
    self->unknown_0 = 0;
    self->unknown_4 = 0;
    func_0205cfd4(self->widgets);
    for (int i = 0; i < 4; ++i) self->slots[i] = 0;
    self->selection = -1;
    memset(self->buffer_f0, 0, 0x14);
    memset(self->buffer_104, 0, 0x14);
    self->flag_118 = 0;
    self->flag_119 = 0;
    self->state = 0;
    self->flag_11b = 0;
    self->flag_11c = 0;
    self->flag_11d = 0;
    self->unknown_120 = 0;
    self->flag_11e = 0;
}

extern "C" void func_ov023_021d8af8(Ov23WidgetController* self)
{
    if (func_0205d67c(self->widgets)) func_0205d6a0(self->widgets, 1);
    self->unknown_0 = 0;
    *(volatile unsigned int*)0x04001000 = (*(volatile unsigned int*)0x04001000 & ~0x1f00) | (self->savedDisplayMode << 8);
    func_02074bf4(&self->resource);
    func_0205cfd4(self->widgets);
    self->state = 0;
    self->flag_11b = 0;
    self->flag_11c = 0;
    self->unknown_0 = 0;
    self->unknown_4 = 0;
}

extern "C" void func_ov023_021d8b6c(Ov23WidgetController* self)
{
    if (func_0205d67c(self->widgets)) func_0205d6a0(self->widgets, 1);
    func_0205d1e0(self->widgets);
    func_0205d228(self->widgets);
    func_0205d274(self->widgets);
    func_0205d2bc(self->widgets);
}

extern "C" int func_ov023_021d8bb4(Ov23WidgetController* self)
{
    unsigned int ticks = GameState::GetInstance()->GetTickCount();
    if (ticks == 0) ticks = 1;
    if (self->flag_11b == 255) func_0205d0e0(self->widgets, ticks);
    Ov23HandlerTable handlers = data_ov023_021fd510;
    handlers.entries[3] = data_020e6d5c;
    if (!handlers.entries[self->state]) return 0;
    (self->*handlers.entries[self->state])();
    return 0;
}

extern "C" void func_ov023_021d8c60(Ov23WidgetController* self)
{
    if (self->state == 0 || self->state == 3) return;
    func_0205d1e0(self->widgets);
    func_0205d228(self->widgets);
    func_0205d274(self->widgets);
}

extern "C" void func_ov023_021d8c94(Ov23WidgetController* self)
{
    if (self->state == 0 || self->state == 3) return;
    func_0205d2bc(self->widgets);
}
