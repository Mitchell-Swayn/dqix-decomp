#pragma once

// Observed 12-byte linked record: signed key, packed selector, opaque word, next.
struct WorldScriptRecordNode
{
    short key;
    unsigned short selector;
    unsigned int opaque4;
    WorldScriptRecordNode* next;
};
