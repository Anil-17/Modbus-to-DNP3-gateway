#include<IDataTypeHandling.h>

int DataTypeHandling::modbus_write_reg_anologOP(modbus_t*slv,int index,int32_t val){
    u_int16_t fin_val[2];
    fin_val[1] = static_cast<uint16_t>((val >> 16) & 0xFFFF);
    fin_val[0] = static_cast<uint16_t>(val & 0xFFFF);
    return modbus_write_registers(slv,index,2,fin_val);
}

int DataTypeHandling::modbus_write_reg_anologOP(modbus_t* slv,int index,float val){
    union {
        float f;
        uint32_t i;
    } converter;
    converter.f = val;
    u_int16_t fin_val[2];
    fin_val[1] = static_cast<uint16_t>((converter.i >> 16) & 0xFFFF);
    fin_val[0] = static_cast<uint16_t>(converter.i & 0xFFFF);
    return modbus_write_registers(slv,index,2,fin_val);

}

int DataTypeHandling::modbus_write_reg_anologOP(modbus_t* slv,int index,double val){
    union{
        double d;
        uint64_t i;
    } converter;
    u_int16_t fin_val[4];
    fin_val[3] = static_cast<uint16_t>((converter.i >>58) & 0xFFFF);
    fin_val[2] = static_cast<uint16_t>(converter.i >>32& 0xFFFF);
    fin_val[1] = static_cast<uint16_t>((converter.i >> 16) & 0xFFFF);
    fin_val[0] = static_cast<uint16_t>(converter.i & 0xFFFF);
    return modbus_write_registers(slv,index,4,fin_val);
}



int DataTypeHandling::modbus_read_reg_analogOP(modbus_t*slv,int index, int& val){
    uint16_t r_val[2];
    if(modbus_read_registers(slv,index,2,r_val)==-1)return 0;
    val=r_val[1];
    val<<=16;
    val|=r_val[0];
    return 1;
}

int DataTypeHandling::modbus_read_reg_analogOP(modbus_t* slv,int index,float& val){
    uint16_t r_val[2];
    if(modbus_read_registers(slv,index,2,r_val)==-1)return 0;
    int val_t;
    val_t=r_val[1];
    val_t<<=16;
    val_t|=r_val[0];
    union {
        float f;
        uint32_t i;
    } converter;
    converter.i=val_t;
    val=converter.f;
    return 1;
}

int DataTypeHandling::modbus_read_reg_analogOP(modbus_t*slv,int index,double& val){
    uint16_t r_val[4];
    if(modbus_read_registers(slv,index,4,r_val)==-1)return 0;
    u_int64_t val_t;
    val_t=r_val[3];
    val_t<<=16;
    val_t|=r_val[2];
    val_t<<=16;
    val_t|=r_val[1];
    val_t<<=16;
    val_t|=r_val[0];
    union {
        double f;
        uint64_t i;
    } converter;
    converter.i=val_t;
    val=converter.f;
    return 1;
}

int DataTypeHandling::modbus_read_reg_analogIP(modbus_t*slv,int index, int& val){
    uint16_t r_val[2];
    if(modbus_read_input_registers(slv,index,2,r_val)==-1)return 0;
    val=r_val[1];
    val<<=16;
    val|=r_val[0];
    return 1;
}

int DataTypeHandling::modbus_read_reg_analogIP(modbus_t* slv,int index,float& val){
    uint16_t r_val[2];
    if(modbus_read_input_registers(slv,index,2,r_val)==-1)return 0;
    int val_t;
    val_t=r_val[1];
    val_t<<=16;
    val_t|=r_val[0];
    union {
        float f;
        uint32_t i;
    } converter;
    converter.i=val_t;
    val=converter.f;
    return 1;
}

int DataTypeHandling::modbus_read_reg_analogIP(modbus_t*slv,int index,double& val){
     uint16_t r_val[4];
    if(modbus_read_input_registers(slv,index,4,r_val)==-1)return 0;
    u_int64_t val_t;
    val_t=r_val[3];
    val_t<<=16;
    val_t|=r_val[2];
    val_t<<=16;
    val_t|=r_val[1];
    val_t<<=16;
    val_t|=r_val[0];
    union {
        double f;
        uint64_t i;
    } converter;
    converter.i=val_t;
    val=converter.f;
    return 1;
}
