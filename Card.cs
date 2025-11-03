using Godot;
using System;

[GlobalClass]
public abstract partial class Card : Node
{
	private bool _shown;

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
