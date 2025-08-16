#include <openssl/evp.h>
#include <openssl/sha.h>
#include <string>
#include <sstream>
#include <iomanip>

std::string sha256(const std::string &str)
{
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if (!ctx)
        return "";

    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int length = 0;

    if (EVP_DigestInit_ex(ctx, EVP_sha256(), nullptr) != 1 ||
        EVP_DigestUpdate(ctx, str.c_str(), str.size()) != 1 ||
        EVP_DigestFinal_ex(ctx, hash, &length) != 1)
    {
        EVP_MD_CTX_free(ctx);
        return "";
    }

    EVP_MD_CTX_free(ctx);

    std::stringstream ss;
    for (unsigned int i = 0; i < length; i++)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }

    return ss.str();
}
