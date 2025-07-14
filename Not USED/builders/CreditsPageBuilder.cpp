#include "CreditsPageBuilder.h"
#include "../components/ComponentFactory.h"
#include <memory>

namespace CSPNet {
namespace Builders {

Wt::WContainerWidget* CreditsPageBuilder::build(Wt::WStackedWidget* contentStack) {
    auto creditsPage = createPageContainer(contentStack);
    auto layout = setupPageLayout(creditsPage);
    
    // Build page sections in logical order
    buildHeroSection(layout);
    buildCreditsGridSection(layout);
    
    return creditsPage;
}

Wt::WContainerWidget* CreditsPageBuilder::createPageContainer(Wt::WStackedWidget* contentStack) {
    auto creditsPage = contentStack->addWidget(std::make_unique<Wt::WContainerWidget>());
    creditsPage->setAttributeValue("style", 
        "min-height: calc(100vh - 52px); "
        "padding: 80px 20px; "
        "overflow: visible; "
        "background: linear-gradient(135deg, #000000 0%, #1d1d1f 50%, #000000 100%);"
    );
    return creditsPage;
}

Wt::WVBoxLayout* CreditsPageBuilder::setupPageLayout(Wt::WContainerWidget* page) {
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

void CreditsPageBuilder::buildHeroSection(Wt::WVBoxLayout* layout) {
    auto hero = layout->addWidget(std::make_unique<Wt::WContainerWidget>());
    hero->setAttributeValue("style", "margin-bottom: 80px;");
    
    auto heroLayout = hero->setLayout(std::make_unique<Wt::WVBoxLayout>());
    heroLayout->setContentsMargins(0, 0, 0, 0);
    
    auto title = heroLayout->addWidget(std::make_unique<Wt::WText>("Credits"));
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
    
    auto subtitle = heroLayout->addWidget(std::make_unique<Wt::WText>("Built with passion by"));
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

void CreditsPageBuilder::buildCreditsGridSection(Wt::WVBoxLayout* layout) {
    auto credits = layout->addWidget(std::make_unique<Wt::WContainerWidget>());
    credits->setStyleClass("credits-grid");
    
    // Create credit cards using ComponentFactory
    Components::ComponentFactory::createCreditCard(credits, 
        "Zerohexer", 
        "Project Creator & Developer");
    
    Components::ComponentFactory::createCreditCard(credits, 
        "Claude Code", 
        "AI Development Assistant");
}

} // namespace Builders
} // namespace CSPNet