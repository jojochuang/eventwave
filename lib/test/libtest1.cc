#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE libmace
#include <boost/test/unit_test.hpp>

#include "mvector.h"
#include "MaceKey.h"
#include "params.h"

BOOST_AUTO_TEST_CASE(TestVector)
{
  mace::vector<int> v;
  v.push_back(1);
  v.push_back(2);
  BOOST_REQUIRE_EQUAL(v.size(), (size_t)2);

  std::string s = v.serializeStr();
  std::string t = s;

  mace::vector<int> w;
  w.deserializeStr(t);

  BOOST_REQUIRE_EQUAL(v.toString(), w.toString());
  BOOST_REQUIRE(v == w);
}

BOOST_AUTO_TEST_CASE(MaceKeyTest)
{
  Log::disableDefaultWarning();
  params::set("MACE_ADDRESS_ALLOW_LOOPBACK", "1");
  mace::MaceKey j = mace::MaceKey(mace::ipv4, "23.24.25.26");
  BOOST_REQUIRE(! j.isNullAddress());

  BOOST_TEST_CHECKPOINT("The following tests if DNS is working in Mace");
  mace::MaceKey k = mace::MaceKey(mace::ipv4, "www.google.com");
  BOOST_WARN(! k.isNullAddress());

  BOOST_TEST_CHECKPOINT("Now testing serialization of MaceKey");
  mace::MaceKey l = mace::MaceKey(mace::ipv4, "127.0.0.1:1024");
  std::string l_s = l.serializeStr();
  char expected_s[] = {1 /* IPV4 */, 127, 0, 0, 1, 4, 0, 255, 255, 255, 255, 0, 0};
  for (size_t i = 0; i < sizeof(expected_s); i++) {
    BOOST_REQUIRE_EQUAL(l_s[i], expected_s[i]);
  }
}
