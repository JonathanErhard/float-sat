//generated using CreateApp.sh

#include <reader-generated/reader.h> 

class Reader: public generated::Reader{

	public:

	void initialize() override;

	//Thread methods
	void initReadthreat() override;
	void runReadthreat() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
};
