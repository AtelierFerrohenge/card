using Godot;
using System;

public abstract partial class Card : Node
{
	[Export]
	public Godot.Collections.Array<int> ShownTo { get; set; } = new Godot.Collections.Array<int>();

	[Export]
	public CardModifierSet Modifiers { get; set; }

	// May want to make this take a int playerId and a bool visibility if it will only be used after individual updates
	protected abstract void UpdateVisibility();

	public void ShowToPlayer(int playerId)
	{
		ShownTo.Add(playerId);
		UpdateVisibility();
	}

	public void HideFromPlayer(int playerId)
	{
		ShownTo.Remove(playerId);
		UpdateVisibility();
	}
}
