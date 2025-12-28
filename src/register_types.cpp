#include "register_types.h"

#include <gdextension_interface.h>
// Figure out why the below line is in the template but not in the tutorial
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "card.h"
#include "standard_playing_card.h"
#include "card_group.h"
#include "card_stack.h"
#include "card_deck.h"
#include "mixins/card_visibility.h"

using namespace godot;

void initialize_gdextension_types(ModuleInitializationLevel p_level)
{
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
    GDREGISTER_CLASS(Card);
    GDREGISTER_CLASS(StandardPlayingCard);
    GDREGISTER_CLASS(CardGroup);
    GDREGISTER_CLASS(CardStack);
    GDREGISTER_CLASS(CardDeck);
    GDREGISTER_CLASS(CardVisibility);
}

void uninitialize_gdextension_types(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
        return;
    }
}

extern "C"
{
    // Probably rename example_library_init later
    // Figure out why GDExtensionClassLibraryPtr is const in the tutorial but not the template
    GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
    {
        // Figure out why the template doesn't need godot:: in front of GDExtensionBinding
        GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
        init_obj.register_initializer(initialize_gdextension_types);
        init_obj.register_terminator(uninitialize_gdextension_types);
        init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

        return init_obj.init();
    }
}