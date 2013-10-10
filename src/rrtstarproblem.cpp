#include "stdlib.h"
#include "stdio.h"
#include <string>
#include "string.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <openrave/openrave.h>
#include "rrtstar/rrtstarplanner.h"
#include "rrtstar/rrtstarproblem.h"

RRTstarProblem::RRTstarProblem(OpenRAVE::EnvironmentBasePtr penv) : OpenRAVE::ProblemInstance(penv)
{
    OpenRAVE::RegisterCommand("RunRRTstar", boost::bind(&RRTstarProblem::RunRRTstar, this, _1, _2), "Run the RRTstar planner");
}

int RRTstarProblem::main(const std::string& cmd)
{
    RAVELOG_INFO("Starting RRTstar Problem\n");
    return 0;
}

int RRTstarProblem::RunRRTstar(ostream& sout, istream& sinput)
{
    RAVELOG_INFO("Planning with RRTstar\n");
    return 0;
}

void RRTstarProblem::Destroy()
{
    ;
}


RRTstarProblem::~RRTstarProblem()
{
    RRTstarProblem::Destroy();
}
