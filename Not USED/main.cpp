// Fix for filesystem compatibility
#include <experimental/filesystem>
namespace std {
    namespace filesystem = experimental::filesystem;
}

#include <Wt/WApplication.h>
#include <Wt/WContainerWidget.h>
#include <Wt/WText.h>
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WPushButton.h>
#include <Wt/WStackedWidget.h>
#include <Wt/WServer.h>
#include <Wt/WEnvironment.h>
#include <iostream>
#include <memory>

using namespace Wt;

// Apple-Inspired Premium Application
class CSPNetApp : public WApplication {
private:
    WStackedWidget* contentStack_;
    WText* homeNavItem_;
    WText* creditsNavItem_;
    
public:
    CSPNetApp(const WEnvironment& env) : WApplication(env) {
        setTitle("CSP-NET • Premium Platform");
        
        // Add comprehensive Apple design system using proper Wt method
        setupAppleDesignSystem();
        
        // Main container
        auto container = root()->addWidget(std::make_unique<WContainerWidget>());
        container->setStyleClass("app-container");
        
        auto layout = container->setLayout(std::make_unique<WVBoxLayout>());
        layout->setContentsMargins(0, 0, 0, 0);
        layout->setSpacing(0);
        
        // Create navigation
        createNavigation(layout);
        
        // Create content stack
        contentStack_ = layout->addWidget(std::make_unique<WStackedWidget>());
        contentStack_->setStyleClass("content-stack");
        
        // Create pages
        createHomePage();
        createCreditsPage();
        
        // Set initial page
        showHomePage();
    }
    
private:
    void setupAppleDesignSystem() {
        auto& styleSheet = WApplication::instance()->styleSheet();
        
        // Base reset and typography
        styleSheet.addRule("*", 
            "margin: 0; "
            "padding: 0; "
            "box-sizing: border-box;"
        );
        
        styleSheet.addRule("html, body", 
            "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif; "
            "-webkit-font-smoothing: antialiased; "
            "-moz-osx-font-smoothing: grayscale; "
            "background: #000000; "
            "color: #f5f5f7; "
            "line-height: 1.47; "
            "overflow-x: hidden; "
            "min-height: 100vh;"
        );
        
        // App container
        styleSheet.addRule(".app-container", 
            "min-height: 100vh; "
            "background: linear-gradient(135deg, #000000 0%, #1d1d1f 50%, #000000 100%);"
        );
        
        // Apple Navigation Bar
        styleSheet.addRule(".nav-bar", 
            "background: rgba(29, 29, 31, 0.8); "
            "backdrop-filter: saturate(180%) blur(20px); "
            "-webkit-backdrop-filter: saturate(180%) blur(20px); "
            "border-bottom: 0.5px solid rgba(255, 255, 255, 0.1); "
            "height: 52px; "
            "position: sticky; "
            "top: 0; "
            "z-index: 9999;"
        );
        
        styleSheet.addRule(".nav-container", 
            "max-width: 1200px; "
            "margin: 0 auto; "
            "height: 52px; "
            "display: flex; "
            "align-items: center; "
            "justify-content: space-between; "
            "padding: 0 20px;"
        );
        
        styleSheet.addRule(".nav-logo", 
            "font-size: 21px; "
            "font-weight: 600; "
            "color: #f5f5f7; "
            "letter-spacing: -0.022em;"
        );
        
        styleSheet.addRule(".nav-menu", 
            "display: flex; "
            "gap: 32px; "
            "align-items: center;"
        );
        
        styleSheet.addRule(".nav-item", 
            "color: #f5f5f7; "
            "font-size: 17px; "
            "font-weight: 400; "
            "text-decoration: none; "
            "padding: 8px 16px; "
            "border-radius: 20px; "
            "transition: all 0.3s ease; "
            "cursor: pointer; "
            "opacity: 0.8;"
        );
        
        styleSheet.addRule(".nav-item:hover", 
            "opacity: 1; "
            "background: rgba(255, 255, 255, 0.1); "
            "transform: translateY(-1px);"
        );
        
        styleSheet.addRule(".nav-item.active", 
            "opacity: 1; "
            "background: rgba(255, 255, 255, 0.15); "
            "color: #ffffff;"
        );
        
        // Content stack
        styleSheet.addRule(".content-stack", 
            "flex: 1;"
        );
        
        // Page styles
        styleSheet.addRule(".page", 
            "min-height: calc(100vh - 52px); "
            "padding: 80px 20px; "
            "overflow: visible;"
        );
        
        styleSheet.addRule(".page-container", 
            "max-width: 1200px; "
            "margin: 0 auto; "
            "text-align: center; "
            "overflow: visible;"
        );
        
        // Hero section
        styleSheet.addRule(".hero", 
            "margin-bottom: 80px;"
        );
        
        styleSheet.addRule(".hero-title", 
            "font-size: clamp(48px, 8vw, 96px); "
            "font-weight: 700; "
            "letter-spacing: -0.055em; "
            "margin-bottom: 24px; "
            "background: linear-gradient(135deg, #ffffff 0%, #f5f5f7 25%, #d1d1d6 75%, #a1a1a6 100%); "
            "-webkit-background-clip: text; "
            "-webkit-text-fill-color: transparent; "
            "background-clip: text; "
            "line-height: 1.05;"
        );
        
        styleSheet.addRule(".hero-subtitle", 
            "font-size: clamp(21px, 3vw, 28px); "
            "font-weight: 400; "
            "color: rgba(245, 245, 247, 0.7); "
            "margin-bottom: 48px; "
            "letter-spacing: -0.022em; "
            "line-height: 1.14;"
        );
        
        // Feature grid
        styleSheet.addRule(".features", 
            "display: grid; "
            "grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); "
            "gap: 24px; "
            "margin: 60px 0; "
            "padding: 20px 0; "
            "overflow: visible;"
        );
        
        styleSheet.addRule(".feature-card", 
            "background: rgba(255, 255, 255, 0.05); "
            "backdrop-filter: blur(20px); "
            "-webkit-backdrop-filter: blur(20px); "
            "border: 1px solid rgba(255, 255, 255, 0.1); "
            "border-radius: 20px; "
            "padding: 40px 32px; "
            "transition: all 0.4s ease; "
            "position: relative; "
            "overflow: hidden;"
        );
        
        styleSheet.addRule(".feature-card::before", 
            "content: ''; "
            "position: absolute; "
            "top: 0; "
            "left: 0; "
            "right: 0; "
            "height: 1px; "
            "background: linear-gradient(90deg, transparent, rgba(255, 255, 255, 0.4), transparent);"
        );
        
        styleSheet.addRule(".feature-card:hover", 
            "transform: translateY(-8px); "
            "background: rgba(255, 255, 255, 0.08); "
            "border-color: rgba(255, 255, 255, 0.2); "
            "box-shadow: 0 20px 40px rgba(0, 0, 0, 0.3);"
        );
        
        styleSheet.addRule(".feature-title", 
            "font-size: 22px; "
            "font-weight: 600; "
            "color: #f5f5f7; "
            "margin-bottom: 16px; "
            "letter-spacing: -0.022em;"
        );
        
        styleSheet.addRule(".feature-desc", 
            "font-size: 17px; "
            "color: rgba(245, 245, 247, 0.7); "
            "line-height: 1.47; "
            "letter-spacing: -0.022em;"
        );
        
        // CTA Button
        styleSheet.addRule(".cta-button", 
            "background: #0071e3; "
            "color: #ffffff; "
            "border: none; "
            "border-radius: 980px; "
            "padding: 18px 36px; "
            "font-size: 19px; "
            "font-weight: 500; "
            "letter-spacing: -0.022em; "
            "cursor: pointer; "
            "transition: all 0.3s ease; "
            "margin-top: 60px; "
            "box-shadow: 0 4px 14px rgba(0, 113, 227, 0.4);"
        );
        
        styleSheet.addRule(".cta-button:hover", 
            "background: #0077ed; "
            "transform: translateY(-2px); "
            "box-shadow: 0 8px 25px rgba(0, 113, 227, 0.6);"
        );
        
        // Credits page
        styleSheet.addRule(".credits-grid", 
            "display: grid; "
            "grid-template-columns: repeat(auto-fit, minmax(350px, 1fr)); "
            "gap: 40px; "
            "margin-top: 60px; "
            "padding: 30px 0; "
            "overflow: visible;"
        );
        
        styleSheet.addRule(".credit-card", 
            "background: rgba(255, 255, 255, 0.05); "
            "backdrop-filter: blur(20px); "
            "-webkit-backdrop-filter: blur(20px); "
            "border: 1px solid rgba(255, 255, 255, 0.1); "
            "border-radius: 24px; "
            "padding: 60px 40px; "
            "transition: all 0.4s ease; "
            "text-align: center;"
        );
        
        styleSheet.addRule(".credit-card:hover", 
            "transform: translateY(-12px); "
            "background: rgba(255, 255, 255, 0.08); "
            "border-color: rgba(255, 255, 255, 0.2); "
            "box-shadow: 0 25px 50px rgba(0, 0, 0, 0.4);"
        );
        
        styleSheet.addRule(".credit-name", 
            "font-size: 32px; "
            "font-weight: 600; "
            "color: #f5f5f7; "
            "margin-bottom: 16px; "
            "letter-spacing: -0.022em;"
        );
        
        styleSheet.addRule(".credit-role", 
            "font-size: 18px; "
            "color: rgba(245, 245, 247, 0.7); "
            "font-weight: 400; "
            "letter-spacing: -0.022em;"
        );
        
        // Tech stack
        styleSheet.addRule(".tech-stack", 
            "margin-top: 80px; "
            "padding-top: 60px; "
            "border-top: 1px solid rgba(255, 255, 255, 0.1);"
        );
        
        styleSheet.addRule(".tech-label", 
            "font-size: 15px; "
            "color: #a1a1a6; "
            "margin-bottom: 20px; "
            "text-transform: uppercase; "
            "letter-spacing: 2px; "
            "font-weight: 500;"
        );
        
        styleSheet.addRule(".tech-items", 
            "font-size: 18px; "
            "color: #d1d1d6; "
            "font-weight: 400; "
            "letter-spacing: -0.022em;"
        );
        
        // Responsive design
        styleSheet.addRule("@media (max-width: 768px)", 
            ".nav-container { padding: 0 16px; } "
            ".nav-menu { gap: 20px; } "
            ".page { padding: 40px 16px; } "
            ".features { grid-template-columns: 1fr; } "
            ".credits-grid { grid-template-columns: 1fr; } "
            ".feature-card, .credit-card { padding: 32px 24px; }"
        );
    }
    
