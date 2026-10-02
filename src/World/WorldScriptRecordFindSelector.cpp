// The lookup compares the six bits at positions 9..14; bit 15 is not interpreted.
struct WorldScriptSelectorNode
{
    short key;
    unsigned short selectorLow : 9, selector : 6, upperFlag : 1;
    void* opaque4;
    WorldScriptSelectorNode* next;
};

extern "C" WorldScriptSelectorNode* func_0208e024(
    WorldScriptSelectorNode** head, int selector, int occurrence)
{
    WorldScriptSelectorNode* node = *head;
    if (node == 0) return 0;
    unsigned char matches = 0;
    while (node != 0)
    {
        if (node->selector == selector)
        {
            if (matches == occurrence) return node;
            matches = (unsigned char)(matches + 1);
        }
        node = node->next;
    }
    return node;
}
