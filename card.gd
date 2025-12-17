@abstract
class_name Card
extends Node

@export var _visual_card_scene: PackedScene = null

var visual_card: Node = null


func _ready() -> void:
	# Decide what to do if the PackedScene is null
	visual_card = _visual_card_scene.instantiate()
	visual_card.ready.connect(_on_visual_card_ready)


@abstract func _on_visual_card_ready() -> void