    void createNavigation(WVBoxLayout* layout) {
        auto navBar = layout->addWidget(std::make_unique<WContainerWidget>());
        navBar->setStyleClass("nav-bar");
        
        auto navContainer = navBar->addWidget(std::make_unique<WContainerWidget>());
        navContainer->setStyleClass("nav-container");
        
        auto navLayout = navContainer->setLayout(std::make_unique<WHBoxLayout>());
        navLayout->setContentsMargins(0, 0, 0, 0);
        
        // Logo
        auto logo = navLayout->addWidget(std::make_unique<WText>("CSP-NET"));
        logo->setStyleClass("nav-logo");
        
        navLayout->addStretch(1);
        
        // Navigation menu
        auto navMenu = navLayout->addWidget(std::make_unique<WContainerWidget>());
        navMenu->setStyleClass("nav-menu");
        
        auto menuLayout = navMenu->setLayout(std::make_unique<WHBoxLayout>());
        menuLayout->setContentsMargins(0, 0, 0, 0);
        
        // Home link
        homeNavItem_ = menuLayout->addWidget(std::make_unique<WText>("Home"));
        homeNavItem_->setStyleClass("nav-item active");
        homeNavItem_->clicked().connect([=]() {
            showHomePage();
        });
        
        // Credits link
        creditsNavItem_ = menuLayout->addWidget(std::make_unique<WText>("Credits"));
        creditsNavItem_->setStyleClass("nav-item");
        creditsNavItem_->clicked().connect([=]() {
            showCreditsPage();
        });
    }
    
