//
// Created by darko on 16.3.24.
//

#ifndef DLM_API_CONNECTION_HPP
#define DLM_API_CONNECTION_HPP

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

#endif //DLM_API_CONNECTION_HPP
