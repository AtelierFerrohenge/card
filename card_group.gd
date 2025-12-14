class_name CardGroup
extends Node


func add_card(card: Card, index: int = -1) -> void:
	if card.get_parent() == null:
		add_child(card)
	else:
		card.reparent(self)
	if index != -1:
		move_child(card, index)


func get_random_card() -> Card:
	return null


func remove_card(card: Card) -> void:
	assert(card.get_parent() == self, "The card is not in this group.")
	remove_child(card)
