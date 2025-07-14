#pragma once
#include <Wt/WContainerWidget.h>
#include <string>
#include "../../models/FeatureModel.h"

namespace CSPNet {
namespace Views {
namespace Components {

class CreditCard : public Wt::WContainerWidget {
public:
    explicit CreditCard(const Models::CreditModel& credit);
    
    void setupCard();
    void setupContent();
    
private:
    Models::CreditModel credit_;
    
    void createCardStructure();
    void addHoverEffects();
};

} // namespace Components
} // namespace Views
} // namespace CSPNet