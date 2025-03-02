#include "RenderCommand.h"

namespace Ferret
{
    Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}
