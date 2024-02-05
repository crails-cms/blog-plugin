#pragma once
#include <crails/cms/controllers/blog.hpp>
#include "app/controllers/application.hpp"
#include "app/models/blog_post_traits.hpp"
#include "lib/odb/application-odb.hxx"

class BlogController : public Crails::Cms::BlogController<BlogPostTraits, ApplicationController>
{
  typedef Crails::Cms::BlogController<BlogPostTraits, ApplicationController> Super;
  typedef BlogPost Post;
public:
  static constexpr const char* scope = "blog";

  BlogController(Crails::Context& context) : Super(context)
  {
    vars["local_route"] = scope;
  }

  void show()
  {
    using namespace std;
    shared_ptr<Post> model, previous_model, next_model;

    if (Super::params["slug"].exists())
      Super::database.find_one(model, odb::query<Post>::slug == Super::params["slug"].template as<string>());
    else if (Super::params["id"].exists())
      Super::database.find_one(model, Super::params["id"].template as<Crails::Odb::id_type>());
    if (model)
    {
      Super::database.find_one(previous_model, Post::template make_previous_query<odb::query<Post>>(*model));
      Super::database.find_one(next_model, Post::template make_next_query<odb::query<Post>>(*model));
      add_model_to_vars("previous_model", previous_model);
      add_model_to_vars("next_model", next_model);
      Super::prepare_open_graph(*model);
      Super::render(get_view_scope() + "/show", {
        {"model", reinterpret_cast<const Crails::Cms::BlogPost*>(model.get())}
      });
    }
    else
      Super::respond_with(Crails::HttpStatus::not_found);
  }
};
