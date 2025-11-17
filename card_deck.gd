class_name CardDeck
extends CardStack

var _shuffled := CardGroup.new()
var _bottom := CardStack.new()


func draw_card(recipient: CardGroup):
	recipient.add_card(get_top_card())


func get_top_card() -> CardInfo:
	if get_card_count() > 0:
		return get_top_card()
	var new_top: CardInfo = _shuffled.get_random_card()
	add_card(new_top)
	return new_top


func get_bottom_card() -> CardInfo:
	if _bottom.get_card_count() > 0:
		return _bottom.get_bottom_card()
	var new_bottom: CardInfo = _shuffled.get_random_card()
	_bottom.add_card_to_bottom(new_bottom)
	return new_bottom


func add_card(card: CardInfo) -> void:
	_shuffled.add_card(card)
