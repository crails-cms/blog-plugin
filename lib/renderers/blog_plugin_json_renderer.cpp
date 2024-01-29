#include "blog_plugin_json_renderer.hpp"
#define declare_renderer(name) void blog_plugin_json_renderer_render_##name(const Crails::Renderer&, Crails::RenderTarget&, Crails::SharedVars&)
#define add_renderer(path, name) templates.insert(std::pair<std::string, Generator>(path, blog_plugin_json_renderer_render_##name))

BlogPluginJsonRenderer::BlogPluginJsonRenderer()
{
}
