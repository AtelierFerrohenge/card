# card

Next Priorities:
	Ignore the below task and...
		Move the functionality into Card itself with the ability to add multiple of these properties
		stored within a dictionary
		Step 1. Figure out how dictionaries are used in Godot C++ and make one with string (or string name) to int
		Step 2. Link _get and _set of Card to this dictionary
		Step 3. Make a modified version of get_suits in Card with type string to string array dictionary
		Step 4. Iterate this second dictionary in _get_property_list to generate enums
		Step 5. Optional for now - add prefixes to custom property names to determine if they're meant to be enums
			or other properties to allow for complete custom properties
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
