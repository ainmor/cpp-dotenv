#include "dotenv.h"

#include "environ.h"
#include "Parser.h"

#include <fstream>
#include <utility>


using namespace std;
using namespace dotenv;


dotenv::Dotenv& dotenv::Dotenv::load_dotenv(const string& dotenv_path, const bool overwrite, const bool interpolate)
{
    ifstream env_file;
    env_file.open(dotenv_path);

    if (env_file.good())
    {
        Parser parser;
        parser.parse(env_file, overwrite, interpolate);
        env_file.close();
    }

    return *this;
}


const dotenv::Dotenv::value_type dotenv::Dotenv::operator[](const key_type& k) const
{
    return getenv(k).second;
}


dotenv::Dotenv& dotenv::Dotenv::instance()
{
    return _instance;
}


const string dotenv::Dotenv::env_filename = ".env";
dotenv::Dotenv dotenv::Dotenv::_instance;

dotenv::Dotenv& dotenv::env = Dotenv::instance();
