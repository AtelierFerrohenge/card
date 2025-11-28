@abstract
class_name CardGroup
extends Node

var _cards: Array[CardInfo] = []


@abstract func add_card_to_array(card: CardInfo, index: int = -1) -> void


func add_card(card: CardInfo, index: int = -1) -> void:
	if card.group != null:
		assert(card.group != self, "The card is already in this group.")
		card.group.remove(card)
	add_card_to_array(card, index)


@abstract func remove_card_from_array(index: int) -> CardInfo


func remove_card(card: CardInfo) -> void:
	assert(card.group == self, "The card is not in this group.")
	var removed_card: CardInfo = remove_card_from_array(card.group_index)
	assert(removed_card == card, "The wrong card was removed.")


func get_random_card() -> CardInfo:
	# Consider using RandomNumberGenerator
	return _cards.pick_random()


func size() -> int:
	return _cards.size()


func _push_back(card: CardInfo) -> void:
	_cards.push_back(card)
	card.group = self
	card.group_index = _cards.size() - 1


func _pop_back() -> CardInfo:
	var card: CardInfo = _cards.pop_back()
	card.group = null
	card.group_index = -1
	return card


func _replace_card(card: CardInfo, index: int) -> CardInfo:
	assert(index >= 0 and index < _cards.size(), "The replacement index is invalid.")
	var replaced_card: CardInfo = _cards[index]
	_cards[index] = card
	card.group = self
	card.group_index = index
	replaced_card.group = null
	replaced_card.group_index = -1
	return replaced_card
