#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class CardRank : public Resource {
    GDCLASS(CardRank, Resource)

public:
    CardRank() = default;
    ~CardRank() override = default;

    void set_rank(const StringName &p_rank);
    StringName get_rank() const;

protected:
    static void _bind_methods();

private:
    StringName rank;
};