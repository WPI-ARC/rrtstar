#include "stdlib.h"
#include "stdio.h"
#include <string>
#include "string.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <openrave/openrave.h>

#ifndef RRTSTAR_PROBLEM_H
#define RRTSTAR_PROBLEM_H

class RRTstarProblem : public OpenRAVE::ProblemInstance
{
private:

    int RunRRTstar(std::ostream& sout, std::istream& sinput);

    OpenRAVE::RobotBasePtr robot;
    std::string plannerName_;
    std::string robotName_;
    OpenRAVE::PlannerBasePtr plannerPtr_;
    OpenRAVE::IkSolverBasePtr ikSolverPtr_;

public:

    RRTstarProblem(OpenRAVE::EnvironmentBasePtr penv);

    virtual ~RRTstarProblem();

    virtual void Destroy();

    virtual int main(const std::string& args);

    virtual void SetActiveRobots(const std::vector<OpenRAVE::RobotBasePtr>& robots);

    virtual bool SimulationStep(OpenRAVE::dReal elapsedTime);

    virtual bool SendCommand(std::ostream& sout, std::istream& sinput);

    virtual void Query(const char* query, std::string& response);
};


#endif // RRTSTAR_PROBLEM_H