    void createHomePage() {
        auto page = contentStack_->addWidget(std::make_unique<WContainerWidget>());
        page->setStyleClass("page");
        
        auto container = page->addWidget(std::make_unique<WContainerWidget>());
        container->setStyleClass("page-container");
        
        auto layout = container->setLayout(std::make_unique<WVBoxLayout>());
        layout->setContentsMargins(0, 0, 0, 0);
        
        // Hero section
        auto hero = layout->addWidget(std::make_unique<WContainerWidget>());
        hero->setStyleClass("hero");
        
        auto heroLayout = hero->setLayout(std::make_unique<WVBoxLayout>());
        heroLayout->setContentsMargins(0, 0, 0, 0);
        
        auto title = heroLayout->addWidget(std::make_unique<WText>("CSP-NET"));
        title->setStyleClass("hero-title");
        
        auto subtitle = heroLayout->addWidget(std::make_unique<WText>("Premium Web Platform"));
        subtitle->setStyleClass("hero-subtitle");
        
        // Features grid with extra spacing
        auto features = layout->addWidget(std::make_unique<WContainerWidget>());
        features->setStyleClass("features");
        features->setAttributeValue("style", 
            "display: grid; "
            "grid-template-columns: repeat(auto-fit, minmax(300px, 1fr)); "
            "gap: 24px; "
            "margin-top: 80px; "
            "margin-bottom: 60px;"
        );
        
        createFeatureCard(features, "Modern Architecture", "Built with Drogon C++ framework for high-performance backend operations");
        createFeatureCard(features, "Premium UI", "Wt Framework components with Apple-inspired design system and interactions");
        createFeatureCard(features, "Enterprise Ready", "Scalable, secure, and production-ready platform from day one");
        
        // CTA Button with proper spacing
        auto buttonContainer = layout->addWidget(std::make_unique<WContainerWidget>());
        buttonContainer->setAttributeValue("style", 
            "margin-top: 60px; "
            "margin-bottom: 40px; "
            "text-align: center; "
            "padding: 40px; "
            "overflow: visible;"
        );
        
        auto button = buttonContainer->addWidget(std::make_unique<WPushButton>("Get Started"));
        button->setAttributeValue("style", 
            "background: linear-gradient(135deg, #007aff 0%, #0056cc 100%); "
            "color: #ffffff; "
            "border: none; "
            "border-radius: 50px; "
            "padding: 20px 40px; "
            "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif; "
            "font-size: 18px; "
            "font-weight: 600; "
            "letter-spacing: -0.01em; "
            "cursor: pointer; "
            "transition: all 0.4s cubic-bezier(0.175, 0.885, 0.32, 1.275); "
            "box-shadow: 0 8px 30px rgba(0, 122, 255, 0.4), 0 4px 15px rgba(0, 122, 255, 0.2); "
            "backdrop-filter: blur(10px); "
            "position: relative; "
            "overflow: hidden; "
            "text-shadow: 0 1px 2px rgba(0, 0, 0, 0.1);"
        );
        
        // Add enhanced hover effects
        button->mouseWentOver().connect([button]() {
            button->setAttributeValue("style", 
                "background: linear-gradient(135deg, #0084ff 0%, #0066ff 100%); "
                "color: #ffffff; "
                "border: none; "
                "border-radius: 50px; "
                "padding: 20px 40px; "
                "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif; "
                "font-size: 18px; "
                "font-weight: 600; "
                "letter-spacing: -0.01em; "
                "cursor: pointer; "
                "transition: all 0.4s cubic-bezier(0.175, 0.885, 0.32, 1.275); "
                "box-shadow: 0 12px 40px rgba(0, 122, 255, 0.6), 0 8px 25px rgba(0, 122, 255, 0.3); "
                "backdrop-filter: blur(10px); "
                "position: relative; "
                "overflow: hidden; "
                "text-shadow: 0 1px 2px rgba(0, 0, 0, 0.1); "
                "transform: translateY(-3px) scale(1.02);"
            );
        });
        
        button->mouseWentOut().connect([button]() {
            button->setAttributeValue("style", 
                "background: linear-gradient(135deg, #007aff 0%, #0056cc 100%); "
                "color: #ffffff; "
                "border: none; "
                "border-radius: 50px; "
                "padding: 20px 40px; "
                "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif; "
                "font-size: 18px; "
                "font-weight: 600; "
                "letter-spacing: -0.01em; "
                "cursor: pointer; "
                "transition: all 0.4s cubic-bezier(0.175, 0.885, 0.32, 1.275); "
                "box-shadow: 0 8px 30px rgba(0, 122, 255, 0.4), 0 4px 15px rgba(0, 122, 255, 0.2); "
                "backdrop-filter: blur(10px); "
                "position: relative; "
                "overflow: hidden; "
                "text-shadow: 0 1px 2px rgba(0, 0, 0, 0.1); "
                "transform: translateY(0) scale(1);"
            );
        });
        
        // Tech stack
        auto techStack = layout->addWidget(std::make_unique<WContainerWidget>());
        techStack->setStyleClass("tech-stack");
        
        auto techLayout = techStack->setLayout(std::make_unique<WVBoxLayout>());
        techLayout->setContentsMargins(0, 0, 0, 0);
        
        auto techLabel = techLayout->addWidget(std::make_unique<WText>("Powered By"));
        techLabel->setStyleClass("tech-label");
        
        auto techItems = techLayout->addWidget(std::make_unique<WText>("Drogon • Wt Framework • C++17 • Modern Web Standards"));
        techItems->setStyleClass("tech-items");
    }
    
