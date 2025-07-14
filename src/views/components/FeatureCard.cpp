#include "FeatureCard.h"
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>

namespace CSPNet {
namespace Views {
namespace Components {

FeatureCard::FeatureCard(const Models::FeatureModel& feature) : feature_(feature) {
    setupCard();
}

void FeatureCard::setupCard() {
    setStyleClass("feature-card");
    createCardStructure();
}

void FeatureCard::createCardStructure() {
    auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    
    auto titleWidget = layout->addWidget(std::make_unique<Wt::WText>(feature_.title));
    titleWidget->setStyleClass("feature-title");
    
    auto descWidget = layout->addWidget(std::make_unique<Wt::WText>(feature_.description));
    descWidget->setStyleClass("feature-desc");
}

} // namespace Components
} // namespace Views
} // namespace CSPNet