#pragma once

#include "card.h"

using namespace godot;

class StandardPlayingCard : public Card {
    GDCLASS(StandardPlayingCard, Card)

public:
    enum Suit {
        SUIT_SPADES,
        SUIT_HEARTS,
        SUIT_CLUBS,
        SUIT_DIAMONDS,
    };

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

    StandardPlayingCard() = default;
    ~StandardPlayingCard() override = default;

    void set_suit(Suit p_suit);
    Suit get_suit() const;

    void set_rank(Rank p_rank);
    Rank get_rank() const;

protected:
    static void _bind_methods();

private:
    Suit suit = SUIT_SPADES;
    Rank rank = RANK_ACE;
};

VARIANT_ENUM_CAST(StandardPlayingCard::Suit);
VARIANT_ENUM_CAST(StandardPlayingCard::Rank);