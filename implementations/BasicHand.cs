using Godot;
using System;

// A Hand that makes all received cards visible to the owner
public partial class BasicHand : Hand
{
	public override void AddCard(Card card)
	{
		base.AddCard(card);
		card.ShowToPlayer(PlayerId);
	}
}
