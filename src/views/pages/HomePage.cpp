#include "HomePage.h"
#include <Wt/WVBoxLayout.h>
#include <Wt/WHBoxLayout.h>
#include <Wt/WText.h>
#include <Wt/WPushButton.h>
#include <iostream>

namespace CSPNet {
namespace Views {
namespace Pages {

HomePage::HomePage() {
    setupPage();
}

void HomePage::setupPage() {
    // Use inline styles instead of CSS classes to ensure visibility
    setAttributeValue("style", 
        "min-height: calc(100vh - 52px); "
        "padding: 80px 20px; "
        "overflow: visible; "
        "background: linear-gradient(135deg, #000000 0%, #1d1d1f 50%, #000000 100%);"
    );
    createPageStructure();
}

void HomePage::createPageStructure() {
    auto container = addWidget(std::make_unique<Wt::WContainerWidget>());
    container->setAttributeValue("style", 
        "max-width: 1200px; "
        "margin: 0 auto; "
        "text-align: center; "
        "overflow: visible;"
    );
    
    auto layout = container->setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    
    createHeroSection(container);
    createFeaturesSection(container);
    createCTASection(container);
    createTechStackSection(container);
}

void HomePage::createHeroSection(Wt::WContainerWidget* parent) {
    auto hero = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    hero->setAttributeValue("style", "margin-bottom: 80px;");
    
    auto heroLayout = hero->setLayout(std::make_unique<Wt::WVBoxLayout>());
    heroLayout->setContentsMargins(0, 0, 0, 0);
    
    auto title = heroLayout->addWidget(std::make_unique<Wt::WText>("CSP-NET"));
    title->setAttributeValue("style", 
        "font-size: clamp(48px, 8vw, 96px); "
        "font-weight: 700; "
        "letter-spacing: -0.055em; "
        "margin-bottom: 24px; "
        "background: linear-gradient(135deg, #ffffff 0%, #f5f5f7 25%, #d1d1d6 75%, #a1a1a6 100%); "
        "-webkit-background-clip: text; "
        "-webkit-text-fill-color: transparent; "
        "background-clip: text; "
        "line-height: 1.05; "
        "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif;"
    );
    
    auto subtitle = heroLayout->addWidget(std::make_unique<Wt::WText>("Premium Web Platform"));
    subtitle->setAttributeValue("style", 
        "font-size: clamp(21px, 3vw, 28px); "
        "font-weight: 400; "
        "color: rgba(245, 245, 247, 0.7); "
        "margin-bottom: 48px; "
        "letter-spacing: -0.022em; "
        "line-height: 1.14; "
        "font-family: -apple-system, BlinkMacSystemFont, system-ui, sans-serif;"
    );
}

void HomePage::createFeaturesSection(Wt::WContainerWidget* parent) {
    // Features grid using proper CSS class
    auto features = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    features->setStyleClass("features");
    
    createFeatureCard(features, "Modern Architecture", "Built with Drogon C++ framework for high-performance backend operations");
    createFeatureCard(features, "Premium UI", "Wt Framework components with Apple-inspired design system and interactions");
    createFeatureCard(features, "Enterprise Ready", "Scalable, secure, and production-ready platform from day one");
}

void HomePage::createFeatureCard(Wt::WContainerWidget* parent, const std::string& title, const std::string& description) {
    auto card = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    card->setStyleClass("feature-card");
    
    auto layout = card->setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    
    auto titleWidget = layout->addWidget(std::make_unique<Wt::WText>(title));
    titleWidget->setStyleClass("feature-title");
    
    auto descWidget = layout->addWidget(std::make_unique<Wt::WText>(description));
    descWidget->setStyleClass("feature-desc");
}

void HomePage::createCTASection(Wt::WContainerWidget* parent) {
    // CTA Button with proper spacing (exactly like working version)
    auto buttonContainer = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    buttonContainer->setAttributeValue("style", 
        "margin-top: 60px; "
        "margin-bottom: 40px; "
        "text-align: center; "
        "padding: 40px; "
        "overflow: visible;"
    );
    
    auto button = buttonContainer->addWidget(std::make_unique<Wt::WPushButton>("Get Started"));
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
}

void HomePage::createTechStackSection(Wt::WContainerWidget* parent) {
    // Tech stack (exactly like working version)
    auto techStack = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    techStack->setStyleClass("tech-stack");
    
    auto techLayout = techStack->setLayout(std::make_unique<Wt::WVBoxLayout>());
    techLayout->setContentsMargins(0, 0, 0, 0);
    
    auto techLabel = techLayout->addWidget(std::make_unique<Wt::WText>("Powered By"));
    techLabel->setStyleClass("tech-label");
    
    auto techItems = techLayout->addWidget(std::make_unique<Wt::WText>("Drogon • Wt Framework • C++17 • Modern Web Standards"));
    techItems->setStyleClass("tech-items");
}

} // namespace Pages
} // namespace Views
} // namespace CSPNet