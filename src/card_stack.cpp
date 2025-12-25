#include "card_stack.h"

void CardStack::transfer_card_to_top(Card *p_card) {
    // Research if there's a better way to alias
    transfer_card(p_card);
}

void CardStack::transfer_card_to_bottom(Card *p_card) {
    transfer_card(p_card);
    move_child(p_card, 0);
}

Card *CardStack::get_top_card() {
    // Review if (Card *) is the best way to cast this
    return is_empty() ? nullptr : (Card *)get_child(-1);
}

Card *CardStack::get_bottom_card() {
    // Review if (Card *) is the best way to cast this
    return is_empty() ? nullptr : (Card *)get_child(0);
}

void CardStack::_bind_methods() {
    ClassDB::bind_method(D_METHOD("transfer_card_to_top", "card"), &CardStack::transfer_card_to_top);
    ClassDB::bind_method(D_METHOD("transfer_card_to_bottom", "card"), &CardStack::transfer_card_to_bottom);
    ClassDB::bind_method(D_METHOD("get_top_card"), &CardStack::get_top_card);
    ClassDB::bind_method(D_METHOD("get_bottom_card"), &CardStack::get_bottom_card);
}