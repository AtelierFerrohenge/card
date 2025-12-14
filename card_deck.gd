class_name CardDeck
extends CardStack

var _shuffled := CardPool.new()
var _bottom := CardStack.new()


func draw_card(recipient: CardGroup):
	recipient.add_card(get_top_card())


func get_top_card() -> Card:
	if size() > 0:
		return get_top_card()
	var new_top: Card = _shuffled.get_random_card()
	# Add handling for when even _shuffled is empty and you need to draw from the bottom
	add_card(new_top)
	return new_top


func get_bottom_card() -> Card:
	if _bottom.get_card_count() > 0:
		return _bottom.get_bottom_card()
	var new_bottom: Card = _shuffled.get_random_card()
	# Add handling for when even _shuffled is empty and you need to draw from the top
	# Invert the bottom for speed
	_bottom.add_card_to_bottom(new_bottom)
	return new_bottom


func add_card(card: Card, _index: int = -1) -> void:
	_shuffled.add_card(card)
