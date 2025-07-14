#include "Navigation.h"
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WText.h>

namespace CSPNet {
namespace Views {
namespace Components {

Navigation::Navigation(std::function<void(const std::string&)> onNavigate)
    : onNavigate_(onNavigate), activePage_("home"), homeNavItem_(nullptr), creditsNavItem_(nullptr) {
    setupNavigation();
}

void Navigation::setupNavigation() {
    setStyleClass("nav-bar");
    createNavigationStructure();
}

void Navigation::createNavigationStructure() {
    auto navContainer = addWidget(std::make_unique<Wt::WContainerWidget>());
    navContainer->setStyleClass("nav-container");
    
    auto navLayout = navContainer->setLayout(std::make_unique<Wt::WHBoxLayout>());
    navLayout->setContentsMargins(0, 0, 0, 0);
    
    // Logo
    auto logo = navLayout->addWidget(std::make_unique<Wt::WText>("CSP-NET"));
    logo->setStyleClass("nav-logo");
    
    navLayout->addStretch(1);
    
    // Navigation menu
    auto navMenu = navLayout->addWidget(std::make_unique<Wt::WContainerWidget>());
    navMenu->setStyleClass("nav-menu");
    
    auto menuLayout = navMenu->setLayout(std::make_unique<Wt::WHBoxLayout>());
    menuLayout->setContentsMargins(0, 0, 0, 0);
    
    // Home link
    homeNavItem_ = menuLayout->addWidget(std::make_unique<Wt::WText>("Home"));
    homeNavItem_->setStyleClass("nav-item active");
    homeNavItem_->clicked().connect([=]() {
        onNavigate_("home");
    });
    
    // Credits link
    creditsNavItem_ = menuLayout->addWidget(std::make_unique<Wt::WText>("Credits"));
    creditsNavItem_->setStyleClass("nav-item");
    creditsNavItem_->clicked().connect([=]() {
        onNavigate_("credits");
    });
}

void Navigation::setActivePage(const std::string& page) {
    activePage_ = page;
    updateNavigationStyles();
}

void Navigation::updateNavigationStyles() {
    if (homeNavItem_) {
        if (activePage_ == "home") {
            homeNavItem_->setStyleClass("nav-item active");
        } else {
            homeNavItem_->setStyleClass("nav-item");
        }
    }
    
    if (creditsNavItem_) {
        if (activePage_ == "credits") {
            creditsNavItem_->setStyleClass("nav-item active");
        } else {
            creditsNavItem_->setStyleClass("nav-item");
        }
    }
}

} // namespace Components
} // namespace Views
} // namespace CSPNet