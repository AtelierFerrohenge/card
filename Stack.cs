using Godot;
using System;

public partial class Stack : Group
{
	public Card GetTop()
	{
		// Add deck out functionality
		// Also add verification (likely in Group) to ensure
		// non-Card Nodes are never added as children
		return (Card)GetChild(-1);
	}
}
