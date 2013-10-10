#include "stdlib.h"
#include "stdio.h"
#include <vector>
#include <string>
#include "string.h"
#include <iostream>
#include <openrave/openrave.h>
#include <openrave/plugin.h>
#include "rrtstar/rrtstarplanner.h"
#include "rrtstar/rrtstarproblem.h"

OpenRAVE::InterfaceBasePtr CreateInterfaceValidated(OpenRAVE::InterfaceType type, const std::string& interfacename, std::istream& sinput, OpenRAVE::EnvironmentBasePtr penv)
{
    if (type == OpenRAVE::PT_ProblemInstance && interfacename == "rrtstar")
    {
        return OpenRAVE::InterfaceBasePtr(new RRTstarProblem(penv));
    }
    else if (type == OpenRAVE::PT_Planner && interfacename == "rrtstar")
    {
        return OpenRAVE::InterfaceBasePtr(new RRTstarPlanner(penv));
    }
    else
    {
        return OpenRAVE::InterfaceBasePtr();
    }
}

void GetPluginAttributesValidated(OpenRAVE::PLUGININFO& info)
{
    info.interfacenames[OpenRAVE::PT_ProblemInstance].push_back("RRTstar");
    info.interfacenames[OpenRAVE::PT_Planner].push_back("RRTstar");
}

RAVE_PLUGIN_API void DestroyPlugin()
{
    RAVELOG_INFO("Destroying plugin RRTstar\n");
}


