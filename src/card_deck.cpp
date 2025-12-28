#include "card_deck.h"

CardDeck::CardDeck() {
    bottom = memnew(CardStack);
    add_child(bottom);
    middle = memnew(CardGroup);
    add_child(middle);
    top = memnew(CardStack);
    add_child(top);
}

void CardDeck::transfer_card(Card *p_card) {
    if(GDVIRTUAL_CALL(_transfer_card, p_card)) {
        return;
    }

    middle->transfer_card(p_card);
}

int CardDeck::get_card_count() const {
    int count = 0;
    if(GDVIRTUAL_CALL(_get_card_count, count)) {
        return count;
    }

    return bottom->get_card_count() + middle->get_card_count() + top->get_card_count();
}

Card *CardDeck::get_random_card() const {
    Card *card = nullptr;
    if(GDVIRTUAL_CALL(_get_random_card, card)) {
        return card;
    }

    // To Do
    return nullptr;
}

// This doesn't actually delete the card, so may need to implement that later
void CardDeck::erase_card(Card *p_card) {
    if(GDVIRTUAL_CALL(_erase_card, p_card)) {
        return;
    }

    // To Do
}

void CardDeck::transfer_card_to_top(Card *p_card) {
    if(GDVIRTUAL_CALL(_transfer_card_to_top, p_card)) {
        return;
    }

    top->transfer_card_to_top(p_card);
}

void CardDeck::transfer_card_to_bottom(Card *p_card) {
    if(GDVIRTUAL_CALL(_transfer_card_to_bottom, p_card)) {
        return;
    }

    bottom->transfer_card_to_bottom(p_card);
}

Card *CardDeck::get_top_card() const {
    Card *card = nullptr;
    if(GDVIRTUAL_CALL(_get_top_card, card)) {
        return card;
    }

    // To Do
    return nullptr;
}

Card *CardDeck::get_bottom_card() const {
    Card *card = nullptr;
    if(GDVIRTUAL_CALL(_get_bottom_card, card)) {
        return card;
    }

    // To Do
    return nullptr;
}

void CardDeck::shuffle() {
    // To Do
}

void CardDeck::draw_card(CardGroup *p_card_group) {
    // To Do
}

void CardDeck::_bind_methods() {
    ClassDB::bind_method(D_METHOD("transfer_card", "card"), &CardDeck::transfer_card);
    ClassDB::bind_method(D_METHOD("get_card_count"), &CardDeck::get_card_count);
    ClassDB::bind_method(D_METHOD("get_random_card"), &CardDeck::get_random_card);
    ClassDB::bind_method(D_METHOD("erase_card", "card"), &CardDeck::erase_card);
    ClassDB::bind_method(D_METHOD("transfer_card_to_top", "card"), &CardDeck::transfer_card_to_top);
    ClassDB::bind_method(D_METHOD("transfer_card_to_bottom", "card"), &CardDeck::transfer_card_to_bottom);
    ClassDB::bind_method(D_METHOD("get_top_card"), &CardDeck::get_top_card);
    ClassDB::bind_method(D_METHOD("get_bottom_card"), &CardDeck::get_bottom_card);
    ClassDB::bind_method(D_METHOD("shuffle"), &CardDeck::shuffle);
    ClassDB::bind_method(D_METHOD("draw_card", "group"), &CardDeck::draw_card);
}