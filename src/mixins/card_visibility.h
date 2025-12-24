#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class CardVisibility : public Resource {
    GDCLASS(CardVisibility, Resource)

public:
    CardVisibility();
    ~CardVisibility() override = default;

    // Consider replacing int with player reference
    // And converting to sets rather than bits
    void show(int p_player);
    void hide(int p_player);

    void set_visibility(int p_visibility);
    int get_visibility() const;

protected:
    static void _bind_methods();

private:
    int visibility = 0;
};