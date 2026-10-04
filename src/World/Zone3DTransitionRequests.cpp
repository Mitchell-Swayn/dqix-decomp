#include "World/Zone3D.h"

// Request 0 dispatches through the grotto state. The meanings of its three
// payload values, and requests 1 and 2, remain unresolved.
void Zone3D::SetGrottoTransitionRequest(bool enabled, unsigned char first, unsigned char second, unsigned short third)
{
    SetTransitionRequest(0, enabled);
    transitionParameter1_ = first;
    transitionParameter2_ = second;
    transitionParameter3_ = third;
}

void Zone3D::SetTransitionRequest1(bool enabled) { SetTransitionRequest(1, enabled); }
void Zone3D::SetTransitionRequest2(bool enabled) { SetTransitionRequest(2, enabled); }

void Zone3D::SetTransitionRequest(int index, bool enabled)
{
    if (enabled) transitionRequests_ |= 1 << index;
    else transitionRequests_ &= ~(1 << index);
}

int Zone3D::GetTransitionRequest(int index)
{
    return transitionRequests_ & (1 << index);
}
