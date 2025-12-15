class_name CardDeck
extends CardStack

var _top := CardStack.new()
var _middle := CardGroup.new()
var _bottom := CardStack.new()


func _init() -> void:
	add_child(_top)
	add_child(_middle)
	add_child(_bottom)


func transfer_card(card: Card) -> void:
	_middle.transfer_card(card)


func get_card_count() -> int:
	return _top.get_card_count() + _middle.get_card_count() + _bottom.get_card_count()


func get_random_card() -> Card:
	# To Do
	return null


func remove_card(card: Card) -> void:
	# To Do
	pass


func transfer_card_to_top(card: Card) -> void:
	_top.transfer_card_to_top(card)


func transfer_card_to_bottom(card: Card) -> void:
	_bottom.transfer_card_to_bottom(card)


func get_top_card() -> Card:
	var top_card: Card = _top.get_top_card()
	if top_card != null:
		return top_card
	top_card = _middle.get_random_card()
	if top_card != null:
		_top.transfer_card_to_top(top_card)
		return top_card
	# Need to handle edge case where middle is filled
	# After a bottom card is added to the top
	top_card = _bottom.get_top_card()
	return top_card


func get_bottom_card() -> Card:
	var bottom_card: Card = _bottom.get_bottom_card()
	if bottom_card != null:
		return bottom_card
	bottom_card = _middle.get_random_card()
	if bottom_card != null:
		_bottom.transfer_card_to_bottom(bottom_card)
		return bottom_card
	# Need to handle edge case where middle is filled
	# After a top card is added to the bottom
	bottom_card = _top.get_bottom_card()
	return bottom_card


# Need to deal with the fact that draws aren't actually
# added to the middle of a group usually
func draw_card(recipient: CardGroup) -> void:
	recipient.transfer_card(get_top_card())


func shuffle() -> void:
	# To do
	# Reparent all to middle
	pass
