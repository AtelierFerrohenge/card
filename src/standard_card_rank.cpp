#include "standard_card_rank.h"

StandardCardRank::StandardCardRank() {
    set_local_to_scene(true);
}

void StandardCardRank::set_rank(Rank p_rank) {
    rank = p_rank;
    // Consider standardizing this into a function
    emit_signal("rank_changed", rank);
}

StandardCardRank::Rank StandardCardRank::get_rank() const {
    return rank;
}

void StandardCardRank::init_signals(Callable p_callable) {
    connect("rank_changed", p_callable);
    // Consider standardizing this into a function
    emit_signal("rank_changed", rank);
}

void StandardCardRank::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_rank", "p_rank"), &StandardCardRank::set_rank);
    ClassDB::bind_method(D_METHOD("get_rank"), &StandardCardRank::get_rank);
    ClassDB::bind_method(D_METHOD("init_signals", "p_callable"), &StandardCardRank::init_signals);

    // Make sure Variant::INT is the best choice here
    ADD_SIGNAL(MethodInfo("rank_changed", PropertyInfo(Variant::INT, "changed_rank")));

    ADD_PROPERTY(PropertyInfo(Variant::INT, "rank", PROPERTY_HINT_ENUM, "Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Jack,Queen,King,Ace"), "set_rank", "get_rank");

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