#pragma once
#include <Wt/WContainerWidget.h>
#include <string>
#include "../../models/FeatureModel.h"

namespace CSPNet {
namespace Views {
namespace Components {

class FeatureCard : public Wt::WContainerWidget {
public:
    explicit FeatureCard(const Models::FeatureModel& feature);
    
    void setupCard();
    void setupContent();
    
private:
    Models::FeatureModel feature_;
    
    void createCardStructure();
    void addHoverEffects();
};

} // namespace Components
} // namespace Views
} // namespace CSPNet