    void createCreditsPage() {
        auto page = contentStack_->addWidget(std::make_unique<WContainerWidget>());
        page->setStyleClass("page");
        
        auto container = page->addWidget(std::make_unique<WContainerWidget>());
        container->setStyleClass("page-container");
        
        auto layout = container->setLayout(std::make_unique<WVBoxLayout>());
        layout->setContentsMargins(0, 0, 0, 0);
        
        // Hero section
        auto hero = layout->addWidget(std::make_unique<WContainerWidget>());
        hero->setStyleClass("hero");
        
        auto heroLayout = hero->setLayout(std::make_unique<WVBoxLayout>());
        heroLayout->setContentsMargins(0, 0, 0, 0);
        
        auto title = heroLayout->addWidget(std::make_unique<WText>("Credits"));
        title->setStyleClass("hero-title");
        
        auto subtitle = heroLayout->addWidget(std::make_unique<WText>("Built with passion by"));
        subtitle->setStyleClass("hero-subtitle");
        
        // Credits grid with extra spacing
        auto credits = layout->addWidget(std::make_unique<WContainerWidget>());
        credits->setStyleClass("credits-grid");
        credits->setAttributeValue("style", 
            "display: grid; "
            "grid-template-columns: repeat(auto-fit, minmax(350px, 1fr)); "
            "gap: 40px; "
            "margin-top: 80px;"
        );
        
        createCreditCard(credits, "Zerohexer", "Project Creator & Developer");
        createCreditCard(credits, "Claude Code", "AI Development Assistant");
    }
    
