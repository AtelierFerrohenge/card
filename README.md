# card

Next Priorities:
	Rework shadow + visual node system into resource + visual node system
		Undo rework - bring back shadow system as it's the only one that allows
		one to many data to visual relationships with the option to set values
		in the editor
	Convert visibility to some sort of set of players and make an editor representation for it
	Review the below
	Complete card_deck update after card_group abstraction
	Organize cards with nodes rather than collections
	Add a testing "draw" button
	Make methods in abstract classes virtual or abstract so they can be overridden
	Don't force the playerId to be an int
	Consider splitting the CardPhase system into a general FSM system
		Also check if that doesn't already exist somewhere in a form I like
	Add a way to restrict cards from a group
	Consider making backing (non-Node) classes not Resources
	Add deck out functionality

Reviewed parts of godot-cpp-template:
	godot-cpp
	src
		???
	.gitmodules
	LICENSE.md
	README.md
	SConstruct
	methods.py

	Need to review differences between SConstruct file of tutorial and template
	Need to review differences between .gdextension file of tutorial and template, primarily reloadable = true
