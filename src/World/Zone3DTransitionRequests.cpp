#include "World/Zone3D.h"

// Request 0 dispatches through the grotto state. The meanings of its three
// payload values, and requests 1 and 2, remain unresolved.
// Original: arm9/main @ 0x0201BF38; symbol: _ZN6Zone3D26SetGrottoTransitionRequestEbhht; size: 0x38.
void Zone3D::SetGrottoTransitionRequest(bool enabled, unsigned char first, unsigned char second, unsigned short third)
{
    SetTransitionRequest(0, enabled);
    transitionParameter1_ = first;
    transitionParameter2_ = second;
    transitionParameter3_ = third;
}

// Original: arm9/main @ 0x0201BF70; symbol: _ZN6Zone3D21SetTransitionRequest1Eb; size: 0x14.
void Zone3D::SetTransitionRequest1(bool enabled) { SetTransitionRequest(1, enabled); }
// Original: arm9/main @ 0x0201BF84; symbol: _ZN6Zone3D21SetTransitionRequest2Eb; size: 0x14.
void Zone3D::SetTransitionRequest2(bool enabled) { SetTransitionRequest(2, enabled); }

// Original: arm9/main @ 0x0201BF98; symbol: _ZN6Zone3D20SetTransitionRequestEib; size: 0x28.
void Zone3D::SetTransitionRequest(int index, bool enabled)
{
    if (enabled) transitionRequests_ |= 1 << index;
    else transitionRequests_ &= ~(1 << index);
}

// Original: arm9/main @ 0x0201BFC0; symbol: _ZN6Zone3D20GetTransitionRequestEi; size: 0x14.
int Zone3D::GetTransitionRequest(int index)
{
    return transitionRequests_ & (1 << index);
}
