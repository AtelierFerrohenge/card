#pragma once

#include "card_group.h"

// Review if this is the right way to include used custom classes
#include "card.h"

using namespace godot;

class CardStack : public CardGroup {
    GDCLASS(CardStack, CardGroup)

public:
    CardStack() = default;
    ~CardStack() override = default;

    void transfer_card_to_top(Card *p_card);
    void transfer_card_to_bottom(Card *p_card);
    Card *get_top_card();
    Card *get_bottom_card();

protected:
    static void _bind_methods();
};
