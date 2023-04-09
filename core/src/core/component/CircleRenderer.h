#pragma once
#include "_Core.h"
#include "generic/Component.h"

namespace core
{
    class CircleRenderer : public Component {
    public:
        CircleRenderer(glm::vec4 color, float thickness, float fade);
        CircleRenderer(Shr<Texture> texture, glm::vec4 color, float thickness, float fade);

        ~CircleRenderer() override { }

        void OnStart() override { }
        void OnStop() override { }
        void OnUpdate() override;
        void OnEvent(Event& event) override { }

        void SetColor(glm::vec4 color) { this->color = color; }

    private:
        Shr<Texture> texture;

        glm::vec4 color;
        float thickness;
        float fade;
    };
}


