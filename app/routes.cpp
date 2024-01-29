#include <crails/router.hpp>
#include <crails/cms/routes.hpp>
#include <crails/cms/views/admin_menu.hpp>
#include "app/controllers/blog.hpp"
#include "app/controllers/admin/blog.hpp"

void initialize_plugin_routes()
{
  auto& router = Crails::Router::singleton::require();
  auto& cms_routes = Crails::Cms::Routes::singleton::require();
  auto& admin_menu = Crails::Cms::AdminMenu::singleton::require();

  // insert plugin routes here
  router.scope(BlogController::scope, [&]()
  {
    cms_routes.register_blog_routes<BlogController>(router);
  });

  router.scope(AdminApplicationController::scope, [&]()
  {
    router.scope(AdminBlogController::scope, [&]()
    {
      admin_menu.add({4, "blog", router.get_current_scope()});
      cms_routes.register_blog_admin_routes<BlogController, AdminBlogController>(router);
    });
  });
}
