#include "Router.h"
#include <iostream>

namespace CSPNet {
namespace App {

Router::Router(Wt::WStackedWidget* contentStack) : contentStack_(contentStack), currentRoute_("home") {
}

void Router::addRoute(const std::string& path, std::function<void()> handler) {
    routes_[path] = handler;
}

void Router::navigate(const std::string& path) {
    auto it = routes_.find(path);
    if (it != routes_.end()) {
        currentRoute_ = path;
        it->second();
        std::cout << "Navigated to: " << path << std::endl;
    } else {
        std::cout << "Route not found: " << path << std::endl;
    }
}

void Router::setCurrentRoute(const std::string& path) {
    currentRoute_ = path;
}

} // namespace App
} // namespace CSPNet