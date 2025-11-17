class_name CardStack
extends CardGroup


func get_top_card() -> CardInfo:
	# Implement no cards or deck out
	return _cards[-1]


func get_bottom_card() -> CardInfo:
	# Implement no cards or deck out
	return _cards[0]


func add_card_to_array(card: CardInfo, index: int = -1) -> void:
	var result: int = _cards.insert(index, card)
	assert(result == OK, "Card insertion failed.")


func remove_card_from_array(index: int) -> CardInfo:
	return _cards.pop_at(index)
