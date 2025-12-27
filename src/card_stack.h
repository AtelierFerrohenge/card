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

    virtual void transfer_card_to_top(Card *p_card);
    virtual void transfer_card_to_bottom(Card *p_card);
    virtual Card *get_top_card() const;
    virtual Card *get_bottom_card() const;

protected:
    static void _bind_methods();

    GDVIRTUAL1(_transfer_card_to_top, Card *)
    GDVIRTUAL1(_transfer_card_to_bottom, Card *)
    GDVIRTUAL0RC(Card *, _get_top_card)
    GDVIRTUAL0RC(Card *, _get_bottom_card)
};
