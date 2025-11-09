using Godot;
using System;

public partial class Deck : CardStack
{
	private CardStack _top;
	private CardGroup _middle;
	private CardStack _bottom;

	public void Draw(CardGroup target)
	{
		target.AddCard(GetTop());
	}

	public void Shuffle()
	{
		// Consider making this a standalone method
		foreach (Node card in _top.GetChildren())
		{
			// Consider using AddCard or not
			card.Reparent(_middle);
		}
		foreach (Node card in _bottom.GetChildren())
		{
			card.Reparent(_middle);
		}
	}

	public override Card GetTop()
	{
		if ( _top.GetChildCount() > 0 )
		{
			return _top.GetTop();
		}
		else
		{
			Card newTop = _middle.GetRandom();
			_top.AddCard(newTop);
			return newTop;
		}
	}

	public override Card GetBottom()
	{
		if ( _bottom.GetChildCount() > 0 )
		{
			return _bottom.GetBottom();
		}
		else
		{
			Card newBottom = _middle.GetRandom();
			_bottom.AddCard(newBottom);
			_bottom.MoveChild(newBottom, 0);
			return newBottom;
		}
	}

	public override void AddCard(Card card)
	{
		_middle.AddCard(card);
	}

	public override void _Ready()
	{
		base._Ready();

		_top = new CardStack();
		_top.Name = "Top";
		AddChild(_top);

		_middle = new CardGroup();
		_middle.Name = "Middle";
		AddChild(_middle);
		
		_bottom = new CardStack();
		_bottom.Name = "Bottom";
		AddChild(_bottom);
	}
}
