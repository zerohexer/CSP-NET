#pragma once
#include <memory>
#include <Wt/WContainerWidget.h>
#include <Wt/WStackedWidget.h>
#include "../views/pages/HomePage.h"

namespace CSPNet {
namespace Controllers {

class HomeController {
public:
    HomeController();
    
    std::unique_ptr<Views::Pages::HomePage> createView();
    Wt::WContainerWidget* createPageContent(Wt::WStackedWidget* contentStack);
    void handleGetStartedClick();
    void handleFeatureInteraction(const std::string& featureId);
    
private:
    void setupController();
};

} // namespace Controllers
} // namespace CSPNet