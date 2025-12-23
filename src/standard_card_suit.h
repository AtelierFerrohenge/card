#pragma once

#include "signal_prop_mixin.h"

using namespace godot;

class StandardCardSuit : public SignalPropMixin {
    GDCLASS(StandardCardSuit, SignalPropMixin)

public:
    enum Suit {
        SUIT_SPADE,
        SUIT_HEART,
        SUIT_CLUB,
        SUIT_DIAMOND,
    };

    StandardCardSuit() = default;
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