class_name CardGroup
extends Node


func transfer_card(card: Card) -> void:
	if card.get_parent() == null:
		add_child(card)
	else:
		card.reparent(self)


func get_card_count() -> int:
	return get_child_count()


func is_empty() -> bool:
	return get_card_count() == 0


func get_random_card() -> Card:
	return null if is_empty() else get_child(randi() % get_card_count())


func remove_card(card: Card) -> void:
	assert(card.get_parent() == self, "The card is not in this group.")
	remove_child(card)
