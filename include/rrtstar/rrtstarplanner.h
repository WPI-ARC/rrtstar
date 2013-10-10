#include "stdlib.h"
#include "stdio.h"
#include <string>
#include "string.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <openrave/openrave.h>

#ifndef RRTSTAR_PLANNER_H
#define RRTSTAR_PLANNER_H


class RRTstarPlanner : public OpenRAVE::PlannerBase
{
public:

    RRTstarPlanner(OpenRAVE::EnvironmentBasePtr penv);

    ~RRTstarPlanner() {}

    bool InitPlan(OpenRAVE::RobotBasePtr robot, OpenRAVE::PlannerBase::PlannerParametersConstPtr params);

    OpenRAVE::PlannerStatus PlanPath(OpenRAVE::TrajectoryBasePtr traj);

    OpenRAVE::PlannerBase::PlannerParametersConstPtr GetParameters() const;

};

#endif // RRTSTAR_PLANNER_H
