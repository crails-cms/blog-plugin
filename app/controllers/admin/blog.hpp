#pragma once
#include <crails/cms/controllers/admin/blog.hpp>
#include "app/controllers/admin/application.hpp"
#include "app/models/blog_post_traits.hpp"
#include "lib/odb/application-odb.hxx"

class AdminBlogController : public Crails::Cms::AdminBlogController<BlogPostTraits, AdminApplicationController>
{
  typedef Crails::Cms::AdminBlogController<BlogPostTraits, AdminApplicationController> Super;
public:
  static constexpr const char* scope = "blog";

  typedef typename BlogPostTraits::Model      Model;
  typedef typename BlogPostTraits::TagModel   Tag;
  typedef typename BlogPostTraits::IndexModel IndexModel;

  AdminBlogController(Crails::Context& context) : Super(context)
  {
    vars["local_route"] = std::string(AdminApplicationController::scope) + '/' + scope;
  }
};
