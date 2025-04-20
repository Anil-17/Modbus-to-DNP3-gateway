#include<IDataBaseUpdater.h>

void UpdateDatabase::Full_Data_Update(modbus_t* slv,DataMap& Map,IOutstation& outstation){
    UpdateBuilder builder;
    DataTypeHandling handler;
    for(auto i:Map.A_I){
        if(i.second.second=="A_I_16"){
            uint16_t val[1];
            modbus_read_input_registers(slv,i.second.first,1,val);
            builder.Update(Analog(val[0]),i.first);
        }
        else if(i.second.second=="A_I_32"){
            int val;
            handler.modbus_read_reg_analogIP(slv,i.second.first,val);
            builder.Update(Analog(val),i.first);
        }
        else if(i.second.second=="A_F_32"){
            float val;
            handler.modbus_read_reg_analogIP(slv,i.second.first,val);
            builder.Update(Analog(val),i.first);
        }
        else if(i.second.second=="A_D_64"){
            double val;
            handler.modbus_read_reg_analogIP(slv,i.second.first,val);
            builder.Update(Analog(val),i.first);
        }
    }
    for(auto i:Map.A_O){
        if(i.second.second=="A_I_16"){
            uint16_t val[1];
            modbus_read_registers(slv,i.second.first,1,val);
            builder.Update(AnalogOutputStatus(val[0]),i.first);
        }
        else if(i.second.second=="A_I_32"){
            int val;
            handler.modbus_read_reg_analogOP(slv,i.second.first,val);
            builder.Update(AnalogOutputStatus(val),i.first);
        }
        else if(i.second.second=="A_F_32"){
            float val;
            handler.modbus_read_reg_analogOP(slv,i.second.first,val);
            builder.Update(AnalogOutputStatus(val),i.first);
        }
        else if(i.second.second=="A_D_64"){
            double val;
            handler.modbus_read_reg_analogOP(slv,i.second.first,val);
            builder.Update(AnalogOutputStatus(val),i.first);
        }
    }
    for(auto i:Map.B_I){
        u_int8_t val[1];
        bool tmp=0;
        modbus_read_input_bits(slv,i.second,1,val);
        if(val[0]!=0)tmp=1;
        builder.Update(Binary(tmp),i.first);
    }
    for(auto i:Map.B_O){
        u_int8_t val[1];
        bool tmp=0;
        modbus_read_bits(slv,i.second,1,val);
        if(val[0]!=0)tmp=1;
        builder.Update(BinaryOutputStatus(tmp),i.first);
    }
    for(auto i:Map.R_C){
        u_int16_t val[1];
        modbus_read_input_registers(slv,i.second,1,val);
        builder.Update(Counter(val[0]),i.first);
    }
    for(auto i:Map.F_C){
        bool val;
        
        builder.FreezeCounter(i.first,val);
    }
    for(auto i:Map.D_I){
        
    }
    outstation.Apply(builder.Build());
}

