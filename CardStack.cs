using Godot;
using System;

public partial class CardStack : CardGroup
{
	public virtual Card GetTop()
	{
		// Add deck out functionality
		// Also add verification (likely in Group) to ensure
		// non-Card Nodes are never added as children
		return (Card)GetChild(-1);
	}

	public virtual Card GetBottom()
	{
		return (Card)GetChild(0);
	}
}
