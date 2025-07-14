#include "CreditCard.h"
#include <Wt/WVBoxLayout.h>
#include <Wt/WText.h>

namespace CSPNet {
namespace Views {
namespace Components {

CreditCard::CreditCard(const Models::CreditModel& credit) : credit_(credit) {
    setupCard();
}

void CreditCard::setupCard() {
    setStyleClass("credit-card");
    createCardStructure();
}

void CreditCard::createCardStructure() {
    auto layout = setLayout(std::make_unique<Wt::WVBoxLayout>());
    layout->setContentsMargins(0, 0, 0, 0);
    
    auto nameWidget = layout->addWidget(std::make_unique<Wt::WText>(credit_.name));
    nameWidget->setStyleClass("credit-name");
    
    auto roleWidget = layout->addWidget(std::make_unique<Wt::WText>(credit_.role));
    roleWidget->setStyleClass("credit-role");
}

} // namespace Components
} // namespace Views
} // namespace CSPNet