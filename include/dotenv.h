#pragma once


#include <string>


namespace dotenv
{
    class Dotenv
    {
    public:

        using   key_type = std::string;
        using value_type = std::string;

    public:

        Dotenv& load_dotenv(const std::string& dotenv_path = env_filename,
                            const bool overwrite = false,
                            const bool interpolate = true);

        const value_type operator[](const key_type& k) const;

    public:

        virtual ~Dotenv() = default;
        Dotenv(const Dotenv&) = delete;
        void operator=(const Dotenv&) = delete;

        static Dotenv& instance();
    
    private:

    Dotenv() = default;

    private:

        static const std::string env_filename;
        static Dotenv _instance;

    };


    extern Dotenv& env;
}
