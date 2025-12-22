#include "card_rank.h"

void CardRank::set_rank(Rank p_rank) {
    rank = p_rank;
}

CardRank::Rank CardRank::get_rank() const {
    return rank;
}

void CardRank::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_rank"), &CardRank::get_rank);
    ClassDB::bind_method(D_METHOD("set_rank", "p_rank"), &CardRank::set_rank);

    ADD_PROPERTY(PropertyInfo(Variant::INT, "rank", PROPERTY_HINT_ENUM, "Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace"), "set_rank", "get_rank");

    BIND_ENUM_CONSTANT(TWO);
    BIND_ENUM_CONSTANT(THREE);
    BIND_ENUM_CONSTANT(FOUR);
    BIND_ENUM_CONSTANT(FIVE);
    BIND_ENUM_CONSTANT(SIX);
    BIND_ENUM_CONSTANT(SEVEN);
    BIND_ENUM_CONSTANT(EIGHT);
    BIND_ENUM_CONSTANT(NINE);
    BIND_ENUM_CONSTANT(TEN);
    BIND_ENUM_CONSTANT(JACK);
    BIND_ENUM_CONSTANT(QUEEN);
    BIND_ENUM_CONSTANT(KING);
    BIND_ENUM_CONSTANT(ACE);
}