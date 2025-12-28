#include "card_rank.h"

void CardRank::set_rank(const StringName &p_rank) {
    rank = p_rank;
}

StringName CardRank::get_rank() const {
    return rank;
}

void CardRank::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_rank", "rank"), &CardRank::set_rank);
    ClassDB::bind_method(D_METHOD("get_rank"), &CardRank::get_rank);

    ADD_PROPERTY(PropertyInfo(Variant::STRING_NAME, "rank"), "set_rank", "get_rank");
}