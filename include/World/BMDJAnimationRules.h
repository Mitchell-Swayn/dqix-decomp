#pragma once

class Animation3D;

struct ObjectAnimationRule
{
    unsigned int mask;
    int slot;
    char extension[8];
};
struct ObjectAnimationRules
{
    ObjectAnimationRule rules[6];
};
extern const ObjectAnimationRules data_020e6f48;

struct ModelAnimationRule
{
    unsigned int mask;
    char extension[8];
    Animation3D** destination;
    int unknown_10;
};
struct ModelAnimationRules
{
    ModelAnimationRule rules[5];
};
extern const ModelAnimationRules data_020e6fa8;

