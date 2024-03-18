//
// Created by darko on 16.3.24.
// Copyright (C) 2024 Darko Gjorgjijoski.
// All rights reserved.
//

#include "../include/response.hpp"

namespace DigitalLicenseManager {
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