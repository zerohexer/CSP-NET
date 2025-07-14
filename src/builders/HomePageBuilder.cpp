#include "HomePageBuilder.h"
#include "../components/ComponentFactory.h"
#include <memory>

namespace CSPNet {
namespace Builders {

Wt::WContainerWidget* HomePageBuilder::build(Wt::WStackedWidget* contentStack) {
    auto homePage = createPageContainer(contentStack);
    auto layout = setupPageLayout(homePage);
    
    // Build page sections in logical order
    buildHeroSection(layout);
    buildFeaturesSection(layout);
    buildCtaSection(layout);
    
    return homePage;
}

Wt::WContainerWidget* HomePageBuilder::createPageContainer(Wt::WStackedWidget* contentStack) {
    auto homePage = contentStack->addWidget(std::make_unique<Wt::WContainerWidget>());
    homePage->setAttributeValue("style", 
        "min-height: calc(100vh - 52px); "
        "padding: 80px 20px; "
        "overflow: visible; "
        "background: linear-gradient(135deg, #000000 0%, #1d1d1f 50%, #000000 100%);"
    );
    return homePage;
}

Wt::WVBoxLayout* HomePageBuilder::setupPageLayout(Wt::WContainerWidget* page) {
    auto container = page->addWidget(std::make_unique<Wt::WContainerWidget>());
    container->setAttributeValue("style", 
        "max-width: 1200px; "
        "margin: 0 auto; "
        "text-align: center; "
        "overflow: visible;"
    );
    
    auto layout = container->setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    return layout;
}

void HomePageBuilder::buildHeroSection(Wt::WVBoxLayout* layout) {
    auto hero = layout->addWidget(std::make_unique<Wt::WContainerWidget>());
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

void HomePageBuilder::buildFeaturesSection(Wt::WVBoxLayout* layout) {
    auto features = layout->addWidget(std::make_unique<Wt::WContainerWidget>());
    features->setStyleClass("features");
    
    // Create feature cards using ComponentFactory
    Components::ComponentFactory::createFeatureCard(features, 
        "Modern Architecture", 
        "Built with Drogon C++ framework for high-performance backend operations");
    
    Components::ComponentFactory::createFeatureCard(features, 
        "Premium UI", 
        "Wt Framework components with Apple-inspired design system and interactions");
    
    Components::ComponentFactory::createFeatureCard(features, 
        "Enterprise Ready", 
        "Scalable, secure, and production-ready platform from day one");
}

void HomePageBuilder::buildCtaSection(Wt::WVBoxLayout* layout) {
    // Create Get Started button using ComponentFactory
    auto container = layout->addWidget(std::make_unique<Wt::WContainerWidget>());
    Components::ComponentFactory::createGetStartedButton(container);
}

} // namespace Builders
} // namespace CSPNet