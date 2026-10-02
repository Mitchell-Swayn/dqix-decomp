#include "Graphics/NSBXX/RenderCommands_Common.h"

void RenderCommand_0(RenderCommandHandler*, int);
void RenderCommand_1(RenderCommandHandler*, int);
void RenderCommand_2(RenderCommandHandler*, int);
void RenderCommand_3(RenderCommandHandler*, int);
void RenderCommand_4(RenderCommandHandler*, int);
void RenderCommand_5(RenderCommandHandler*, int);
void RenderCommand_6(RenderCommandHandler*, int);
void RenderCommand_7(RenderCommandHandler*, int);
void RenderCommand_8(RenderCommandHandler*, int);
void RenderCommand_9(RenderCommandHandler*, int);
void RenderCommand_10(RenderCommandHandler*, int);
void RenderCommand_11(RenderCommandHandler*, int);
void RenderCommand_12(RenderCommandHandler*, int);
void RenderCommand_13(RenderCommandHandler*, int);

// The dispatcher masks opcodes to five bits; slots 14..31 are null.
void (*data_020f1e08[32])(RenderCommandHandler*, int) = {
    RenderCommand_0,
    RenderCommand_1,
    RenderCommand_2,
    RenderCommand_3,
    RenderCommand_4,
    RenderCommand_5,
    RenderCommand_6,
    RenderCommand_7,
    RenderCommand_8,
    RenderCommand_9,
    RenderCommand_10,
    RenderCommand_11,
    RenderCommand_12,
    RenderCommand_13
};
typedef char RenderCommandDispatchSizeCheck[sizeof(data_020f1e08) == 128 ? 1 : -1];
