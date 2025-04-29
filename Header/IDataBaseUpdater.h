#include<modbus/modbus.h>
#include<IDataBaseHandler.h>
#include <opendnp3/outstation/UpdateBuilder.h>
#include <opendnp3/outstation/IOutstation.h>
#include <IDataTypeHandling.h>

using namespace opendnp3;


class UpdateDatabase{
    public:
    void Full_Data_Update(modbus_t*,DataMap&,IOutstation&);

};
