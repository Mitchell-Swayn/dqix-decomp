#pragma once

struct WorldScriptArrayEntry
{
    short key;
    unsigned short unknown2;
    unsigned int unknown4;
    unsigned int unknown8;
    unsigned int unknownC;
    unsigned int unknown10;
    unsigned int unknown14;
};

struct WorldScriptArrayList
{
    WorldScriptArrayEntry* entries;
    short count;
    short capacity;
    unsigned int unknown8;
    unsigned short unknownC;
    unsigned short unknownE;
};

typedef char WorldScriptArrayEntrySizeCheck[
    sizeof(WorldScriptArrayEntry) == 24 ? 1 : -1];
typedef char WorldScriptArrayListSizeCheck[
    sizeof(WorldScriptArrayList) == 16 ? 1 : -1];
\n