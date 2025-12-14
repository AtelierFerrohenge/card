class_name CardDeck
extends CardStack

var _top := CardStack.new()
var _bottom := CardStack.new()


func draw_card(recipient: CardGroup):
	recipient.add_card(get_top_card())


func get_top_card() -> Card:
	if _top.get_child_count() > 0:
		return _top.get_top_card()
	var new_top: Card = get_random_card()
	# Add handling for when even self is empty and you need to draw from the bottom
	_top.add_card(new_top)
	return new_top


func get_bottom_card() -> Card:
	if _bottom.get_child_count() > 0:
		return _bottom.get_top_card()
	var new_bottom: Card = get_random_card()
	# Add handling for when even self is empty and you need to draw from the top
	_bottom.add_card(new_bottom)
	return new_bottom
