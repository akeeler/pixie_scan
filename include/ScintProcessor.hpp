/** \file ScintProcessor.hpp
 *
 * Processor for scintillator detectors
 */

#ifndef __SCINTPROCESSOR_HPP_
#define __SCINTPROCESSOR_HPP_

#include "EventProcessor.hpp"
#include "Trace.hpp"

class ScintProcessor : public EventProcessor 
{
public:
    ScintProcessor(); // no virtual c'tors
    virtual bool Process(RawEvent &event);
    virtual void DeclarePlots(void);
    // nice and simple raw derived class
private:
    struct ScintData {
	ScintData(string type ="");
	ScintData(ChanEvent* chan);
	bool GoodDataCheck(void) const;
	
	string detSubtype;
	double tqdc;
	double maxval;
	double maxpos;
	double phase;
	double stdDevBaseline;
	double aveBaseline;
	double highResTime;
	
	const Trace &trace;
    };

    unsigned int counter;
    
    std::map<int, struct ScintData> liquidMap;
    std::map<int, struct ScintData> betaMap;
};

#endif // __SCINTPROCSSEOR_HPP_