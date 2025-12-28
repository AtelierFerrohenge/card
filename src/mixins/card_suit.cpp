#include "card_suit.h"

void CardSuit::set_suit(const StringName &p_suit) {
    suit = p_suit;
}

StringName CardSuit::get_suit() const {
    return suit;
}

void CardSuit::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_suit", "suit"), &CardSuit::set_suit);
    ClassDB::bind_method(D_METHOD("get_suit"), &CardSuit::get_suit);

    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "suit"), "set_suit", "get_suit");
}