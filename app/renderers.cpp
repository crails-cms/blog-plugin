#include <crails/renderer.hpp>
#include <crails/cms/views/injector.hpp>
#include "app/controllers/blog.hpp"
#include "lib/renderers/blog_plugin_html_renderer.hpp"
#include "lib/renderers/blog_plugin_json_renderer.hpp"
#include "lib/renderers/blog_plugin_rss_renderer.hpp"
#include <iostream>

static void initialize_renderer(const Crails::Renderers& renderers, const Crails::Renderer& source)
{
  for (auto it = renderers.begin() ; it != renderers.end() ; ++it)
  {
    const Crails::Renderer* renderer = it->get();

    if (*renderer->get_mimetypes().begin() == *source.get_mimetypes().begin())
      const_cast<Crails::Renderer*>(renderer)->merge(source);
  }
}

void initialize_plugin_renderers()
{
  Crails::Cms::Injector* injector = Crails::Cms::Injector::singleton::get();
  auto& renderers = Crails::Renderers::singleton::require();
  BlogPluginHtmlRenderer plugin_html;
  BlogPluginRssRenderer  plugin_rss;
  BlogPluginJsonRenderer plugin_json;

  initialize_renderer(renderers, plugin_html);
  initialize_renderer(renderers, plugin_rss);
  initialize_renderer(renderers, plugin_json);
  Crails::Cms::Injector::register_injectable<BlogController::InjectableIndex>("blog-index", {"count"});
}
