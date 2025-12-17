class_name CardGroup
extends Node

@export var _visual_card_group_scene: PackedScene = null

var _visual_card_group: Node = null


func _ready() -> void:
	if _visual_card_group_scene != null:
		_visual_card_group = _visual_card_group_scene.instantiate()
		_visual_card_group.ready.connect(_on_visual_card_group_ready)
		# Temporarily use get_parent()
		get_parent().add_child.call_deferred(_visual_card_group)


func transfer_card(card: Card) -> void:
	if card.get_parent() == null:
		add_child(card)
	else:
		card.reparent(self)


func get_card_count() -> int:
	return get_child_count()


func is_empty() -> bool:
	return get_card_count() == 0


func get_random_card() -> Card:
	return null if is_empty() else get_child(randi() % get_card_count())


func get_cards() -> Array[Node]:
	# Try to convert to Array[Card]
	return get_children()


func remove_card(card: Card) -> void:
	assert(card.get_parent() == self, "The card is not in this group.")
	remove_child(card)


func _on_visual_card_group_ready() -> void:
	for card: Card in get_cards():
		_visual_card_group.add_child(card.visual_card)
