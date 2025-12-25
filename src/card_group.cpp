#include "card_group.h"

void CardGroup::transfer_card(Card *p_card) {
    // Review if get_parent() called on the card is the best way to transfer
    if(p_card->get_parent() == nullptr) {
        add_child(p_card);
    } else {
        p_card->reparent(this);
    }
}

bool CardGroup::is_empty() {
    return get_child_count() == 0;
}

Card *CardGroup::get_random_card() {
    // Review if (Card *) is the best way to cast this
    return is_empty() ? nullptr : (Card *)get_child(UtilityFunctions::randi() % get_child_count());
}

// This doesn't actually delete the card, so may need to implement that later
void CardGroup::erase_card(Card *p_card) {
    remove_child(p_card);
}

void CardGroup::_bind_methods() {
    ClassDB::bind_method(D_METHOD("transfer_card", "card"), &CardGroup::transfer_card);
    ClassDB::bind_method(D_METHOD("is_empty"), &CardGroup::is_empty);
    ClassDB::bind_method(D_METHOD("get_random_card"), &CardGroup::get_random_card);
    ClassDB::bind_method(D_METHOD("erase_card", "card"), &CardGroup::erase_card);
}