    void createFeatureCard(WContainerWidget* parent, const std::string& title, const std::string& description) {
        auto card = parent->addWidget(std::make_unique<WContainerWidget>());
        card->setStyleClass("feature-card");
        
        auto layout = card->setLayout(std::make_unique<WVBoxLayout>());
        layout->setContentsMargins(0, 0, 0, 0);
        
        auto titleWidget = layout->addWidget(std::make_unique<WText>(title));
        titleWidget->setStyleClass("feature-title");
        
        auto descWidget = layout->addWidget(std::make_unique<WText>(description));
        descWidget->setStyleClass("feature-desc");
    }
    
    void createCreditCard(WContainerWidget* parent, const std::string& name, const std::string& role) {
        auto card = parent->addWidget(std::make_unique<WContainerWidget>());
        card->setStyleClass("credit-card");
        
        auto layout = card->setLayout(std::make_unique<WVBoxLayout>());
        layout->setContentsMargins(0, 0, 0, 0);
        
        auto nameWidget = layout->addWidget(std::make_unique<WText>(name));
        nameWidget->setStyleClass("credit-name");
        
        auto roleWidget = layout->addWidget(std::make_unique<WText>(role));
        roleWidget->setStyleClass("credit-role");
    }
    
    void showHomePage() {
        contentStack_->setCurrentIndex(0);
        homeNavItem_->setStyleClass("nav-item active");
        creditsNavItem_->setStyleClass("nav-item");
    }
    
    void showCreditsPage() {
        contentStack_->setCurrentIndex(1);
        homeNavItem_->setStyleClass("nav-item");
        creditsNavItem_->setStyleClass("nav-item active");
    }
};

// Application creation function
std::unique_ptr<WApplication> createApplication(const WEnvironment& env) {
    return std::make_unique<CSPNetApp>(env);
}

int main(int argc, char* argv[]) {
    try {
        std::cout << R"(
   ──────────────────────────────────────────────────────────────
   
                     CSP-NET • Premium Platform
   
        Apple-Inspired Design • Proper Wt CSS • Premium UI
   
   ──────────────────────────────────────────────────────────────
        )" << std::endl;

        // Setup Wt server
        WServer server(argc, argv, WTHTTP_CONFIGURATION);
        server.addEntryPoint(EntryPointType::Application, createApplication);
        
        if (server.start()) {
            std::cout << "\n🎉 CSP-NET Platform Ready!" << std::endl;
            std::cout << "Frontend:    http://localhost:8080" << std::endl;
            std::cout << "Framework:   Wt with proper Apple CSS styling" << std::endl;
            std::cout << "Navigation:  Home • Credits (fully functional)" << std::endl;
            std::cout << "CSS Method:  styleSheet().addRule() (recommended)" << std::endl;
            std::cout << "\nPress Ctrl+C to stop\n" << std::endl;
            
            WServer::waitForShutdown();
        }
        
        std::cout << "CSP-NET Platform stopped" << std::endl;
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
}