#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <functional>
#include <string>

namespace CSPNet {
namespace Views {
namespace Components {

class Navigation : public Wt::WContainerWidget {
public:
    Navigation(std::function<void(const std::string&)> onNavigate);
    
    void setActivePage(const std::string& page);
    void setupNavigation();
    
private:
    std::function<void(const std::string&)> onNavigate_;
    std::string activePage_;
    Wt::WText* homeNavItem_;
    Wt::WText* creditsNavItem_;
    
    void createNavigationStructure();
    void addNavigationItem(Wt::WContainerWidget* menu, 
                          const std::string& text, 
                          const std::string& page, 
                          bool active = false);
    void updateNavigationStyles();
};

} // namespace Components
} // namespace Views
} // namespace CSPNet