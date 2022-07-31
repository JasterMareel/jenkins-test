#define BOOST_TEST_MODULE build_and_release_tests

#include <boost/test/unit_test.hpp>
#include <string>

BOOST_AUTO_TEST_SUITE(TestSuite)

BOOST_AUTO_TEST_CASE(TestOne)
{

    BOOST_CHECK((true));
}

BOOST_AUTO_TEST_CASE(PresetTest)
{

    std::string preset_check = "Presets are";
    std::string preset_in_use = "not in use";

#ifdef PRESETS_IN_USE
    preset_in_use = preset_check;
#endif

    BOOST_CHECK((preset_check == preset_in_use));
}

BOOST_AUTO_TEST_SUITE_END()