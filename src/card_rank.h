#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class CardRank : public Resource {
    GDCLASS(CardRank, Resource)

public:
    enum Rank {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE,
    };

    CardRank() = default;
    ~CardRank() override = default;

    void set_rank(Rank p_rank);
    Rank get_rank() const;

protected:
    static void _bind_methods();

private:
    Rank rank = TWO;
};

VARIANT_ENUM_CAST(CardRank::Rank);