#include "standard_card_suit.h"

void StandardCardSuit::set_suit(Suit p_suit) {
    suit = p_suit;
    // Consider standardizing this into a function
    emit_signal("value_changed", suit);
}

StandardCardSuit::Suit StandardCardSuit::get_suit() const {
    return suit;
}

void StandardCardSuit::init_signals(Callable p_callable) {
    connect("value_changed", p_callable);
    // Consider standardizing this into a function
    emit_signal("value_changed", suit);
}

void StandardCardSuit::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_suit", "p_suit"), &StandardCardSuit::set_suit);
    ClassDB::bind_method(D_METHOD("get_suit"), &StandardCardSuit::get_suit);
    ClassDB::bind_method(D_METHOD("init_signals", "p_callable"), &StandardCardSuit::init_signals);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "suit", PROPERTY_HINT_ENUM, "Spade,Heart,Club,Diamond"), "set_suit", "get_suit");

    BIND_ENUM_CONSTANT(SUIT_SPADE);
    BIND_ENUM_CONSTANT(SUIT_HEART);
    BIND_ENUM_CONSTANT(SUIT_CLUB);
    BIND_ENUM_CONSTANT(SUIT_DIAMOND);
}