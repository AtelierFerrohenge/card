#pragma once

#include "card_stack.h"

// Review if this is the right way to include used custom classes
#include "card.h"

using namespace godot;

class CardDeck : public CardStack {
    GDCLASS(CardDeck, CardStack)

public:
    CardDeck();
    // Might need a destructor for bottom, middle, top to prevent memory leaks
    // Review how child node destruction works
    ~CardDeck() override = default;

    virtual void transfer_card(Card *p_card) override;
    virtual int get_card_count() const override;
    virtual Card *get_random_card() const override;
    virtual void erase_card(Card *p_card) override;

    virtual void transfer_card_to_top(Card *p_card) override;
    virtual void transfer_card_to_bottom(Card *p_card) override;
    virtual Card *get_top_card() const override;
    virtual Card *get_bottom_card() const override;

    void shuffle();
    void draw_card(CardGroup *p_card_group);

protected:
    static void _bind_methods();

private:
    CardStack *bottom = nullptr;
    CardGroup *middle = nullptr;
    CardStack *top = nullptr;
};
