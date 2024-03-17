#include "../include/client.hpp"

#include <string>

namespace DigitalLicenseManager {

    Connection create_connection(const std::string &base_url, const std::string &version, const std::string &consumer_key, const std::string &consumer_secret) {
        Connection connection = Connection(base_url, version, consumer_key, consumer_secret);
        return connection;
    }
    Response licenses_create(Connection &connection, const std::initializer_list<Parameter> &data) {
        Request request = Request(connection);
        return request.post("licenses", data);
    }
    Response licenses_update(Connection &connection, const std::string &key, const std::initializer_list<Parameter> &data) {
        Request request = Request(connection);
        return request.post("licenses/"+key, data);
    }
    Response licenses_query(Connection &connection) {
        Request request = Request(connection);
        return request.get("licenses", {});
    };
    Response licenses_get(Connection &connection, const std::string &key) {
        Request request = Request(connection);
        return request.get("licenses/"+key, {});
    };
    Response licenses_activate(Connection &connection, const std::string &key, const std::string &label) {
        Request request = Request(connection);
        return request.get("licenses/activate/"+key, {{"label", label}});
    };
    Response licenses_deactivate(Connection &connection, const std::string &token) {
        Request request = Request(connection);
        return request.get("licenses/deactivate/"+token, {});
    };
    Response licenses_validate(Connection &connection, const std::string &token) {
        Request request = Request(connection);
        return request.get("licenses/validate/"+token, {});
    };
}