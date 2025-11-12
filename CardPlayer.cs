using Godot;
using System;

public partial class CardPlayer : Node
{
	// Determine whether Hand should be a separate class or part of CardPlayer
	// If [Export] for <[MustBeVariant] T> is implemented, consider replacing int with T
	[Export]
	public int PlayerId { get; set; }
}
