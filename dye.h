#pragma once

class Dye
{
    void dyeMonitor();
    void dyeProcedure(int dye_time); // in minutes
    void dyeCleanUp();
    bool prepBath();
    bool bath_ready;
};

extern Dye dye;