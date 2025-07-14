#include "FeatureModel.h"

namespace CSPNet {
namespace Models {

std::vector<FeatureModel> AppData::getFeatures() {
    return {
        FeatureModel(
            "Modern Architecture", 
            "Built with Drogon C++ framework for high-performance backend operations",
            "⚡"
        ),
        FeatureModel(
            "Premium UI", 
            "Wt Framework components with Apple-inspired design system and interactions",
            "🎨"
        ),
        FeatureModel(
            "Enterprise Ready", 
            "Scalable, secure, and production-ready platform from day one",
            "🏢"
        )
    };
}

std::vector<CreditModel> AppData::getCredits() {
    return {
        CreditModel(
            "Zerohexer", 
            "Project Creator & Developer",
            "👨‍💻"
        ),
        CreditModel(
            "Claude Code", 
            "AI Development Assistant",
            "🤖"
        )
    };
}

} // namespace Models
} // namespace CSPNet