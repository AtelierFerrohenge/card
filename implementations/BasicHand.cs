using Godot;
using System;

// A Hand that makes all received cards visible to the owner
public partial class BasicHand : Hand
{
	public override void ReceiveCard(Card card)
	{
		base.ReceiveCard(card);
		card.ShowToPlayer(PlayerId);
	}
}
