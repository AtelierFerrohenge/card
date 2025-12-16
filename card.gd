@abstract
class_name Card
extends Node

signal update_visuals(show_to: int)

@export var visual_card_scene: PackedScene

var _shown_to: int = 0:
	set = _set_shown_to


func _ready() -> void:
	# Temporarily use get_parent()
	var visual_card_instance: Node = visual_card_scene.instantiate()
	# Encode the requirement for visual_card_ready somewhere
	visual_card_instance.visual_card_ready.connect(_on_visual_card_ready)
	get_parent().add_child.call_deferred(visual_card_instance)


func show_to_player(id: int) -> void:
	_shown_to |= 1 << id


func hide_from_player(id: int) -> void:
	_shown_to &= ~(1 << id)


@abstract func _on_visual_card_ready(visual_card: Node) -> void


func _set_shown_to(value: int) -> void:
	if _shown_to != value:
		_shown_to = value
		update_visuals.emit(_shown_to)
