#pragma once
#include <string>
#include <functional>
#include <unordered_map>
#include <Wt/WStackedWidget.h>

namespace CSPNet {
namespace App {

class Router {
public:
    Router(Wt::WStackedWidget* contentStack);
    
    void addRoute(const std::string& path, std::function<void()> handler);
    void navigate(const std::string& path);
    void setCurrentRoute(const std::string& path);
    std::string getCurrentRoute() const { return currentRoute_; }
    
private:
    Wt::WStackedWidget* contentStack_;
    std::unordered_map<std::string, std::function<void()>> routes_;
    std::string currentRoute_;
};

} // namespace App
} // namespace CSPNet