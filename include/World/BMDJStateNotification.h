#pragma once

// Partially known payload for zone-state notifications. Only the fields needed
// by each notification are initialized by its caller.
struct BMDJStateNotification
{
    int unknown_0[3];
    int zoneID;
    int unknown_10[3];
    short groupID;
    short instanceID;
    int unknown_20[2];
    short angle;
    char unknown_2a[10];
};
