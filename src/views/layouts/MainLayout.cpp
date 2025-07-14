#include "MainLayout.h"
#include <Wt/WVBoxLayout.h>

namespace CSPNet {
namespace Views {
namespace Layouts {

MainLayout::MainLayout() : navigation_(nullptr), contentStack_(nullptr) {
    setupLayout();
}

void MainLayout::setupLayout() {
    setStyleClass("app-container");
    createLayoutStructure();
}

void MainLayout::createLayoutStructure() {
    auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
    
    // Create navigation
    navigation_ = layout->addWidget(std::make_unique<Components::Navigation>(
        [this](const std::string& page) {
            if (navigationCallback_) {
                navigationCallback_(page);
            }
        }
    ));
    
    // Create content stack
    contentStack_ = layout->addWidget(std::make_unique<Wt::WStackedWidget>());
    contentStack_->setStyleClass("content-stack");
}

void MainLayout::navigateToPage(const std::string& page) {
    if (page == "home") {
        contentStack_->setCurrentIndex(0);
        navigation_->setActivePage("home");
    } else if (page == "credits") {
        contentStack_->setCurrentIndex(1);
        navigation_->setActivePage("credits");
    }
}

void MainLayout::setNavigationCallback(std::function<void(const std::string&)> callback) {
    navigationCallback_ = callback;
}

} // namespace Layouts
} // namespace Views
} // namespace CSPNet