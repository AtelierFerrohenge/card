#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class StandardCardSuit : public Resource {
    GDCLASS(StandardCardSuit, Resource)

public:
    enum Suit {
        SUIT_SPADE,
        SUIT_HEART,
        SUIT_CLUB,
        SUIT_DIAMOND,
    };

    StandardCardSuit();
    ~StandardCardSuit() override = default;

    // Review if setter can and should be private
    void set_suit(Suit p_suit);
    Suit get_suit() const;

    void init_signals(Callable p_callable);

protected:
    static void _bind_methods();

private:
    Suit suit = SUIT_SPADE;
};

VARIANT_ENUM_CAST(StandardCardSuit::Suit);