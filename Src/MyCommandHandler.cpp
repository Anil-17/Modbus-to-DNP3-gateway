#include "MyCommandHandler.h"
#include <IDataTypeHandling.h>




void MyCommandHandler::Begin() {

}

void MyCommandHandler::End() {

}

CommandStatus MyCommandHandler::Select(const opendnp3::ControlRelayOutputBlock &command, uint16_t index){
    if(this->mapping.B_O.find(index)==this->mapping.B_O.end()){
        return CommandStatus::NOT_SUPPORTED;
    }
    else if(command.opType!=OperationType::LATCH_ON&&command.opType!=OperationType::LATCH_OFF){
        return CommandStatus::NOT_SUPPORTED;
    }
    else return CommandStatus::SUCCESS;
}

CommandStatus MyCommandHandler::Operate(const opendnp3::ControlRelayOutputBlock &command, uint16_t index, IUpdateHandler &handler, opendnp3::OperateType opType) {
    bool val;
    if(command.opType==OperationType::LATCH_ON){
        val=1;
    }
    else val=0;
    handler.Update(BinaryOutputStatus(val), index);
    modbus_write_bit(this->slv,this->mapping.B_O[index],val);
    return CommandStatus::SUCCESS;
}

CommandStatus MyCommandHandler::Select(const AnalogOutputInt16 &command, uint16_t index) {
    if(this->mapping.A_O.find(index)!=this->mapping.A_O.end()&&this->mapping.A_O[index].second=="A_I_16"){
        return CommandStatus::SUCCESS;
    }
    else {
        return CommandStatus::NOT_SUPPORTED;
    }
}

CommandStatus MyCommandHandler::Operate(const AnalogOutputInt16 &command,uint16_t index,IUpdateHandler &handler,OperateType opType) {
    handler.Update(AnalogOutputStatus(command.value),index);
    modbus_write_register(this->slv,this->mapping.A_O[index].first,command.value);
    return CommandStatus::SUCCESS;
}

CommandStatus MyCommandHandler::Select(const AnalogOutputInt32 &command, uint16_t index) {
    if(this->mapping.A_O.find(index)!=this->mapping.A_O.end()&&this->mapping.A_O[index].second=="A_I_32"){
        return CommandStatus::SUCCESS;
    }
    else {
        return CommandStatus::NOT_SUPPORTED;
    }
}

CommandStatus MyCommandHandler::Operate(const AnalogOutputInt32 &command,uint16_t index,IUpdateHandler &handler,OperateType opType) {
    DataTypeHandling data_h;
    handler.Update(AnalogOutputStatus(command.value),index);
    data_h.modbus_write_reg_anologOP(this->slv,this->mapping.A_O[index].first,command.value);
    return CommandStatus::SUCCESS;
}

CommandStatus MyCommandHandler::Select(const AnalogOutputFloat32 &command, uint16_t index) {
    if(this->mapping.A_O.find(index)!=this->mapping.A_O.end()&&this->mapping.A_O[index].second=="A_F_32"){
        return CommandStatus::SUCCESS;
    }
    else {
        return CommandStatus::NOT_SUPPORTED;
    }
}

CommandStatus MyCommandHandler::Operate(const AnalogOutputFloat32 &command,uint16_t index,IUpdateHandler &handler,OperateType opType) {
    DataTypeHandling data_h;
    handler.Update(AnalogOutputStatus(command.value),index);
    data_h.modbus_write_reg_anologOP(this->slv,this->mapping.A_O[index].first,command.value);
    return CommandStatus::SUCCESS;
}

CommandStatus MyCommandHandler::Select(const AnalogOutputDouble64 &command, uint16_t index) {
    if(this->mapping.A_O.find(index)!=this->mapping.A_O.end()&&this->mapping.A_O[index].second=="A_D_64"){
        return CommandStatus::SUCCESS;
    }
    else {
        return CommandStatus::NOT_SUPPORTED;
    }
}

CommandStatus MyCommandHandler::Operate(const AnalogOutputDouble64 &command,uint16_t index,IUpdateHandler &handler,OperateType opType) {
    DataTypeHandling data_h;
    handler.Update(AnalogOutputStatus(command.value),index);
    data_h.modbus_write_reg_anologOP(this->slv,this->mapping.A_O[index].first,command.value);
    return CommandStatus::SUCCESS;
}
