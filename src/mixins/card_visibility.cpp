#include "card_visibility.h"

CardVisibility::CardVisibility() {
    set_local_to_scene(true);
}

void CardVisibility::show(int p_player) {
    visibility |= 1 << p_player;
}

void CardVisibility::hide(int p_player) {
    visibility &= ~(1 << p_player);
}

void CardVisibility::set_visibility(int p_visibility) {
    visibility = p_visibility;
    emit_signal("visibility_changed", visibility);
}

int CardVisibility::get_visibility() const {
    return visibility;
}

void CardVisibility::_bind_methods() {
    ClassDB::bind_method(D_METHOD("show", "player"), &CardVisibility::show);
    ClassDB::bind_method(D_METHOD("hide", "player"), &CardVisibility::hide);
    ClassDB::bind_method(D_METHOD("set_visibility", "visibility"), &CardVisibility::set_visibility);
    ClassDB::bind_method(D_METHOD("get_visibility"), &CardVisibility::get_visibility);

    ADD_SIGNAL(MethodInfo("visibility_changed", PropertyInfo(Variant::INT, "changed_visibility")));

    ADD_PROPERTY(PropertyInfo(Variant::INT, "visibility"), "set_visibility", "get_visibility");
}