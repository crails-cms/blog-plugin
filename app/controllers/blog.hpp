#pragma once
#include <crails/cms/controllers/blog.hpp>
#include "app/controllers/application.hpp"
#include "app/models/blog_post_traits.hpp"
#include "lib/odb/application-odb.hxx"

class BlogController : public Crails::Cms::BlogController<BlogPostTraits, ApplicationController>
{
  typedef Crails::Cms::BlogController<BlogPostTraits, ApplicationController> Super;
public:
  static constexpr const char* scope = "blog";

  BlogController(Crails::Context& context) : Super(context)
  {
    vars["local_route"] = scope;
  }
};
