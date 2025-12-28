#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class CardSuit : public Resource {
    GDCLASS(CardSuit, Resource)

public:
    CardSuit() = default;
    ~CardSuit() override = default;

    void set_suit(const StringName &p_suit);
    StringName get_suit() const;

protected:
    static void _bind_methods();

private:
    StringName suit;
};