#pragma once

#include "godot_cpp/classes/resource.hpp"

using namespace godot;

class SignalPropMixin : public Resource {
    GDCLASS(SignalPropMixin, Resource)

public:
    SignalPropMixin();
    ~SignalPropMixin() override = default;

protected:
    static void _bind_methods();
};