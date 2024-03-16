//
// Created by darko on 16.3.24.
//  Copyright (C) 2024 Darko Gjorgjijoski.
// All rights reserved.
//

#ifndef DLM_REQUEST_H
#define DLM_REQUEST_H

#include "response.hpp"
#include "connection.hpp"
#include <iostream>
#include <list>
#include <cpr/curl_container.h>

namespace DigitalLicenseManager {

    class Request {

    private:
        Connection connection;

    public:
        explicit Request(Connection connection);
        Response post(const std::string &path, const std::initializer_list<cpr::Parameter> &data);
        Response get(const std::string &path, const std::initializer_list<cpr::Parameter> &data);
        std::string endpoint(const std::string &path);
    };

} // DigitalLicenseManager

#endif //DLM_REQUEST_H
