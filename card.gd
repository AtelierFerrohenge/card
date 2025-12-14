class_name Card
extends Node

signal update_visuals(show_to: int)

var group: CardGroup = null
var group_index: int = -1
var _shown_to: int = 0:
	set = set_shown_to
var _visual_node: Node = null:
	set = set_visual_node


func show_to_player(id: int) -> void:
	_shown_to |= 1 << id


func hide_from_player(id: int) -> void:
	_shown_to &= ~(1 << id)


func set_shown_to(value: int) -> void:
	if _shown_to != value:
		_shown_to = value
		update_visuals.emit(_shown_to)


func set_visual_node(value: Node) -> void:
	# Check the target method exists
	if _visual_node != null:
		update_visuals.disconnect(_visual_node.update_visuals)
	_visual_node = value
	if _visual_node != null:
		update_visuals.connect(_visual_node.update_visuals)
