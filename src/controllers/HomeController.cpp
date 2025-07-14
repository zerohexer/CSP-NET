#include "HomeController.h"
#include <iostream>

namespace CSPNet {
namespace Controllers {

HomeController::HomeController() {
    setupController();
}

void HomeController::setupController() {
    // Initialize controller if needed
}

std::unique_ptr<Views::Pages::HomePage> HomeController::createView() {
    return std::make_unique<Views::Pages::HomePage>();
}

Wt::WContainerWidget* HomeController::createPageContent(Wt::WStackedWidget* contentStack) {
    // Create the home page view
    auto homePage = contentStack->addWidget(std::make_unique<Views::Pages::HomePage>());
    return homePage;
}

void HomeController::handleGetStartedClick() {
    std::cout << "Get Started button clicked!" << std::endl;
    // Handle button logic here - could navigate, show modal, etc.
}

void HomeController::handleFeatureInteraction(const std::string& featureId) {
    std::cout << "Feature interaction: " << featureId << std::endl;
    // Handle feature card interactions
}

} // namespace Controllers
} // namespace CSPNet