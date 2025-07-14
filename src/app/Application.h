#pragma once
#include <Wt/WApplication.h>
#include <memory>
#include "../views/layouts/MainLayout.h"
#include "../controllers/HomeController.h"
#include "../controllers/CreditsController.h"
#include "Router.h"

namespace CSPNet {
namespace App {

class Application : public Wt::WApplication {
public:
    explicit Application(const Wt::WEnvironment& env);
    
private:
    // Core components
    Views::Layouts::MainLayout* mainLayout_;
    std::unique_ptr<Router> router_;
    
    // Controllers
    std::unique_ptr<Controllers::HomeController> homeController_;
    std::unique_ptr<Controllers::CreditsController> creditsController_;
    
    // Pages
    Wt::WContainerWidget* homePage_;
    Wt::WContainerWidget* creditsPage_;
    
    // Setup methods
    void setupApplication();
    void setupDesignSystem();
    void setupRouting();
    void setupControllers();
    void setupPages();
    
    // Navigation handlers
    void navigateToHome();
    void navigateToCredits();
    void handleNavigation(const std::string& page);
    
    // Clean Modular Architecture: Page creation handled by specialized builders
};

// Application factory function
std::unique_ptr<Wt::WApplication> createApplication(const Wt::WEnvironment& env);

} // namespace App
} // namespace CSPNet