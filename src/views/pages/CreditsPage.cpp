#include "CreditsPage.h"
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>
#include "../components/CreditCard.h"
#include "../../models/FeatureModel.h"

namespace CSPNet {
namespace Views {
namespace Pages {

CreditsPage::CreditsPage() {
    setupPage();
}

void CreditsPage::setupPage() {
    setStyleClass("page");
    createPageStructure();
}

void CreditsPage::createPageStructure() {
    auto container = addWidget(std::make_unique<Wt::WContainerWidget>());
    container->setStyleClass("page-container");
    
    auto layout = container->setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    
    createHeroSection(container);
    createCreditsSection(container);
}

void CreditsPage::createHeroSection(Wt::WContainerWidget* parent) {
    auto hero = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    hero->setStyleClass("hero");
    
    auto heroLayout = hero->setLayout(std::make_unique<Wt::WVBoxLayout>());
    heroLayout->setContentsMargins(0, 0, 0, 0);
    
    auto title = heroLayout->addWidget(std::make_unique<Wt::WText>("Credits"));
    title->setStyleClass("hero-title");
    
    auto subtitle = heroLayout->addWidget(std::make_unique<Wt::WText>("Built with passion by"));
    subtitle->setStyleClass("hero-subtitle");
}

void CreditsPage::createCreditsSection(Wt::WContainerWidget* parent) {
    // Credits grid using proper CSS class
    auto credits = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    credits->setStyleClass("credits-grid");
    
    createCreditCard(credits, "Zerohexer", "Project Creator & Developer");
    createCreditCard(credits, "Claude Code", "AI Development Assistant");
}

void CreditsPage::createCreditCard(Wt::WContainerWidget* parent, const std::string& name, const std::string& role) {
    auto card = parent->addWidget(std::make_unique<Wt::WContainerWidget>());
    card->setStyleClass("credit-card");
    
    auto layout = card->setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    
    auto nameWidget = layout->addWidget(std::make_unique<Wt::WText>(name));
    nameWidget->setStyleClass("credit-name");
    
    auto roleWidget = layout->addWidget(std::make_unique<Wt::WText>(role));
    roleWidget->setStyleClass("credit-role");
}

} // namespace Pages
} // namespace Views
} // namespace CSPNet