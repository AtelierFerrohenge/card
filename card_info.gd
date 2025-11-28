class_name CardInfo
extends Node

var group: CardGroup = null
var group_index: int = -1
var _shown_to: int = 0:
	set = set_shown_to
var _visual_node: Node = null


func show_to_player(id: int) -> void:
	_shown_to |= 1 << id


func hide_from_player(id: int) -> void:
	_shown_to &= ~(1 << id)


func set_shown_to(value: int) -> void:
	if _shown_to != value:
		_shown_to = value
		_visual_node.update_visuals(_shown_to)
