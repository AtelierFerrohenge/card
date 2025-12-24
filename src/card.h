#pragma once

#include "godot_cpp/classes/node.hpp"

using namespace godot;

class Card : public Node {
    GDCLASS(Card, Node)

public:
    Card() = default;
    ~Card() override = default;

    // Consider adding a variadic function to quickly set up signals
    // Possibly unnecessary

protected:
    static void _bind_methods();
};
