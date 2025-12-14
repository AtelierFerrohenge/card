class_name CardStack
extends CardGroup


func get_top_card() -> Card:
	# Implement no cards or deck out
	return get_child(-1)


func get_bottom_card() -> Card:
	# Implement no cards or deck out
	return get_child(0)
