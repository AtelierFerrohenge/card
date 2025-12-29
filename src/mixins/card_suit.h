#pragma once

#include "godot_cpp/classes/resource.hpp"

#include <godot_cpp/core/gdvirtual.gen.inc>

using namespace godot;

class CardSuit : public Resource {
    GDCLASS(CardSuit, Resource)

public:
    CardSuit() = default;
    ~CardSuit() override = default;

    void set_suit(int p_suit);
    int get_suit() const;

    TypedArray<String> get_suits() const;
    String get_hints() const;

protected:
    static void _bind_methods();
    bool _set(const StringName &p_name, const Variant &p_property);
    bool _get(const StringName &p_name, Variant &r_property) const;
    void _get_property_list(List<PropertyInfo> *p_list) const;

    GDVIRTUAL0RC(TypedArray<String>, _get_suits)

private:
    int suit;
};