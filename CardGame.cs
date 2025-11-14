using Godot;
using System;

public partial class CardGame : Node
{
	[Export]
	private CardGamePhase Phase { get; set; }

	private void ChangePhase(CardGamePhase nextPhase)
	{
        // Review if this is needed
        Phase.PhaseEnded -= ChangePhase;

		Phase = nextPhase;

        Phase.PhaseEnded += ChangePhase;
	}

	public override void _Ready()
	{
		Phase.PhaseEnded += ChangePhase;
	}
}
