// Fix for filesystem compatibility
#include <experimental/filesystem>
namespace std {
    namespace filesystem = experimental::filesystem;
}

#include <Wt/WServer.h>
#include <iostream>
#include "app/Application.h"

using namespace Wt;

int main(int argc, char* argv[]) {
    try {
        std::cout << R"(
   ──────────────────────────────────────────────────────────────
   
                     CSP-NET • Premium Platform
   
        Apple-Inspired Design • MVC Architecture • Premium UI
   
   ──────────────────────────────────────────────────────────────
        )" << std::endl;

        // Setup Wt server
        WServer server(argc, argv, WTHTTP_CONFIGURATION);
        server.addEntryPoint(EntryPointType::Application, CSPNet::App::createApplication);
        
        if (server.start()) {
            std::cout << "\n🎉 CSP-NET Platform Ready!" << std::endl;
            std::cout << "Frontend:      http://localhost:8080" << std::endl;
            std::cout << "Architecture:  MVC + SPA Pattern" << std::endl;
            std::cout << "Framework:     Wt with Apple Design System" << std::endl;
            std::cout << "Structure:     Modular Components & Controllers" << std::endl;
            std::cout << "Navigation:    Home • Credits (SPA Routing)" << std::endl;
            std::cout << "CSS Method:    styleSheet().addRule() (recommended)" << std::endl;
            std::cout << "\nPress Ctrl+C to stop\n" << std::endl;
            
            WServer::waitForShutdown();
        }
        
        std::cout << "CSP-NET Platform stopped" << std::endl;
        return 0;
        
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
}