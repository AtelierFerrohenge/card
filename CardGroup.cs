using Godot;
using System;

public partial class CardGroup : Node
{
	[Export]
	public CardModifierSet Modifiers { get; set; }

	// Add a way to restrict cards from a group

	public virtual void AddCard(Card card)
	{
		card.GetParent()?.RemoveChild(card);
		AddChild(card);
	}

	public Card GetRandom()
	{
		// Consider RNG modularization later
		return (Card)GetChild((int)(GD.Randi() % GetChildCount()));
	}
}
