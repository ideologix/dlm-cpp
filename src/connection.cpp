//
// Created by darko on 16.3.24.
//

#include "../include/connection.hpp"

namespace DigitalLicenseManager {

    Connection::Connection() {}
    Connection::Connection(const std::string &base_url, const std::string &version, const std::string &consumer_key,
                           const std::string &consumer_secret) {
        this->version = version;
        this->base_url = base_url;
        this->consumer_key = consumer_key;
        this->consumer_secret = consumer_secret;
    }

} // DigitalLicenseManager