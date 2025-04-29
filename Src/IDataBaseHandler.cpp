#include<IDataBaseHandler.h>

DatabaseConfig DataMap::ReadFile(string file_addr){
    ifstream fout;
    fout.open(file_addr);
    string cn;
    getline(fout,cn);
    uint16_t cnt=stoi(cn);
    DatabaseConfig database(cnt);
    while(getline(fout,cn)){
        LineHandle(cn,database);
    }
    fout.close();
    return database;
}
void DataMap::LineHandle(string line, DatabaseConfig& database){
    vector<string> all_c=LineRead(line);
    if(all_c[0]=="A_I"){
        this->A_I[stoi(all_c[1])].first=stoi(all_c[2]);
        this->A_I[stoi(all_c[1])].second=all_c[3];
        database.analog_input[stoi(all_c[1])].clazz=PointClassSpec::from_type(stoi(all_c[4]));
        if(all_c[3]=="A_F_32"){
            database.analog_input[stoi(all_c[1])].evariation= EventAnalogVariation::Group32Var7;
            database.analog_input[stoi(all_c[1])].svariation= StaticAnalogVariation::Group30Var5;
        }
    }
    else if(all_c[0]=="A_O"){
        this->A_O[stoi(all_c[1])].first=stoi(all_c[2]);
        this->A_O[stoi(all_c[1])].second=all_c[3];
        database.analog_output_status[stoi(all_c[1])].clazz=PointClassSpec::from_type(stoi(all_c[4]));
        if(all_c[3]=="A_F_32"){
            database.analog_output_status[stoi(all_c[1])].evariation= EventAnalogOutputStatusVariation::Group42Var7;
            database.analog_output_status[stoi(all_c[1])].svariation= StaticAnalogOutputStatusVariation::Group40Var3;
        }
    }
    else if(all_c[0]=="B_O"){
        this->B_O[stoi(all_c[1])]=stoi(all_c[2]);
        database.binary_output_status[stoi(all_c[1])].clazz=PointClassSpec::from_type(stoi(all_c[3]));
    }
    else if(all_c[0]=="B_I"){
        this->B_I[stoi(all_c[1])]=stoi(all_c[2]);
        database.binary_input[stoi(all_c[1])].clazz=PointClassSpec::from_type(stoi(all_c[3]));
    }
    else if(all_c[0]=="R_C"){
        this->R_C[stoi(all_c[1])]=stoi(all_c[2]);
        database.counter[stoi(all_c[1])].clazz=PointClassSpec::from_type(stoi(all_c[3]));
    }
    else if(all_c[0]=="F_C"){
        this->R_C[stoi(all_c[1])]=stoi(all_c[2]);
        database.frozen_counter[stoi(all_c[1])].clazz=PointClassSpec::from_type(stoi(all_c[3]));
    }
    else if(all_c[0]=="D_I"){
        this->R_C[stoi(all_c[1])]=stoi(all_c[2]);
        database.double_binary[stoi(all_c[1])].clazz=PointClassSpec::from_type(stoi(all_c[3]));
    }
    return;
}

vector<string> DataMap::LineRead(string sentence){
    vector<std::string> words;
    istringstream iss(sentence);
    string word;

    while (iss >> word) {
        words.push_back(word);
    }

    return words;
}
