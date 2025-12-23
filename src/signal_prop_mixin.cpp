#include "signal_prop_mixin.h"

SignalPropMixin::SignalPropMixin() {
    set_local_to_scene(true);
}

void SignalPropMixin::_bind_methods() {
    // Probably need to make this a generic so I'm not locked into Variant::INT
    // Make sure Variant::INT is the best choice here for enums, too
    ADD_SIGNAL(MethodInfo("value_changed", PropertyInfo(Variant::INT, "changed_value")));
}