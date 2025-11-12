using Godot;
using System;

public partial class Hand : CardGroup
{
	protected CardPlayer _player;

	public override void _Ready()
	{
		_player = GetParent() as CardPlayer;
		// Verify Hand is owned by a CardPlayer
	}
}
