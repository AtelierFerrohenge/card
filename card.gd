@abstract
class_name Card
extends Node

@export var visual_card_scene: PackedScene

var shown_to: int = 0:
	set = _set_shown_to

var _visual_card: Node


func _ready() -> void:
	_visual_card = visual_card_scene.instantiate()
	_visual_card.ready.connect(_on_visual_card_ready)
	# Temporarily use get_parent()
	get_parent().add_child.call_deferred(_visual_card)


func show_to_player(id: int) -> void:
	shown_to |= 1 << id


func hide_from_player(id: int) -> void:
	shown_to &= ~(1 << id)


@abstract func _update_shown_to_visual() -> void


func _set_shown_to(value: int) -> void:
	shown_to = value
	_update_shown_to_visual()


func _on_visual_card_ready() -> void:
	_update_shown_to_visual()
