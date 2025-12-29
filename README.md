# card

Next Priorities:
	Improve rank and suit mixins further by pulling values from a dynamic dictionary that
	can be modified in the editor but shows up as an enum dropdown
		Quickly implemented, need to go back through and clean things up
		Then split the functionality into a base class for suit and rank
		Or perhaps do away with suit and rank altogether and just use the base
		Or even merge the functionality back into Card for a sort of dynamic enums
		base class
	Rewrite card deck to have a single data structure tracking all "known" cards rather than
	just the top or bottom
	Remove unnecessary GDScript virtuals and unbind C++ virtual overrides
	Clean up C++ headers - figure out if minimum possible or duplicated whenever used in the same file
	is better
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
