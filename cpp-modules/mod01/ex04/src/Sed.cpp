#include "Sed.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

Sed::Sed(const std::string &filepath, const std::string &s1, const std::string &s2) {
    filepath_ = filepath;
    s1_ = s1;
    s2_ = s2;
}

static bool hasErrorOccured(const std::string &path) {
    std::fstream ifs(path);

    return ifs.rdstate() != 0;
}

static void write(const std::string &path, const std::string &content) {
    std::ofstream ofs(path);
    if (ofs) {
        ofs << content;
    }
    if (ofs.bad()) {
        std::cerr << "Error: Failed to write to file" << std::endl;
        std::exit(1);
    }
}

void Sed::readFileContent(void) {
    if (hasErrorOccured(filepath_)) {
        std::cerr << "Error: Failed to open file" << std::endl;
        std::exit(1);
    }
    std::ifstream ifs(filepath_);
    std::stringstream ss;
    ss << ifs.rdbuf();
    content_ = ss.str();
}

void Sed::replace(void) {
    if (s1_.empty()) {
        std::cerr << "Error: first string may not be empty" << std::endl;
        std::exit(1);
    }

    readFileContent();

    size_t pos, idx = 0;
    while ((pos = content_.find(s1_, idx)) != std::string::npos) {
        content_.erase(pos, s1_.size());
        content_.insert(pos, s2_);
        idx = pos + s2_.size();
    }

    write(filepath_ + ".replace", content_);
}
