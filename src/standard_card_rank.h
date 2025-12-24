#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class StandardCardRank : public Resource {
    GDCLASS(StandardCardRank, Resource)

public:
    enum Rank {
        RANK_TWO,
        RANK_THREE,
        RANK_FOUR,
        RANK_FIVE,
        RANK_SIX,
        RANK_SEVEN,
        RANK_EIGHT,
        RANK_NINE,
        RANK_TEN,
        RANK_JACK,
        RANK_QUEEN,
        RANK_KING,
        RANK_ACE,
    };

    StandardCardRank();
    ~StandardCardRank() override = default;

    void set_rank(Rank p_rank);
    Rank get_rank() const;

protected:
    static void _bind_methods();

private:
    Rank rank = RANK_ACE;
};

VARIANT_ENUM_CAST(StandardCardRank::Rank);