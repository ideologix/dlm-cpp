//
// Created by darko on 16.3.24.
//
#include "../include/request.hpp"
#include <cpr/cpr.h>

namespace DigitalLicenseManager {

    /**
     * The constructor
     * @param Connection connection
     */
    Request::Request(Connection connection) {
        this->connection = connection;
    }

    /**
     * The GET request
     * @param std::string path
     * @param std::initializer_list<cpr::Parameter> data
     * @return Response
     */
    Response Request::get(const std::string &path, const std::initializer_list<cpr::Parameter> &data) {

        cpr::Response r = cpr::Get(cpr::Url{endpoint(path)},
                                   cpr::Authentication{this->connection.consumer_key, this->connection.consumer_secret, cpr::AuthMode::BASIC},
                                   cpr::Parameters{data});
        Response response = Response(r.status_code, r.text);

        return response;
    }

    /**
     * The POST request
     * @param std::string path
     * @param std::initializer_list<cpr::Parameter> data
     * @return Response
     */
    Response Request::post(const std::string &path, const std::initializer_list<cpr::Parameter> &data) {

        cpr::Response r = cpr::Get(cpr::Url{endpoint(path)},
                                   cpr::Authentication{this->connection.consumer_key, this->connection.consumer_secret, cpr::AuthMode::BASIC},
                                   cpr::Parameters{data});
        Response response = Response(r.status_code, r.text);
        return response;
    }

    /**
     * Create endpoint based on base url and path
     * @param std::string path
     * @return std::string
     */
    std::string Request::endpoint(const std::string &path) {

        std::string path_f = '/' == path[0] ? path.substr(1) : path;
        std::string back_url_f  = '/' == this->connection.base_url.back() ? this->connection.base_url : this->connection.base_url + '/';

        return back_url_f + "wp-json/dlm/" + this->connection.version + "/" + path_f;
    }

} // DigitalLicenseManager