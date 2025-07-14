#pragma once
#include <memory>
#include <Wt/WContainerWidget.h>
#include <Wt/WStackedWidget.h>
#include "../views/pages/CreditsPage.h"

namespace CSPNet {
namespace Controllers {

class CreditsController {
public:
    CreditsController();
    
    std::unique_ptr<Views::Pages::CreditsPage> createView();
    Wt::WContainerWidget* createPageContent(Wt::WStackedWidget* contentStack);
    void handleCreditInteraction(const std::string& creditId);
    
private:
    void setupController();
};

} // namespace Controllers
} // namespace CSPNet