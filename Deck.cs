using Godot;
using System;

public partial class Deck : Stack
{
	public void Draw(Group target)
	{
		target.ReceiveCard(GetTop());
	}
}
