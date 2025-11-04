using Godot;
using System;

[GlobalClass]
public abstract partial class Card : Node
{
	private bool _shown;

	// May need to make into array for multiplayer or vs AI
	[Export]
	public bool Shown
	{
		get => _shown;
		set
		{
			_shown = value;
			UpdateVisibility();
		}
	}

	protected abstract void UpdateVisibility();
}
