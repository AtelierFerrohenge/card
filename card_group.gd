@tool
class_name CardGroupOld
extends Resource

# Research if std::map can represent both
var _card_lookup: Dictionary[Card, int] = {}
var _cards_order: Array[Card] = []


func _init() -> void:
	resource_local_to_scene = true


func transfer_card(card: Card) -> void:
	# Review if calling an unrelated object's signal
	# is a good idea
	# Still need to hook this up
	card.transferred.emit()
	_card_lookup[card] = _cards_order.size()
	_cards_order.append(card)


func is_empty() -> bool:
	return _cards_order.size() == 0


func get_random_card() -> Card:
	return null if is_empty() else _cards_order.pick_random()


func remove_card(card: Card) -> void:
	# Guardrail against removing cards not part of the group
	# Optimize this with swapping for unordered groups
	# if std::map doesn't work
	_cards_order.remove_at(_card_lookup[card])
	_card_lookup.erase(card)
