#pragma thumb off
// Field layout is established by instructions; object semantics remain uncertain.
struct Node {
    char pad[32];
    Node* next;
};
struct Owner {
    char pad[9];
    unsigned char count;
    char gap[10];
    Node* first;
};
// Original: arm9/ov000 @ 0x021600CC; symbol: func_ov000_021600cc; size: 0x2c.
extern "C" void Combat_AppendActionTargetRecord(Owner* obj,Node* node) {
    Node** slot=&obj->first;
    while(*slot)slot=&(*slot)->next;
    *slot=node;
    obj->count++;
}
