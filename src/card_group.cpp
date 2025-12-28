#include "card_group.h"

void CardGroup::transfer_card(Card *p_card) {
    if(GDVIRTUAL_CALL(_transfer_card, p_card)) {
        return;
    }

    // Review if get_parent() called on the card is the best way to transfer
    if(p_card->get_parent() == nullptr) {
        add_child(p_card);
    } else {
        p_card->reparent(this);
    }
}

int CardGroup::get_card_count() const {
    int count = 0;
    if(GDVIRTUAL_CALL(_get_card_count, count)) {
        return count;
    }

    return get_child_count();
}

Card *CardGroup::get_random_card() const {
    Card *card = nullptr;
    if(GDVIRTUAL_CALL(_get_random_card, card)) {
        return card;
    }

    return is_empty() ? nullptr : cast_to<Card>(get_child(UtilityFunctions::randi() % get_child_count()));
}

// This doesn't actually delete the card, so may need to implement that later
void CardGroup::erase_card(Card *p_card) {
    if(GDVIRTUAL_CALL(_erase_card, p_card)) {
        return;
    }

    remove_child(p_card);
}

bool CardGroup::is_empty() const {
    return get_card_count() == 0;
}

void CardGroup::_bind_methods() {
    ClassDB::bind_method(D_METHOD("transfer_card", "card"), &CardGroup::transfer_card);
    ClassDB::bind_method(D_METHOD("get_card_count"), &CardGroup::get_card_count);
    ClassDB::bind_method(D_METHOD("get_random_card"), &CardGroup::get_random_card);
    ClassDB::bind_method(D_METHOD("erase_card", "card"), &CardGroup::erase_card);
    ClassDB::bind_method(D_METHOD("is_empty"), &CardGroup::is_empty);

    GDVIRTUAL_BIND(_transfer_card, "card");
    GDVIRTUAL_BIND(_get_card_count);
    GDVIRTUAL_BIND(_get_random_card);
    GDVIRTUAL_BIND(_erase_card, "card");
}