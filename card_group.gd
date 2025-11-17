class_name CardGroup
extends Resource

var _cards: Array[CardInfo] = []


func add_card(card: CardInfo) -> void:
	if card.group != null:
		assert(card.group != self, "The card is already in this group.")
		card.group.remove(card)
	_cards.append(card)
	card.group = self
	card.group_index = _cards.size() - 1


func remove_card(card: CardInfo) -> void:
	assert(card.group == self, "The card is not in this group.")
	assert(card.group_index >= 0 and card.group_index < _cards.size() and _cards[card.group_index] == card, "The card is tracking an invalid group index.")
	var back: CardInfo = _cards.pop_back()
	if card.group_index != _cards.size() - 1:
		_cards[card.group_index] = back
