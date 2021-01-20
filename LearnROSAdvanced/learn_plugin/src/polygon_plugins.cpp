//
// Created by xu on 2021/1/11.
//

#include <learn_plugin/polygon_base.h>
#include "../include/learn_plugin/polygon_plugins.h"
// use macros of plyginlib to register
#include <pluginlib/class_list_macros.h>

PLUGINLIB_EXPORT_CLASS(polygon_plugins::Triangle, polygon_base::RegularPolygon)
PLUGINLIB_EXPORT_CLASS(polygon_plugins::Square, polygon_base::RegularPolygon)


