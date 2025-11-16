class_name CardInfo
extends Resource

signal visibility_changed(shown_to: int)

## Bit flags corresponding to player id
@export var shown_to: int = 0:
	set = set_shown_to
var visual_node: Node = null:
	set = set_visual_node


func show_to_player(id: int) -> void:
	shown_to |= 1 << id


func hide_from_player(id: int) -> void:
	shown_to &= ~(1 << id)


func set_shown_to(value: int) -> void:
	shown_to = value
	visibility_changed.emit(shown_to)


func set_visual_node(value: Node) -> void:
	if visual_node != null:
		visibility_changed.disconnect(visual_node._on_visibility_changed)
	visual_node = value
	assert(visual_node.has_method(&"_on_visibility_changed"), "visual_node does not have the method _on_visibility_changed.")
	visibility_changed.connect(visual_node._on_visibility_changed)
