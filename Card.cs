using Godot;
using System;

public abstract partial class Card : Node
{
	[Export]
	public Godot.Collections.Array<string> ShownTo { get; set; } = new Godot.Collections.Array<string>();

	// May want to make this take a string playerId and a bool visibility if it will only be used after individual updates
	protected abstract void UpdateVisibility();

	public void ShowToPlayer(string playerId)
	{
		ShownTo.Add(playerId);
		UpdateVisibility();
	}

	public void HideFromPlayer(string playerId)
	{
		ShownTo.Remove(playerId);
		UpdateVisibility();
	}
}
