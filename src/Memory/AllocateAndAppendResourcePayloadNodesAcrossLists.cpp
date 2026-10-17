#include "Memory/SignedAllocator.h"
// Lists use signatureLength=4, so each allocated node is payload, prev, next.
struct ResourceNode { unsigned char* payload; ResourceNode* previous; ResourceNode* next; };
struct ResourceContext { void* allocator; unsigned unknown04; SignedAllocatorList triple0[3], triple1[3], triple2[3]; SignedAllocatorList single; SignedAllocatorList three[3]; SignedAllocatorList fourth; SignedAllocatorList pairs8[2], pairs16[2]; SignedAllocatorList twelve; SignedAllocatorList final[4]; SignedAllocatorList large; };
struct LargeResource { void* nested; unsigned char* values; unsigned unknown08; unsigned short count; };
struct ResourceTriples { unsigned char* values[3][3]; unsigned char counts[3][3]; };
struct ResourceSingle { unsigned char* values; unsigned char count; };
struct ResourceThreeAndOne { unsigned char* values[3]; unsigned char* fourth; unsigned char counts[3]; unsigned char fourthCount; };
struct ResourcePairs { unsigned char* values[2]; unsigned char counts[2]; };
struct ResourceTwelve { unsigned unknown00; unsigned char* values; unsigned char count; };
struct ResourceFour { unsigned char* values[4]; unsigned char counts[4]; };
extern "C" {
int Object_AllocateAndClearTwelveByteSecondaryRecord(ResourceNode**, void*);
int Memory_AllocateAndClearThreeWordRecord(ResourceNode**, void*);
int AllocateAndClearThreeWords(ResourceNode**, void*);
int Object_AllocateAndClearTwelveBytePrimaryRecord(ResourceNode**, void*);
LargeResource* Object_ReadInitialOptionalResourceWord(ResourceContext*);
ResourceTriples* ReadResolvedRecordWord4OrZero(ResourceContext*);
ResourceSingle* ReadResolvedRecordWordTwoOrZero(ResourceContext*);
ResourceThreeAndOne* Object_ReadOptionalResourceWordC(ResourceContext*);
ResourcePairs* Object_ReadOptionalResourceWord18(ResourceContext*);
ResourcePairs* ReadResolvedRecordWord1COrZero(ResourceContext*);
ResourceTwelve* ReadResolvedRecordWordField20OrZero(ResourceContext*);
ResourceFour* Object_ReadOptionalResolvedValue(ResourceContext*);
}
// Original: arm9/main @ 0x020546C8; symbol: func_020546c8; size: 0x7A8.
extern "C" void AllocateAndAppendResourcePayloadNodesAcrossLists(ResourceContext* context) {
    ResourceNode* node0; ResourceNode* node1; ResourceNode* node2; ResourceNode* node3;
    ResourceNode* node4; ResourceNode* node5; ResourceNode* node6; ResourceNode* node7;
    ResourceNode* node8; ResourceNode* node9; ResourceNode* node10;
    LargeResource* large = Object_ReadInitialOptionalResourceWord(context);
    if (large) {
        if (large->count != 0) {
            node0 = 0;
            if (Object_AllocateAndClearTwelveByteSecondaryRecord(&node0, context->allocator)) {
                context->large.InsertAtEnd((SignedAllocatorHeader*)node0);
                node0->payload = large->values;
                for (int index = 1; index < large->count; ++index) {
                    node0 = 0;
                    if (Object_AllocateAndClearTwelveByteSecondaryRecord(&node0, context->allocator)) {
                        context->large.InsertAtEnd((SignedAllocatorHeader*)node0);
                        node0->payload = large->values + index * 28;
                    }
                }
            }
        }
    }
    ResourceTriples* triples = ReadResolvedRecordWord4OrZero(context);
    if (triples) {
        for (int group = 0; group < 3; ++group) {
            if (triples->counts[0][group] != 0) {
                node1 = 0;
                if (Memory_AllocateAndClearThreeWordRecord(&node1, context->allocator)) {
                    context->triple0[group].InsertAtEnd((SignedAllocatorHeader*)node1);
                    node1->payload = triples->values[0][group];
                    for (int index = 1; index < triples->counts[0][group]; ++index) {
                        node1 = 0;
                        if (Memory_AllocateAndClearThreeWordRecord(&node1, context->allocator)) {
                            context->triple0[group].InsertAtEnd((SignedAllocatorHeader*)node1);
                            node1->payload = triples->values[0][group] + index * 8;
                        }
                    }
                }
            }
            if (triples->counts[1][group] != 0) {
                node2 = 0;
                if (Memory_AllocateAndClearThreeWordRecord(&node2, context->allocator)) {
                    context->triple1[group].InsertAtEnd((SignedAllocatorHeader*)node2);
                    node2->payload = triples->values[1][group];
                    for (int index = 1; index < triples->counts[1][group]; ++index) {
                        node2 = 0;
                        if (Memory_AllocateAndClearThreeWordRecord(&node2, context->allocator)) {
                            context->triple1[group].InsertAtEnd((SignedAllocatorHeader*)node2);
                            node2->payload = triples->values[1][group] + index * 8;
                        }
                    }
                }
            }
            if (triples->counts[2][group] != 0) {
                node3 = 0;
                if (Memory_AllocateAndClearThreeWordRecord(&node3, context->allocator)) {
                    context->triple2[group].InsertAtEnd((SignedAllocatorHeader*)node3);
                    node3->payload = triples->values[2][group];
                    for (int index = 1; index < triples->counts[2][group]; ++index) {
                        node3 = 0;
                        if (Memory_AllocateAndClearThreeWordRecord(&node3, context->allocator)) {
                            context->triple2[group].InsertAtEnd((SignedAllocatorHeader*)node3);
                            node3->payload = triples->values[2][group] + index * 8;
                        }
                    }
                }
            }
        }
    }
    ResourceSingle* single = ReadResolvedRecordWordTwoOrZero(context);
    if (single) {
        if (single->count != 0) {
            node4 = 0;
            if (Memory_AllocateAndClearThreeWordRecord(&node4, context->allocator)) {
                context->single.InsertAtEnd((SignedAllocatorHeader*)node4);
                node4->payload = single->values;
                for (int index = 1; index < single->count; ++index) {
                    node4 = 0;
                    if (Memory_AllocateAndClearThreeWordRecord(&node4, context->allocator)) {
                        context->single.InsertAtEnd((SignedAllocatorHeader*)node4);
                        node4->payload = single->values + index * 8;
                    }
                }
            }
        }
    }
    ResourceThreeAndOne* four = Object_ReadOptionalResourceWordC(context);
    if (four) {
        for (int group = 0; group < 3; ++group) {
            if (four->counts[group] != 0) {
                node5 = 0;
                if (Memory_AllocateAndClearThreeWordRecord(&node5, context->allocator)) {
                    context->three[group].InsertAtEnd((SignedAllocatorHeader*)node5);
                    node5->payload = four->values[group];
                    for (int index = 1; index < four->counts[group]; ++index) {
                        node5 = 0;
                        if (Memory_AllocateAndClearThreeWordRecord(&node5, context->allocator)) {
                            context->three[group].InsertAtEnd((SignedAllocatorHeader*)node5);
                            node5->payload = four->values[group] + index * 8;
                        }
                    }
                }
            }
        }
        if (four->fourthCount != 0) {
            node6 = 0;
            if (AllocateAndClearThreeWords(&node6, context->allocator)) {
                context->fourth.InsertAtEnd((SignedAllocatorHeader*)node6);
                node6->payload = four->fourth;
                for (int index = 1; index < four->fourthCount; ++index) {
                    node6 = 0;
                    if (AllocateAndClearThreeWords(&node6, context->allocator)) {
                        context->fourth.InsertAtEnd((SignedAllocatorHeader*)node6);
                        node6->payload = four->fourth + index * 16;
                    }
                }
            }
        }
    }
    ResourcePairs* pairs7 = Object_ReadOptionalResourceWord18(context);
    if (pairs7) {
        for (int group = 0; group < 2; ++group) {
            if (pairs7->counts[group] != 0) {
                node7 = 0;
                if (Memory_AllocateAndClearThreeWordRecord(&node7, context->allocator)) {
                    context->pairs8[group].InsertAtEnd((SignedAllocatorHeader*)node7);
                    node7->payload = pairs7->values[group];
                    for (int index = 1; index < pairs7->counts[group]; ++index) {
                        node7 = 0;
                        if (Memory_AllocateAndClearThreeWordRecord(&node7, context->allocator)) {
                            context->pairs8[group].InsertAtEnd((SignedAllocatorHeader*)node7);
                            node7->payload = pairs7->values[group] + index * 8;
                        }
                    }
                }
            }
        }
    }
    ResourcePairs* pairs8 = ReadResolvedRecordWord1COrZero(context);
    if (pairs8) {
        for (int group = 0; group < 2; ++group) {
            if (pairs8->counts[group] != 0) {
                node8 = 0;
                if (AllocateAndClearThreeWords(&node8, context->allocator)) {
                    context->pairs16[group].InsertAtEnd((SignedAllocatorHeader*)node8);
                    node8->payload = pairs8->values[group];
                    for (int index = 1; index < pairs8->counts[group]; ++index) {
                        node8 = 0;
                        if (AllocateAndClearThreeWords(&node8, context->allocator)) {
                            context->pairs16[group].InsertAtEnd((SignedAllocatorHeader*)node8);
                            node8->payload = pairs8->values[group] + index * 16;
                        }
                    }
                }
            }
        }
    }
    ResourceTwelve* twelve = ReadResolvedRecordWordField20OrZero(context);
    if (twelve) {
        if (twelve->count != 0) {
            node9 = 0;
            if (Object_AllocateAndClearTwelveBytePrimaryRecord(&node9, context->allocator)) {
                context->twelve.InsertAtEnd((SignedAllocatorHeader*)node9);
                node9->payload = twelve->values;
                for (int index = 1; index < twelve->count; ++index) {
                    node9 = 0;
                    if (Object_AllocateAndClearTwelveBytePrimaryRecord(&node9, context->allocator)) {
                        context->twelve.InsertAtEnd((SignedAllocatorHeader*)node9);
                        node9->payload = twelve->values + index * 12;
                    }
                }
            }
        }
    }
    ResourceFour* final = Object_ReadOptionalResolvedValue(context);
    if (final) {
        for (int group = 0; group < 4; ++group) {
            if (final->counts[group] != 0) {
                node10 = 0;
                if (Memory_AllocateAndClearThreeWordRecord(&node10, context->allocator)) {
                    context->final[group].InsertAtEnd((SignedAllocatorHeader*)node10);
                    node10->payload = final->values[group];
                    for (int index = 1; index < final->counts[group]; ++index) {
                        node10 = 0;
                        if (Memory_AllocateAndClearThreeWordRecord(&node10, context->allocator)) {
                            context->final[group].InsertAtEnd((SignedAllocatorHeader*)node10);
                            node10->payload = final->values[group] + index * 8;
                        }
                    }
                }
            }
        }
    }
}
