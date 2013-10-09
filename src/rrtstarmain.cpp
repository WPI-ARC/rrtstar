#include "stdlib.h"
#include "stdio.h"
#include <vector>
#include <string>
#include "string.h"
#include <iostream>
#include <openrave/openrave.h>
#include <openrave/plugin.h>

OpenRAVE::InterfaceBasePtr CreateInterfaceValidated(OpenRAVE::InterfaceType type, const std::string& interfacename, std::istream& sinput, OpenRAVE::EnvironmentBasePtr penv)
{
    if( type == OpenRAVE::PT_ProblemInstance && interfacename == "rrtstar" ) {
        //return OpenRAVE::InterfaceBasePtr(new RRTStarProblem(penv));
        return OpenRAVE::InterfaceBasePtr();
    }
    else if( type == OpenRAVE::PT_Planner && interfacename == "rrtstar" ) {
        //return OpenRAVE::InterfaceBasePtr(new RRTStarPlanner(penv));
        return OpenRAVE::InterfaceBasePtr();
    }
    return OpenRAVE::InterfaceBasePtr();
}

void GetPluginAttributesValidated(OpenRAVE::PLUGININFO& info)
{
    info.interfacenames[OpenRAVE::PT_ProblemInstance].push_back("RRT*");
    info.interfacenames[OpenRAVE::PT_Planner].push_back("RRT*");
}

RAVE_PLUGIN_API void DestroyPlugin()
{
    RAVELOG_INFO("Destroying plugin RRT*\n");
}


