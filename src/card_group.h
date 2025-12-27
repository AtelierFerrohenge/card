#pragma once

#include "godot_cpp/classes/node.hpp"

#include <godot_cpp/core/gdvirtual.gen.inc>

// Review if this is the right way to include used custom classes
#include "card.h"

using namespace godot;

class CardGroup : public Node {
    GDCLASS(CardGroup, Node)

public:
    CardGroup() = default;
    ~CardGroup() override = default;

    virtual void transfer_card(Card *p_card);
    virtual int get_card_count() const;
    virtual Card *get_random_card() const;
    virtual void erase_card(Card *p_card);

    bool is_empty() const;

protected:
    static void _bind_methods();

    GDVIRTUAL1(_transfer_card, Card *)
    GDVIRTUAL0RC(int, _get_card_count)
    GDVIRTUAL0RC(Card *, _get_random_card)
    GDVIRTUAL1(_erase_card, Card *)
};
