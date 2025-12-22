@tool
class_name CardRankOld
extends Resource

signal rank_changed(new_suit: Rank)

enum Rank {
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	JACK,
	QUEEN,
	KING,
	ACE,
}

@export var rank: Rank = Rank.ACE:
	set = _set_rank


func _init() -> void:
	resource_local_to_scene = true


func emit() -> void:
	rank_changed.emit(rank)


func _set_rank(value: Rank) -> void:
	rank = value
	emit()
