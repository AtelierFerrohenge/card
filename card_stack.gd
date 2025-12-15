class_name CardStack
extends CardGroup


func transfer_card_to_top(card: Card) -> void:
	transfer_card(card)


func transfer_card_to_bottom(card: Card) -> void:
	transfer_card(card)
	move_child(card, 0)


func get_top_card() -> Card:
	return null if is_empty() else get_child(-1)


func get_bottom_card() -> Card:
	return null if is_empty() else get_child(0)
