#include "card_group.h"

void CardGroup::transfer_card(Card *p_card) {
    // Review if get_parent() called on the card is the best way to transfer
    if(p_card->get_parent() == nullptr) {
        add_child(p_card);
    } else {
        p_card->reparent(this);
    }
}

void CardGroup::erase_card(Card *p_card) {
    remove_child(p_card);
}

void CardGroup::_bind_methods() {
    ClassDB::bind_method(D_METHOD("transfer_card", "card"), &CardGroup::transfer_card);
    ClassDB::bind_method(D_METHOD("erase_card", "card"), &CardGroup::erase_card);
}