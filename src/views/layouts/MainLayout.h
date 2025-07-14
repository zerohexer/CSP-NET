#pragma once
#include <Wt/WContainerWidget.h>
#include <Wt/WStackedWidget.h>
#include <functional>
#include "../components/Navigation.h"

namespace CSPNet {
namespace Views {
namespace Layouts {

class MainLayout : public Wt::WContainerWidget {
public:
    MainLayout();
    
    void setupLayout();
    Wt::WStackedWidget* getContentStack() { return contentStack_; }
    Components::Navigation* getNavigation() { return navigation_; }
    
    void navigateToPage(const std::string& page);
    void setNavigationCallback(std::function<void(const std::string&)> callback);
    
private:
    Components::Navigation* navigation_;
    Wt::WStackedWidget* contentStack_;
    std::function<void(const std::string&)> navigationCallback_;
    
    void createLayoutStructure();
    void setupLayoutStyles();
};

} // namespace Layouts
} // namespace Views
} // namespace CSPNet