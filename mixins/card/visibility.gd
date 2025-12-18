@tool
class_name Visibility
extends Resource

signal visibility_changed(new_visibility: int)

@export var visibility: int = 0:
	set = _set_visibility


func _init() -> void:
	resource_local_to_scene = true


func show_to_player(id: int) -> void:
	visibility |= 1 << id


func hide_from_player(id: int) -> void:
	visibility &= ~(1 << id)


func emit() -> void:
	visibility_changed.emit(visibility)


func _set_visibility(value: int) -> void:
	visibility = value
	emit()
