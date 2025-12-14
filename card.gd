class_name Card
extends Node

signal update_visuals(show_to: int)

# Make this a Dictionary representation
var _shown_to: int = 0:
	set = set_shown_to


func show_to_player(id: int) -> void:
	_shown_to |= 1 << id


func hide_from_player(id: int) -> void:
	_shown_to &= ~(1 << id)


func set_shown_to(value: int) -> void:
	if _shown_to != value:
		_shown_to = value
		update_visuals.emit(_shown_to)
