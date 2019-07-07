//
// Created by takacchi on 06/07/19.
//

#include <iostream>
#include <list>
#include <array>
#include <assert.h>
#include "capitalize_sentences.h"
#include "date_transform.h"
#include "join_string.h"
#include "palindrome.h"
#include "split_string.h"
#include "sys_converters.h"
#include "url_parts.h"
#include "validate_license.h"

void check_capitalize();
void check_date();
void check_join_str();
void check_palindrome();
void check_split_str();
void check_sys_conv();
void check_url();
void check_license();

int main()
{
    check_capitalize();
    check_date();
    check_join_str();
    check_palindrome();
    check_split_str();
    check_sys_conv();
    check_url();
    check_license();

    return 0;
}

void check_capitalize()
{
    const std::string test_string = "sOMe StRING to TEST  my  FUNCTION";
    const std::string correct = "Some String To Test  My  Function";

    std::string result_string = my_capitalize(test_string);

    assert(result_string == correct);
}

void check_date()
{
    const std::string test_string = "any date, 25.09.1999 and some text";
    const std::string correct = "any date, 1999-09-25 and some text";
    const std::string result_string = date_transform(test_string);

    assert(result_string == correct);
}

void check_join_str() {
    const std::vector<std::string> test_vector{"some", "words", "to", "test", "function"};
    const std::list<std::string> test_list{"some", "words", "to", "test", "function"};

    const std::string v_space_result = join_strings(test_vector, " ");
    const std::string v_comma_result = join_strings(test_vector, ", ");

    const std::string l_space_result = join_strings(test_list, " ");
    const std::string l_comma_result = join_strings(test_list, ", ");

    assert(v_comma_result == "some, words, to, test, function");
    assert(v_space_result == "some words to test function");

    assert(l_comma_result == "some, words, to, test, function");
    assert(l_space_result == "some words to test function");
}

void check_palindrome()
{
    const std::vector<std::string> test_strings{ "aabbcc", "avac", "qwewq" };
    const std::vector<std::string> correct{ "aa", "ava", "qwewq" };

    for (int i = 0; i < test_strings.size(); i++)
    {
        std::string result = longest_palindrome(test_strings[i]);
        assert(result == correct[i]);
    }
}

void check_split_str()
{
    using namespace std::string_literals;

    const std::vector<std::string> correct = { "This", "is", "very", "unique", "test", "string" };

    assert(correct == split("Thisxisxveryxuniquextestxstring"s, 'x'));
    assert(correct == split("This. is. very. unique. test. string"s, ". "s));

}

void check_sys_conv()
{
    // Bytes to String
    std::vector<unsigned char> test_vec { 0xAA, 0xBA, 0xF0, 0x0F };
    std::array<unsigned char, 6> test_arr {{ 9, 8, 7, 6, 1, 2 }};
    unsigned char test_tab[6] = { 0x11, 0x99, 0x22, 0x88, 0x33, 0x77 };

    assert(bytes_to_hexstr(test_vec, true) == "AABAF00F");
    assert(bytes_to_hexstr(test_vec) == "aabaf00f");
    assert(bytes_to_hexstr(test_arr, true) == "090807060102");
    assert(bytes_to_hexstr(test_arr) == "090807060102");
    assert(bytes_to_hexstr(test_tab, true) == "119922883377");
    assert(bytes_to_hexstr(test_tab) == "119922883377");

    // String to bytes
    std::vector<unsigned char> correct { 0x0A, 0xBA, 0xFF, 0xFA };

    assert(hexstr_to_bytes("ABAFFFA") == correct);
    assert(hexstr_to_bytes("aBAffFa") == correct);

}

void check_url()
{
    auto result_url = parse_url("https://www.nisshoku.jp:80/?name=taka#ceo");

    assert(result_url);
    assert(result_url->protocol == "https");
    assert(result_url->domain == "www.nisshoku.jp");
    assert(result_url->port == 80);
    assert(result_url->path.value() == "/");
    assert(result_url->query.value() == "name=taka");
    assert(result_url->fragment.value() == "ceo");
}

void check_license()
{
    // validate plate
    std::vector<std::string> correct_plates { "ZAC-ZZ 123", "CXV-EQ 9999", "AAA-AA 111" };
    std::vector<std::string> wrong_plates { "abcde123", "avc-cs 123", "qwe-as 9191" };

    for(const std::string& plate : correct_plates)
        assert(validate_plate(plate));

    // extract plates from string
    std::string plates_stirng = "ZAC-ZZ 123zxc-zx 1234 CXV-EQ 9999000..AAA-AA 111";
    assert(extract_validate_plate(plates_stirng) == correct_plates);

}