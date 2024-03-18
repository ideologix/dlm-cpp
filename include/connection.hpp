//
// Created by darko on 16.3.24.
// Copyright (C) 2024 Darko Gjorgjijoski.
// All rights reserved.
//

#ifndef DLM_CPP_CONNECTION_HPP
#define DLM_CPP_CONNECTION_HPP

#include <string>

namespace DigitalLicenseManager {

    class Connection {

    public:
        std::string base_url;
        std::string version;
        std::string consumer_key;
        std::string consumer_secret;

        Connection();
        Connection(const std::string &base_url, const std::string &version, const std::string &consumer_key, const std::string &consumer_secret);
    };

} // DigitalLicenseManager

#endif //DLM_CPP_CONNECTION_HPP
