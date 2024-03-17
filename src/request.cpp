//
// Created by darko on 16.3.24.
//
#include "../include/request.hpp"
#include "curl/curl.h"

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
     * @param std::initializer_list<Parameter> data
     * @return Response
     */
    Response Request::get(const std::string &path, const std::initializer_list<Parameter> &data) {

        curl_global_init(CURL_GLOBAL_ALL);

        CURL* handle = curl_easy_init();
        std::string read_buffer;
        std::string query_string = "";
        long http_code;

        for (auto& e : data) {
            char *value = curl_escape(e.value.c_str(), e.value.length());
            if(value) {
                query_string += e.key;
                query_string += "=";
                query_string += std::string (value);
                curl_free(value);
            }
        }

        std::string url = this->endpoint(path);
        if(!query_string.empty()) {
            url += (url.back() == '?' ? '&' + query_string : '?' + query_string);
        }

        std::cout << "Request url: ";
        std::cout << url << std::endl;

        curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
        curl_easy_setopt(handle, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
        curl_easy_setopt(handle, CURLOPT_USERNAME, this->connection.consumer_key.c_str());
        curl_easy_setopt(handle, CURLOPT_PASSWORD, this->connection.consumer_secret.c_str());
        //curl_easy_setopt(handle, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(handle, CURLOPT_WRITEDATA, &read_buffer);
        curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &http_code);

        curl_easy_perform(handle);
        curl_easy_cleanup(handle);
        curl_global_cleanup();

        Response response = Response(http_code, read_buffer);

        return response;
    }

    /**
     * The POST request
     * @param std::string path
     * @param std::initializer_list<Parameter> data
     * @return Response
     */
    Response Request::post(const std::string &path, const std::initializer_list<Parameter> &data) {


        Response response = Response(1, "");
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

    /**
     * Write callback
     * @param contents
     * @param size
     * @param nmemb
     * @param userp
     * @return
     */
    size_t Request::WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

} // DigitalLicenseManager