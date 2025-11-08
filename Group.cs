using Godot;
using System;

public partial class Group : Node
{
	[Export]
	public CardModifierSet Modifiers { get; set; }

	// Add a way to restrict cards from a group

	public virtual void ReceiveCard(Card card)
	{
		card.Reparent(this);
	}
}
