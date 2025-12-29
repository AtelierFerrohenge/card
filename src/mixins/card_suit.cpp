#include "card_suit.h"

void CardSuit::set_suit(int p_suit) {
    suit = p_suit;
}

int  CardSuit::get_suit() const {
    return suit;
}

TypedArray<String> CardSuit::get_suits() const {
    TypedArray<String> suits;
    if(GDVIRTUAL_CALL(_get_suits, suits)) {
        return suits;
    }

    suits.push_back("Spades");
    suits.push_back("Hearts");
    suits.push_back("Clubs");
    suits.push_back("Diamonds");
    return suits;
}

String CardSuit::get_hints() const {
    return String(",").join(get_suits());
}

void CardSuit::_bind_methods() {
    GDVIRTUAL_BIND(_get_suits);
}

bool CardSuit::_set(const StringName &p_name, const Variant &p_property) {
    // Check if I can use SNAME("suit") somehow
    if(p_name == StringName("suit")) {
        set_suit(p_property);
    } else {
        return false;
    }
    return true;
}

bool CardSuit::_get(const StringName &p_name, Variant &r_property) const {
    // Check if I can use SNAME("suit") somehow
    if(p_name == StringName("suit")) {
        r_property = get_suit();
    } else {
        return false;
    }
    return true;
}

void CardSuit::_get_property_list(List<PropertyInfo> *p_list) const {
    // Check if I can use PNAME("suit") somehow
    p_list->push_back(PropertyInfo(Variant::INT, "suit", PROPERTY_HINT_ENUM, get_hints()));
}