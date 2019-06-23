//
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
//#include "Analyze.h"
//
//Analyze A;
//
//TEST_CASE("Check Outputs") {
//	REQUIRE(A.test_infix2postfix("2+2")==("4"));
//	REQUIRE(A.test_infix2postfix("2*2") == ("4"));
//	REQUIRE(A.test_infix2postfix("2^2") == ("4"));
//	REQUIRE(A.test_infix2postfix("2/2") == ("1"));
//	REQUIRE(A.test_infix2postfix("2%2") == ("0"));
//	REQUIRE(A.test_infix2postfix("(1+2)+(3/3)-(5%5)") == ("4"));
//	REQUIRE(A.test_infix2postfix("(1*2)+(3^3)-(5%5)") == ("29"));
//}
//TEST_CASE("Check expression") {
//	REQUIRE(A.isBadWritten("+2") == true);
//	REQUIRE(A.isBadWritten("2&") == true);
//	REQUIRE(A.isBadWritten("[2") == true);
//	REQUIRE(A.isBadWritten("2++")==true);
//	REQUIRE(A.isBadWritten("(2+") == true);
//	REQUIRE(A.isBadWritten("2+") == true);
//	REQUIRE(A.isBadWritten("2+2") == false);
//}
//
