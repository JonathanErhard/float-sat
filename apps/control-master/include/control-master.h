//generated using CreateApp.sh

#include <control-master-generated/control-master.h> 

class ControlMaster: public generated::ControlMaster{

	public:

	void initialize() override;

	//Thread methods
	void initServoThread() override;
	void runServoThread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	

};
