#include "standard_playing_card.h"

void StandardPlayingCard::set_suit(Suit p_suit) {
    suit = p_suit;
    emit_signal("suit_changed", suit);
}

StandardPlayingCard::Suit StandardPlayingCard::get_suit() const {
    return suit;
}

void StandardPlayingCard::set_rank(Rank p_rank) {
    rank = p_rank;
    emit_signal("rank_changed", rank);
}

StandardPlayingCard::Rank StandardPlayingCard::get_rank() const {
    return rank;
}

void StandardPlayingCard::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_suit", "suit"), &StandardPlayingCard::set_suit);
    ClassDB::bind_method(D_METHOD("get_suit"), &StandardPlayingCard::get_suit);
    ClassDB::bind_method(D_METHOD("set_rank", "rank"), &StandardPlayingCard::set_rank);
    ClassDB::bind_method(D_METHOD("get_rank"), &StandardPlayingCard::get_rank);

    ADD_SIGNAL(MethodInfo("suit_changed", PropertyInfo(Variant::INT, "changed_suit")));
    ADD_SIGNAL(MethodInfo("rank_changed", PropertyInfo(Variant::INT, "changed_rank")));

    ADD_PROPERTY(PropertyInfo(Variant::INT, "suit", PROPERTY_HINT_ENUM, "Spades,Hearts,Clubs,Diamonds"), "set_suit", "get_suit");
    ADD_PROPERTY(PropertyInfo(Variant::INT, "rank", PROPERTY_HINT_ENUM, "Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace"), "set_rank", "get_rank");

    BIND_ENUM_CONSTANT(SUIT_SPADES);
    BIND_ENUM_CONSTANT(SUIT_HEARTS);
    BIND_ENUM_CONSTANT(SUIT_CLUBS);
    BIND_ENUM_CONSTANT(SUIT_DIAMONDS);

    BIND_ENUM_CONSTANT(RANK_TWO);
    BIND_ENUM_CONSTANT(RANK_THREE);
    BIND_ENUM_CONSTANT(RANK_FOUR);
    BIND_ENUM_CONSTANT(RANK_FIVE);
    BIND_ENUM_CONSTANT(RANK_SIX);
    BIND_ENUM_CONSTANT(RANK_SEVEN);
    BIND_ENUM_CONSTANT(RANK_EIGHT);
    BIND_ENUM_CONSTANT(RANK_NINE);
    BIND_ENUM_CONSTANT(RANK_TEN);
    BIND_ENUM_CONSTANT(RANK_JACK);
    BIND_ENUM_CONSTANT(RANK_QUEEN);
    BIND_ENUM_CONSTANT(RANK_KING);
    BIND_ENUM_CONSTANT(RANK_ACE);
}