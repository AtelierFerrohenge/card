class_name CardPool
extends CardGroup


func add_card_to_array(card: Card, index: int = -1) -> void:
	if index != -1:
		card = _replace_card(card, index)
	_push_back(card)


func remove_card_from_array(index: int) -> Card:
	var swap_index: int = _cards.size() - 1
	var swap_card: Card = _pop_back()
	if index != swap_index:
		swap_card = _replace_card(swap_card, index)
	return swap_card
