class_name CardStack
extends CardGroup


func get_top_card() -> CardInfo:
	# Implement no cards or deck out
	return _cards.back()


func get_bottom_card() -> CardInfo:
	# Implement no cards or deck out
	return _cards.front()
