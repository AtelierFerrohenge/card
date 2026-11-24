#include "card.h"

void Card::_bind_methods() {
    ADD_SIGNAL(MethodInfo("group_changed", PropertyInfo(Variant::OBJECT, "card", PROPERTY_HINT_RESOURCE_TYPE, Card::get_class_static())));
}