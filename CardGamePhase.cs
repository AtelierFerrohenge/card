using Godot;
using System;

public abstract partial class CardGamePhase : Resource
{
	[Signal]
	public delegate void PhaseEndedEventHandler(CardGamePhase nextPhase);

	public abstract void Start();

	public abstract void Run();

	// Enforce signal emission or loop back to start at the end
	public abstract void End();
}
