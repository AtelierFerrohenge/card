@abstract
class_name CardGroup
extends Node

var _cards: Array[Card] = []


@abstract func add_card_to_array(card: Card, index: int = -1) -> void


func add_card(card: Card, index: int = -1) -> void:
	if card.group != null:
		assert(card.group != self, "The card is already in this group.")
		card.group.remove(card)
	add_card_to_array(card, index)


@abstract func remove_card_from_array(index: int) -> Card


func remove_card(card: Card) -> void:
	assert(card.group == self, "The card is not in this group.")
	var removed_card: Card = remove_card_from_array(card.group_index)
	assert(removed_card == card, "The wrong card was removed.")


func get_random_card() -> Card:
	# Consider using RandomNumberGenerator
	return _cards.pick_random()


func size() -> int:
	return _cards.size()


func _push_back(card: Card) -> void:
	_cards.push_back(card)
	card.group = self
	card.group_index = _cards.size() - 1


func _pop_back() -> Card:
	var card: Card = _cards.pop_back()
	card.group = null
	card.group_index = -1
	return card


func _replace_card(card: Card, index: int) -> Card:
	assert(index >= 0 and index < _cards.size(), "The replacement index is invalid.")
	var replaced_card: Card = _cards[index]
	_cards[index] = card
	card.group = self
	card.group_index = index
	replaced_card.group = null
	replaced_card.group_index = -1
	return replaced_card
