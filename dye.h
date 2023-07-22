#pragma once

class Dye
{
public:
    void dyeMonitor();
    void dyeProcedure(int dye_time); // in minutes
    void dyeCleanUp(int cool_time);
    bool prepBath();
    bool bath_ready;
};

extern Dye dye;