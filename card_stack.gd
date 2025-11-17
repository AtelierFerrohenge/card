class_name CardStack
extends CardGroup


func get_top_card() -> CardInfo:
	# Implement no cards or deck out
	return _cards.back()


func get_bottom_card() -> CardInfo:
	# Implement no cards or deck out
	return _cards.front()


func add_card_to_bottom(card: CardInfo) -> void:
	# Quick implementation - reimplement later with card_group add_card changes too
	add_card(card)
	var bottom: CardInfo = get_bottom_card()
	_cards[0] = card
	_cards[-1] = bottom
	card.group_index = 0
	bottom.group_index = _cards.size() - 1
