using Godot;
using System;

// A Hand that makes all received cards visible to the owner
public partial class BasicHand : Hand
{
	protected CardPlayer _player;

	public override void AddCard(Card card)
	{
		base.AddCard(card);
		card.ShowToPlayer(_player.PlayerId);
	}

	public override void _Notification(int what)
	{
		base._Notification(what);
		switch ((long)what)
		{
			case NotificationParented:
				_player = GetParent() as CardPlayer;
				break;
			case NotificationUnparented:
				_player = null;
				break;
		}
	}
}
