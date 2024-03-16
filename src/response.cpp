//
// Created by darko on 16.3.24.
//

#include "../include/response.hpp"

namespace DigitalLicenseManager {
    Response::Response() {}
    Response::Response(const long &status, const std::string &contents) {
        this->status = status;
        this->contents = contents;
    }
    long Response::get_status() {
        return this->status;
    }
    std::string Response::get_contents() {
        return this->contents;
    }

} // DigitalLicenseManager