//
// Created by Darko Gjorgjijoski on 17.3.24.
//

#ifndef DLM_CPP_PARAMETER_H
#define DLM_CPP_PARAMETER_H

struct Parameter {
    Parameter(std::string p_key, std::string p_value) : key{std::move(p_key)}, value{std::move(p_value)} {}

    std::string key;
    std::string value;
};

#endif //DLM_CPP_PARAMETER_H
