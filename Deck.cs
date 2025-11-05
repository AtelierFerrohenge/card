using Godot;
using System;

public abstract partial class Deck : Group
{
	// This actually just returns the top rather than "revealing" it
	// I should rename this and maybe implement a real top revealing function later
	public Card RevealTop()
	{
		// Add deck out functionality
		// Also add verification (likely in Group) to ensure
		// non-Card Nodes are never added as children
		return (Card)GetChild(-1);
	}

	public void Draw(Group target)
	{
		target.GetCard(RevealTop());
	}
}
