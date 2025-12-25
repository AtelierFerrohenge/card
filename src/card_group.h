#pragma once

#include "godot_cpp/classes/node.hpp"

// Review if this is the right way to include used custom classes
#include "card.h"

using namespace godot;

class CardGroup : public Node {
    GDCLASS(CardGroup, Node)

public:
    CardGroup() = default;
    ~CardGroup() override = default;

    void transfer_card(Card *p_card);
    bool is_empty();
    Card *get_random_card();
    void erase_card(Card *p_card);

protected:
    static void _bind_methods();
};
