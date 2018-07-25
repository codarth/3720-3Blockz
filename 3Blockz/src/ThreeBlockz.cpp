#include <sdk.h> // Code::Blocks SDK
#include <configurationpanel.h>
#include <logmanager.h>
#include <map>
#include "../include/ThreeBlockz.h"
#include "../include/OpEqOverloadToolHandler.h"
#include "../include/HashToolHandler.h"

// Register the plugin with Code::Blocks.
// We are using an anonymous namespace so we don't litter the global one.
namespace
{
PluginRegistrant<ThreeBlockz> reg(_T("ThreeBlockz"));
}

BEGIN_EVENT_TABLE(ThreeBlockz, cbPlugin)
    EVT_MENU(TBZ::ABOUT_MENU_ID, ThreeBlockz::menuItemCommandEvent)
    EVT_MENU(TBZ::HASH_MENU_ID, ThreeBlockz::menuItemCommandEvent)
    EVT_MENU(TBZ::OP_EQ_MENU_ID, ThreeBlockz::menuItemCommandEvent)
    EVT_MENU(TBZ::GET_SET_MENU_ID, ThreeBlockz::menuItemCommandEvent)
    EVT_MENU(TBZ::BUILDER_MENU_ID, ThreeBlockz::menuItemCommandEvent)
END_EVENT_TABLE()

ThreeBlockz::ThreeBlockz():_threeBlockzMenu(nullptr)
{
    // Make sure our resources are available.
    // In the generated boilerplate code we have no resources but when
    // we add some, it will be nice that this code is in place already ;)
    if(!Manager::LoadResource(_T("ThreeBlockz.zip")))
    {
        NotifyMissingFile(_T("ThreeBlockz.zip"));
    }
}

ThreeBlockz::~ThreeBlockz()
{

}

void ThreeBlockz::OnAttach()
{
    // do whatever initialization you need for your plugin
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be TRUE...
    // You should check for it in other functions, because if it
    // is FALSE, it means that the application did *not* "load"
    // (see: does not need) this plugin...
}

void ThreeBlockz::OnRelease(bool appShutDown)
{
    // do de-initialization for your plugin
    // if appShutDown is true, the plugin is unloaded because Code::Blocks is being shut down,
    // which means you must not use any of the SDK Managers
    // NOTE: after this function, the inherited member variable
    // m_IsAttached will be FALSE...
    if (!appShutDown)
        this->_threeBlockzMenu->Detach();
}

void ThreeBlockz::BuildMenu(wxMenuBar* menuBar)
{
    if (!this->m_IsAttached || menuBar == nullptr)
    {
        // The plugin hasn't been attached yet, so don't create the menu.
        // Don't create the menu if the menu bar is not there.
        return;
    }

    // Create the main menu item
    wxMenu* threeBlockzMenu = createMenu(menuBar);
    if (threeBlockzMenu == nullptr)
    {
        // Something went wrong. Don't carry on.
        return;
    }

    // Create each item in the 3Blockz menu
    createHashMenuItem(threeBlockzMenu);
    createEqualMenuItem(threeBlockzMenu);
    createGetSetMenuItem(threeBlockzMenu);
    createBuilderMenuItem(threeBlockzMenu);
    createAboutMenuItem(threeBlockzMenu);

    threeBlockzMenu->Enable(TBZ::GET_SET_MENU_ID, false);
    threeBlockzMenu->Enable(TBZ::BUILDER_MENU_ID, false);

    this->_threeBlockzMenu = threeBlockzMenu;
}

void ThreeBlockz::createAboutMenuItem(wxMenu* threeBlockzMenu)
{
    if (threeBlockzMenu == nullptr)
        return;

    if (threeBlockzMenu->FindItem(_("About")) == wxNOT_FOUND)
    {
        // Menu item was not found. Let's create it.
        threeBlockzMenu->AppendSeparator();
        threeBlockzMenu->Append(TBZ::ABOUT_MENU_ID, _("About"));
    }
}

void ThreeBlockz::createHashMenuItem(wxMenu* threeBlockzMenu)
{
    if (threeBlockzMenu == nullptr)
        return;

    if (threeBlockzMenu->FindItem(_("Hash Struct Generator")) == wxNOT_FOUND)
    {
        // Menu item was not found. Let's create it.
        threeBlockzMenu->Append(TBZ::HASH_MENU_ID, _("Hash Struct Generator"));
    }

    // Register tool
    registerTool(TBZ::HASH_MENU_ID, std::make_shared<HashToolHandler>());
}

void ThreeBlockz::createEqualMenuItem(wxMenu* threeBlockzMenu)
{
    if (threeBlockzMenu == nullptr)
        return;

    if (threeBlockzMenu->FindItem(_("Operator== Overload Generator")) == wxNOT_FOUND)
    {
        // Menu item was not found. Let's create it.
        threeBlockzMenu->Append(TBZ::OP_EQ_MENU_ID, _("Operator== Overload Generator"));
    }

    // Register Tool
    registerTool(TBZ::OP_EQ_MENU_ID, std::make_shared<OpEqOverloadToolHandler>());
}

void ThreeBlockz::createGetSetMenuItem(wxMenu* threeBlockzMenu)
{
    if (threeBlockzMenu == nullptr)
        return;

    if (threeBlockzMenu->FindItem(_("Getters and Setters Generator")) == wxNOT_FOUND)
    {
        // Menu item was not found. Let's create it.
        threeBlockzMenu->Append(TBZ::GET_SET_MENU_ID, _("Getters and Setters Generator"));
    }
}

void ThreeBlockz::createBuilderMenuItem(wxMenu* threeBlockzMenu)
{
    if (threeBlockzMenu == nullptr)
        return;

    if (threeBlockzMenu->FindItem(_("Class Builder Generator")) == wxNOT_FOUND)
    {
        // Menu item was not found. Let's create it.
        threeBlockzMenu->Append(TBZ::BUILDER_MENU_ID, _("Class Builder Generator"));
    }
}

wxMenu* ThreeBlockz::createMenu(wxMenuBar* menuBar)
{
    if (menuBar == nullptr)
        return nullptr;

    int id = menuBar->FindMenu(_("3Blockz"));

    if (id == wxNOT_FOUND)
    {
        // Menu item not found. Let's create it.
        wxMenu* menu = new wxMenu();

        if (!menuBar->Append(menu, _("3Blockz")))
        {
            // Could not append the menu, so we can try again later.
            delete menu;

            return nullptr;
        }

        return menu;
    }

    return menuBar->GetMenu(id);
}

void ThreeBlockz::BuildModuleMenu(const ModuleType type, wxMenu* menu, const FileTreeData* data)
{
    //Some library module is ready to display a pop-up menu.
    //Check the parameter \"type\" and see which module it is
    //and append any items you need in the menu...
    //TIP: for consistency, add a separator as the first item...
}

void ThreeBlockz::menuItemCommandEvent(wxCommandEvent& event)
{
    if (this->_tbToolMap.count(event.GetId()) == 1)
    {
        this->_tbToolMap[event.GetId()]->showUI();
    }
}

void ThreeBlockz::registerTool(long id, shared_ptr<TBToolHandler> tool)
{
    this->_tbToolMap[id] = tool;
}
