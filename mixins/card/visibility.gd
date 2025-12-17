class_name Visibility
extends Resource

signal visibility_changed(new_visibility: int)

var _visibility: int = 0:
	set = _set_visibility


func show_to_player(id: int) -> void:
	_visibility |= 1 << id


func hide_from_player(id: int) -> void:
	_visibility &= ~(1 << id)


func emit() -> void:
	visibility_changed.emit(_visibility)


func _set_visibility(value: int) -> void:
	_visibility = value
	emit()
