using Godot;
using System;

public partial class Deck : Group
{
	public Card GetTop()
	{
		// Add deck out functionality
		// Also add verification (likely in Group) to ensure
		// non-Card Nodes are never added as children
		return (Card)GetChild(-1);
	}

	public void Draw(Group target)
	{
		target.ReceiveCard(GetTop());
	}
}
