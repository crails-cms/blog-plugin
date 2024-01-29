#include <string>

void initialize_plugin_routes();
void initialize_plugin_renderers();
void install_plugin_database();
void uninstall_plugin_database();
/*
extern unsigned char blog_plugin_application_js[];
extern unsigned int  blog_plugin_application_js_len;
extern unsigned char blog_plugin_admin_js[];
extern unsigned int  blog_plugin_admin_js_len;
*/
extern "C"
{
  void initialize()
  {
    initialize_plugin_routes();
    initialize_plugin_renderers();
  }

  void install()
  {
    install_plugin_database();
  }

  void uninstall()
  {
    uninstall_plugin_database();
  }
/*
  std::string_view plugin_javascript()
  {
    return std::string_view(
      reinterpret_cast<const char*>(blog_plugin_application_js),
      blog_plugin_application_js_len
    );
  }

  std::string_view plugin_admin_javascript()
  {
    return std::string_view(
      reinterpret_cast<const char*>(blog_plugin_admin_js),
      blog_plugin_admin_js_len
    );
  }
*/
}
