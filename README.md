Feature Server
==============

Feature server for Drupal 7 is built using several "Features" from contributed modules including Services, Panels/Page Manager, Views and others. It is built this way to showcase the power of Features and what is possible by simply exporting configuration from a Drupal site.

We believe Feature Server is an import part of the Drupal ecosystem as it allows configured components to be shared.

Overview
--------

All the modules within Feature Server are themselves Features. This is done as both a demonstration of what's possible with Features as well as to leverage all the amazing APIs already available in the Drupal community.

### Feature Server
Feature Server at the core provides entity types and bundles for managing Drupal compatible projects. You can creating Project entities with bundles for a module, theme or distribution. You can then attach a Release entity to any project. Required data such as core compatibility, release notes, project machine names, etc. are all entity properties which make them light/fast to load.

This also means however you can extend the entities using the Field UI to add additional data as needed (i.e. location, taxonomy)

Some key components/dependencies in Feature Service include:

- [ECK](http://drupal.org/project/eck Entity Construction Kit)
- [Ctools](http://drupal.org/project/ctools)
- [Entity Reference](http://drupal.org/project/entityreference)
- [Filehash](http://drupal.org/project/filehash)
- [Features](http://drupal.org/project/features)

### Feature Server Services
Feature Server Services uses the Services API to expose project and release data. An extension is included to create a Drupal Update module compatible project feed so you can expose your Features to Drupal sites. But this also allows you to use any Services compatible access control, data methods or servers for exposing this data. 

### Feature Server UI
This is a basic UI for creating project pages, releases and similar functionality that you would find on Drupal.org. It is not designed to be a complete solution for exposing all options available within Feature Server. Simply a guide to what is possible to build. It uses Page Manager and Panels to define the project page layouts as well as some node types for storing related data on projects (i.e. extended description, open issues)

Consider is an example of what is possible to build against the underlying Feature Server APIs

- [Inline Entity Form](http://drupal.org/project/inline_entity_form)
- [Panels](http://drupal.org/project/panels)
