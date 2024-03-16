#ifndef DLM_API_CLIENT_H
#define DLM_API_CLIENT_H

#include "connection.hpp"
#include "request.hpp"
#include "response.hpp"

namespace DigitalLicenseManager {
    Connection create_connection(const std::string &base_url, const std::string &version, const std::string &consumer_key, const std::string &consumer_secret);
    Response licenses_query(Connection &connection);
    Response licenses_get(Connection &connection, const std::string &key);
    Response licenses_activate(Connection &connection, const std::string &key, const std::string &label);
    Response licenses_deactivate(Connection &connection, const std::string &token);
    Response licenses_validate(Connection &connection, const std::string &token);
}

#endif //DLM_API_CLIENT_H
