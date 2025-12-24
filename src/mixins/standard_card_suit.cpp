#include "standard_card_suit.h"

StandardCardSuit::StandardCardSuit() {
    set_local_to_scene(true);
}

void StandardCardSuit::set_suit(Suit p_suit) {
    suit = p_suit;
    emit_signal("suit_changed", suit);
}

StandardCardSuit::Suit StandardCardSuit::get_suit() const {
    return suit;
}

void StandardCardSuit::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_suit", "suit"), &StandardCardSuit::set_suit);
    ClassDB::bind_method(D_METHOD("get_suit"), &StandardCardSuit::get_suit);

    ADD_SIGNAL(MethodInfo("suit_changed", PropertyInfo(Variant::INT, "changed_suit")));

    ADD_PROPERTY(PropertyInfo(Variant::INT, "suit", PROPERTY_HINT_ENUM, "Spade,Heart,Club,Diamond"), "set_suit", "get_suit");

    BIND_ENUM_CONSTANT(SUIT_SPADE);
    BIND_ENUM_CONSTANT(SUIT_HEART);
    BIND_ENUM_CONSTANT(SUIT_CLUB);
    BIND_ENUM_CONSTANT(SUIT_DIAMOND);
}