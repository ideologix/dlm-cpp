//
// Created by darko on 16.3.24.
// Copyright (C) 2024 Darko Gjorgjijoski.
// All rights reserved.
//

#ifndef DLM_RESPONSE_H
#define DLM_RESPONSE_H

#include <iostream>

namespace DigitalLicenseManager {

    class Response {

    protected:
        long status = 0;
        std::string contents;

    public:
        Response() = default;
        Response(const long &status, const std::string &contents);
        long get_status();
        std::string get_contents();
    };

} // DigitalLicenseManager

#endif //DLM_RESPONSE_H
