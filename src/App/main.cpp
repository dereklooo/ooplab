#include "App.hpp"

#include "Core/Context.hpp"

int main(int, char**) {
    const auto context = Core::Context::GetInstance();
    App app;

    while (!context->GetExit()) {
        switch (app.GetCurrentState()) {
            case App::State::Title:
                app.Title();
            break;
            case App::State::TitleUpdate:
                app.TitleUpgrade();
            break;
            case App::State::START:
                app.Start();
            break;
            case App::State::UPDATE:
                app.Update();
            break;

            case App::State::END:
                app.End();
            context->SetExit(true);
            break;
        }
        context->Update();
    }
    return 0;
}
