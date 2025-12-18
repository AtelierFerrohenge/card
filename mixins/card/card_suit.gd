@tool
class_name CardSuit
extends Resource

signal suit_changed(new_suit: Suit)

enum Suit {
	SPADE,
	HEART,
	CLUB,
	DIAMOND,
}

@export var suit: Suit = Suit.SPADE:
	set = _set_suit


func _init() -> void:
	resource_local_to_scene = true


func emit() -> void:
	suit_changed.emit(suit)


func _set_suit(value: Suit) -> void:
	suit = value
	emit()
