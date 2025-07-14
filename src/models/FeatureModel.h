#pragma once
#include <string>
#include <vector>

namespace CSPNet {
namespace Models {

struct FeatureModel {
    std::string title;
    std::string description;
    std::string icon;
    
    FeatureModel(const std::string& t, const std::string& d, const std::string& i = "")
        : title(t), description(d), icon(i) {}
};

struct CreditModel {
    std::string name;
    std::string role;
    std::string avatar;
    
    CreditModel(const std::string& n, const std::string& r, const std::string& a = "")
        : name(n), role(r), avatar(a) {}
};

class AppData {
public:
    static std::vector<FeatureModel> getFeatures();
    static std::vector<CreditModel> getCredits();
};

} // namespace Models
} // namespace CSPNet