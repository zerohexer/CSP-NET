#include "Application.h"
#include <Wt/WServer.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WPushButton.h>
#include <Wt/WContainerWidget.h>
#include <iostream>
#include "../styles/DesignSystem.h"
#include "../styles/AppleTheme.h"
#include "../builders/HomePageBuilder.h"
#include "../builders/CreditsPageBuilder.h"

namespace CSPNet {
namespace App {

Application::Application(const Wt::WEnvironment& env) 
    : WApplication(env), mainLayout_(nullptr), homePage_(nullptr), creditsPage_(nullptr) {
    setupApplication();
}

void Application::setupApplication() {
    setTitle("CSP-NET • Premium Platform");
    
    // Setup design system first
    setupDesignSystem();
    
    // Initialize controllers
    setupControllers();
    
    // Create main layout with navigation callback
    mainLayout_ = root()->addWidget(std::make_unique<Views::Layouts::MainLayout>());
    
    // Set up navigation callback
    mainLayout_->setNavigationCallback([this](const std::string& page) {
        handleNavigation(page);
    });
    
    // Setup routing
    setupRouting();
    
    // Create and add pages
    setupPages();
    
    // Set initial route
    navigateToHome();
}

void Application::setupDesignSystem() {
    // Setup core design system
    Styles::DesignSystem::setupGlobalStyles();
    Styles::DesignSystem::setupComponentStyles();
    Styles::DesignSystem::setupLayoutStyles();
    Styles::DesignSystem::setupResponsiveStyles();
    
    // Setup Apple theme
    Styles::AppleTheme::setupAppleDesignSystem();
}

void Application::setupControllers() {
    homeController_ = std::make_unique<Controllers::HomeController>();
    creditsController_ = std::make_unique<Controllers::CreditsController>();
}

void Application::setupRouting() {
    router_ = std::make_unique<Router>(mainLayout_->getContentStack());
    
    // Add routes
    router_->addRoute("home", [this]() { navigateToHome(); });
    router_->addRoute("credits", [this]() { navigateToCredits(); });
}

void Application::setupPages() {
    auto contentStack = mainLayout_->getContentStack();
    
    // Clean Modular Architecture: Use specialized builders
    homePage_ = Builders::HomePageBuilder::build(contentStack);
    creditsPage_ = Builders::CreditsPageBuilder::build(contentStack);
    
    // Show home page by default
    contentStack->setCurrentIndex(0);
}

void Application::navigateToHome() {
    auto contentStack = mainLayout_->getContentStack();
    contentStack->setCurrentIndex(0);
    router_->setCurrentRoute("home");
    
    // Update navigation highlight
    mainLayout_->getNavigation()->setActivePage("home");
}

void Application::navigateToCredits() {
    auto contentStack = mainLayout_->getContentStack();
    contentStack->setCurrentIndex(1);
    router_->setCurrentRoute("credits");
    
    // Update navigation highlight
    mainLayout_->getNavigation()->setActivePage("credits");
}

void Application::handleNavigation(const std::string& page) {
    if (page == "home") {
        navigateToHome();
    } else if (page == "credits") {
        navigateToCredits();
    }
}



// Application factory function
std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env) {
    return std::make_unique<Application>(env);
}

} // namespace App
} // namespace CSPNet