#include "MapConfig.h"

const std::string MapConfig::TREE = "TREE";
const std::string MapConfig::HASH = "HASH";
const std::string MapConfig::DB = "DB";
const std::string MapConfig::TCDB = "TCDB";
const std::string MapConfig::DBMEM = "DBMEM";
const std::string MapConfig::DBHASH = "DBHASH";
const std::string MapConfig::DB_DIR = "DB_DIR";
const std::string MapConfig::FILE = "FILE";
const std::string MapConfig::AUTO_SYNC = "AUTO_SYNC";
const std::string MapConfig::SYNC = "SYNC";
const std::string MapConfig::CACHE = "CACHE";
const std::string MapConfig::LOG = "LOG";
const std::string MapConfig::KEY_SIZE = "KEY_SIZE";
const std::string MapConfig::DATA_SIZE = "DATA_SIZE";
const std::string MapConfig::LCACHE = "LCACHE";
const std::string MapConfig::NCACHE = "NCACHE";

MapConfig::EnvInfoMap MapConfig::envs;
std::string MapConfig::dbsubdir;
