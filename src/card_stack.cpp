#include "card_stack.h"

void CardStack::transfer_card_to_top(Card *p_card) {
    if(GDVIRTUAL_CALL(_transfer_card_to_top, p_card)) {
        return;
    }

    transfer_card(p_card);
}

void CardStack::transfer_card_to_bottom(Card *p_card) {
    if(GDVIRTUAL_CALL(_transfer_card_to_bottom, p_card)) {
        return;
    }

    transfer_card(p_card);
    move_child(p_card, 0);
}

Card *CardStack::get_top_card() const {
    Card *card = nullptr;
    if(GDVIRTUAL_CALL(_get_top_card, card)) {
        return card;
    }

    return is_empty() ? nullptr : cast_to<Card>(get_child(-1));
}

Card *CardStack::get_bottom_card() const {
    Card *card = nullptr;
    if(GDVIRTUAL_CALL(_get_bottom_card, card)) {
        return card;
    }

    return is_empty() ? nullptr : cast_to<Card>(get_child(0));
}

void CardStack::_bind_methods() {
    ClassDB::bind_method(D_METHOD("transfer_card_to_top", "card"), &CardStack::transfer_card_to_top);
    ClassDB::bind_method(D_METHOD("transfer_card_to_bottom", "card"), &CardStack::transfer_card_to_bottom);
    ClassDB::bind_method(D_METHOD("get_top_card"), &CardStack::get_top_card);
    ClassDB::bind_method(D_METHOD("get_bottom_card"), &CardStack::get_bottom_card);

    GDVIRTUAL_BIND(_transfer_card_to_top, "card");
    GDVIRTUAL_BIND(_transfer_card_to_bottom, "card");
    GDVIRTUAL_BIND(_get_top_card);
    GDVIRTUAL_BIND(_get_bottom_card);
}