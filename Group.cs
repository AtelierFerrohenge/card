using Godot;
using System;

public partial class Group : Node
{
	public virtual void ReceiveCard(Card card)
	{
		card.Reparent(this);
	}
}
