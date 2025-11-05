using Godot;
using System;

public abstract partial class Group : Node
{
	public void GetCard(Card card)
	{
		card.Reparent(this);
	}
}
